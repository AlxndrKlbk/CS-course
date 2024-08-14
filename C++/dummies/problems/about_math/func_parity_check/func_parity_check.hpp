#pragma once

#include <optional>
#include <fstream>
#include <vector>
#include <utility>
#include <string>
#include <iostream>
#include <type_traits>
#include <algorithm>
#include <limits>

#include <math.h>

#include "calc_integral.hpp"

namespace {

/**
 * @brief parallel - check that lines not equal
 * @param a1
 * @param a2
 * @param b1
 * @param b2
 * @return
 */
bool parallel(double a1, double a2, double b1, double b2);

/**
 * @brief intersect - calculate line intersection between two line of kind ax + by + c = 0
 * @param a1
 * @param a2
 * @param b1
 * @param b2
 * @param c1
 * @param c2
 * @param x
 * @param y
 */
void intersect(double a1, double a2, double b1, double b2, double c1, double c2, double& x, double& y);

}

template<typename T>
std::optional<std::vector<std::pair<T, T>>> load_from_file(const char* const filePath)
{
    std::ifstream file;
    file.open(filePath, std::ios::in);

    if (!file.is_open()) {
        std::cerr << "Error opening the file: " << filePath << std::endl;
        return std::nullopt;
    }

    std::string line;
    const std::string delimiter = " ";
    int readedVal = 0;

    // read size of array
    getline(file, line);
    auto pos_end = line.find(delimiter, 0);
    uint arrSize = atoi(line.substr(0, pos_end).c_str());
    std::vector<std::pair<T, T>> buff(arrSize);

    // fill array
    int counter = 0;
    while(getline(file, line)) {
        size_t pos_start = 0, pos_end, delim_len = delimiter.length();
        while ((pos_end = line.find(delimiter, pos_start)) != std::string::npos) {
            auto point  = buff[counter];

            if constexpr (std::is_same<T, int>::value) {
                point.first = atoi(line.substr(pos_start, pos_end - pos_start).c_str());    // X coord

                pos_start = pos_end + delim_len;
                pos_end = line.find(delimiter, pos_start);
                point.second = atol(line.substr(pos_start, pos_end - pos_start).c_str());   // Y coord
            } else {

                point.first = atol(line.substr(pos_start, pos_end - pos_start).c_str());    // X coord

                pos_start = pos_end + delim_len;
                pos_end = line.find(delimiter, pos_start);
                point.second = atol(line.substr(pos_start, pos_end - pos_start).c_str());   // Y coord
            }


            buff[counter++] = std::move(point);
        }
    }

    return buff;
}


/**
 * @brief move_relatively_x_axis - move up/down relatively X axis
 * @param points - massive of points to move
 */
template<typename T>
void move_relatively_x_axis(std::vector<std::pair<T, T>>& points)
{
    auto minElem = std::min_element(points.cbegin(),
                                    points.cend(),
                                    [](std::pair<T, T> const& x,
                                       std::pair<T, T> const& y) {
                                        return x.second < y.second;
                                    });

    auto moveTerm = minElem->second;

    if (moveTerm == 0) {
        return;
    }

    for (auto&& val: points) {
        val.second -= moveTerm;
    }
}

/**
 * @brief move_relatively_y_axis - move left/right relatively Y axis
 * @param points - massive of points to move
 */
template <typename T>
void move_relatively_y_axis(std::vector<std::pair<T, T>>& points)
{
    const auto [minElem, maxElem] = std::minmax_element(points.cbegin(),
                                                points.cend(),
                                                [](std::pair<T, T> const& x,
                                                   std::pair<T, T> const& y) {
                                                    return x.first < y.first;
                                                });

    auto half_distance = (maxElem->first - minElem->first) / 2;
    auto moveTerm = maxElem->first - half_distance;

    if (moveTerm == 0) {
        return;
    }

    for (auto&& val: points) {
        val.first -= moveTerm;
    }
}

/**
 * @brief get_mid - get mid point for given function
 * @param points - vector with pair of points
 * @return mid point if exist
 */
template<typename T>
std::optional<typename std::vector<std::pair<T, T>>::iterator> get_mid(std::vector<std::pair<T, T>>& points) {
    auto left = points.cbegin();
    auto right = left;

    right++;
    while(true) {
        if (left->first < 0 && right->first > 0) {
            break;
        }

        left = right;
        right++;
    }

    double a1, a2, b1, b2, c1, c2;
    double x, y;
    // line equation ax + by + c = 0
    a1 = left->first- right->second;
    b1 = right->first - left->first;
    c1 = left->first * right->second - right->first * left->second;

    // Y axis
    a2 = std::numeric_limits<float>::max() - std::numeric_limits<float>::min();
    b2 = 0;
    c2 = 0;

    if (parallel(a1, a2, b1, b2)) {
        return std::nullopt;
    }

    intersect(a1, a2, b1, b2, c1, c2, x, y);

    //ToDo : lag on performane because overflow capacity of vector
    auto inserted = points.insert(right, {x, y});
    return {inserted};
}


/**
 * @brief check_func_parity - method to check functions parity
 * @param points - vector with pair of points
 * @return true if function is parity
 */
template <typename T>
bool check_func_parity(std::vector<std::pair<T, T>>&& points)
{
    std::sort(points.begin(),
              points.end(),
              [](std::pair<T, T> const& x,
                 std::pair<T, T> const& y) {
                  return x.first < y.first;
              });

    move_relatively_x_axis(points);
    move_relatively_y_axis(points);

    auto mid = get_mid(points);
    if (!mid) {
        return false;
    }

    //ToDo too much memory usage, duplicating vector for re-use Leibniz function
    // need to implement Leibniz for integrating between two iterators
    std::vector<std::pair<T, T>> left(points.begin(), mid.value());
    std::vector<std::pair<T, T>> right(mid.value(), points.end());

    auto leftSquare  = integralLeibniz(left);
    auto rightSquare = integralLeibniz(right);

    auto tmp = fabs(leftSquare - rightSquare);
    if ((fabs(leftSquare - rightSquare) / rightSquare * 100) < 0.0001) {    // accuracy 0.0001%, is it?
        return true;
    }

    return false;
}

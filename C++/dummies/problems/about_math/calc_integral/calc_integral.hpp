#pragma once


template<typename T>
double integralLeibniz(T const& points)
{
    double accumSquere = 0;

    auto cur = points.begin();
    cur++;

    auto prev = points.begin();

    while(cur != points.end()) {

        auto y1 = cur->second;
        auto y2 = prev->second;

        auto x1 = cur->first;
        auto x2 = prev->first;
        auto high =  x1 - x2;

        accumSquere +=  (y2 + y1) * 0.5 * high;

        prev = cur;
        cur++;
    }
    return accumSquere;
}

#include <vector>
#include <algorithm>

int main(int argc, char** argv)
{
    std::vector<int> nums = {1, 2, 4};

    auto iter = std::find(nums.begin(), nums.end(), 4);

    // итераторы вектора инвалидируются при опрациях, которые изменяют размер или структуру вектора (сортировоки)
    if (iter != nums.end()) {
        // вставка со смешение
        // nums.insert(iter, 3);
        // nums.emplace(iter, 3);

        // замена найденного
        // *iter = 3;
        nums[iter - nums.begin()] = 3;
    }

    return 0;
}

#include <vector>
#include <experimental/random>
#include <chrono>
#include <iostream>

#include <cassert>

class NumArray {
public:
    NumArray(std::vector<int>& nums)
        : mNums(std::move(nums))
    {
    }

    int sumRange(int left, int right) {
        int sum = 0;
        for (int i = left; i <= right; i++) {
            sum += mNums[i];
        }
        return sum;
    }
private:
    std::vector<int> mNums;
};

class NumArrayPrefixes {
public:
    NumArrayPrefixes(std::vector<int>& nums) {
        mPrefix.emplace_back(nums[0]);
        for(int i=1;i<nums.size();i++){
            mPrefix.emplace_back(mPrefix[i-1] + nums[i]);
        }
    }

    int sumRange(int left, int right) {
        if(left==0){
            return mPrefix[right];
        }
        return mPrefix[right] - mPrefix[left-1];
    }

private:
    std::vector<int> mPrefix;
};


void test() {
    constexpr size_t size = 100000000;
    std::vector<int> vec(size);

    for (int n = 0; n < size; ++n) {
        auto&& val = std::experimental::randint(1, 100);
        vec[n] =  std::move(val);
    }

    using clock = std::chrono::high_resolution_clock;

    auto point1 = clock::now();
    auto prefixSolution = new NumArrayPrefixes(vec);
    auto&& res = prefixSolution->sumRange(3, 8899213);
    res = prefixSolution->sumRange(24214, 99999999);
    std::cout << "Prefixes sum implementation runtime:" << clock::now() - point1 << std::endl;

    point1 = clock::now();
    auto solution = new NumArray(vec);
    auto&& res2 = solution->sumRange(3, 8899213);
    res2 = solution->sumRange(24214, 99999999);
    std::cout << "Naive sum implementation runtime:" << clock::now() - point1 << std::endl;

    assert(res == res2);
}

int main(int argc, char** argv) {
    test();
    return 0;
}

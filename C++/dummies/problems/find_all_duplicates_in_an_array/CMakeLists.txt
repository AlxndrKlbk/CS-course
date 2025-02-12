# Given an integer array nums of length n where all the integers of nums are in the range [1, n]
# and each integer appears at most twice, return an array of all the integers that appears twice.
# You must write an algorithm that runs in O(n) time and uses only constant auxiliary space, excluding the space needed to store the output

# Example 1:
# Input: nums = [4,3,2,7,8,2,3,1]
# Output: [2,3]

# Example 2:
# Input: nums = [1,1,2]
# Output: [1]

# Example 3:
# Input: nums = [1]
# Output: []

set(CPP_SOURCES
    solution.cpp
)

add_executable(find_all_duplicate_in_an_array ${CPP_SOURCES})

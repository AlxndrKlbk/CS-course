# Given a string s, return the longest in s.

# Example 1:
# Input: s = "babad"
# Output: "bab"
# Explanation: "aba" is also a valid answer.

# Example 2:
# Input: s = "cbbd"
# Output: "bb"

# Constraints:
#     1 <= s.length <= 1000
#     s consist of only digits and English letters.

set(CPP_SOURCES
    solution.cpp
)

add_executable(longes_palindromic_substring ${CPP_SOURCES})

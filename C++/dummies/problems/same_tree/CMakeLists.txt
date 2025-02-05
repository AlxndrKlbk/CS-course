# Given the roots of two binary trees p and q, write a function to check if they are the same or not.
# Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.

# Example 1:
# Input: p = [1,2,3], q = [1,2,3]
#     1     1
#    / \   / \
#    2 3   2 3
# Output: true

# Example 2:
#     1     1
#    /       \
#    2       2
# Input: p = [1,2], q = [1,null,2]
# Output: false

# Example 3:
#     1     1
#    / \   / \
#    2 1   1 2
# Input: p = [1,2,1], q = [1,1,2]
# Output: false

set(CPP_SOURCES
    solution.cpp
)

add_executable(same_tree ${CPP_SOURCES})

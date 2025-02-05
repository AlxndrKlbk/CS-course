# Given a binary tree, find its minimum depth.
# The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

# Note: A leaf is a node with no children.

set(CPP_SOURCES
    solution.cpp
)

add_executable(minimum_depth_of_binary_tree ${CPP_SOURCES})

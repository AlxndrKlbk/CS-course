# Given the head of a singly linked list, reverse the list, and return the reversed list.

# Input: head = [1,2,3,4,5]
# Output: [5,4,3,2,1]

set(CPP_SOURCES
    solution.cpp
)

add_executable(list_node_reverse ${CPP_SOURCES})

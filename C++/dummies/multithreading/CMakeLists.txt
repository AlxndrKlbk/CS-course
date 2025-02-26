
add_executable(fork_test fork_test/fork_test.cpp)
add_executable(signal_ignoring_test signal_ignoring_test/signal_ignoring_test.cpp)
add_executable(lock_with_file lock_with_file/lock_with_file.cpp)
add_executable(who_wc pipes/who_wc.cpp)
add_executable(shared_memory shared_memory/shared_memory.cpp)
add_executable(map_reduce map_reduce/map_reduce.cpp)

add_subdirectory(big_data_sort)
add_subdirectory(posix_ipc_pipe)
add_subdirectory(posix_semaphore)
add_subdirectory(threads)
add_subdirectory(events_queue)

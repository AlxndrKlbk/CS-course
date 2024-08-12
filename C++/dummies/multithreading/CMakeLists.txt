
add_executable(fork_test fork_test/fork_test.cpp)
add_executable(signal_ignoring_test signal_ignoring_test/signal_ignoring_test.cpp)
add_executable(lock_with_file lock_with_file/lock_with_file.cpp)
add_executable(who_wc pipes/who_wc.cpp)
add_executable(shared_memory shared_memory/shared_memory.cpp)

add_subdirectory(posix_ipc_pipe)
add_subdirectory(posix_semaphore)

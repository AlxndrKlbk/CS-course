
# execute "who" command, redirect input to PIPE write-side fd[0]
# execute "wc" command, count amount of lines on PIPE read-side fd[1]

add_executable(one_direction_channel who_wc.cpp)


# Эта программа записывает дамп структуры с виртуальными методам и множественным наследование в
# файл, который создается рядом с расположением исполняемого файла.
# Можно увидеть, как происходит выравнивание, сколько раз в памяти указан vptr

add_executable(layout_with_virtual_methods_multiple_inheritance source.cpp)

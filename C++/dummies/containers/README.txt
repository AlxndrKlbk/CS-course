Массивы (std::vector, std::array).

std::vector - динамический массив. Может занимать память "с запасом". Можно вставлять элементы в середину, удалять из середины, изменять размер массива и размер аллоцированной памяти в любое время. Элементы массива всегда создаются на куче.

Документация: http://www.cplusplus.com/reference/vector/vector/

std::array - статический массив (C++11). Является минимальной оболочкой над обычными массивами языка C. Размер массива задается во время компиляции. Память для элементов выделяется там, где объявлени массив (в частности, если массив объявлен на стеке, то и его элементы будут находиться на стеке).

Документация: http://www.cplusplus.com/reference/array/array/
Списки (std::list, std::forward_list, std::deque).

std::list - двусвязный список. Можно вставлять и удалять элементы с обоих концов и в середине (по итераторам). Можно итерироваться в прямом и обратном направлении,

Документация: http://www.cplusplus.com/reference/list/list/

std::forward_list - односвязный список (C++11). Можно итерироваться только в прямом направлении, но расходует меньше памяти.

Документация: http://www.cplusplus.com/reference/forward_list/forward_list/
Упорядоченныt ассоциативные контейнеры (std::set, std::multiset, std::map, std::multimap).

std::set - множество. Документация: http://www.cplusplus.com/reference/set/set/

std::multiset - мультимножество. Документация: http://www.cplusplus.com/reference/set/multiset/

std::map - ассоциативный массив, словарь, упорядоченный список пар "ключ-значение". Документация: http://www.cplusplus.com/reference/map/map/

std::multimap - упорядоченный список пар "ключ-значение" с повторениями ключей. Документация: http://www.cplusplus.com/reference/map/multimap/

Все эти контейнеры реализованы с помощью красно-черных деревьев. Подробнее:

    О 2-3 деревьях на английской википедии: https://en.wikipedia.org/wiki/2-3_tree
    О красно-черных деревьях на английской википедии: https://en.wikipedia.org/wiki/Red-black_tree

Дополнительно можно разобраться с B-деревьями и AVL-деревьями. Почитать можно тут:

    B-дерево: https://en.wikipedia.org/wiki/B-tree
    B+-дерево: https://en.wikipedia.org/wiki/B%2B_tree
    AVL-дерево: https://en.wikipedia.org/wiki/AVL_tree

А также имеет смысл попробовать следующие библиотеки:

    https://code.google.com/p/cpp-btree/
    http://adtinfo.org/

Неупорядоченные ассоциативные контейнеры (std::unordered_set, std::unordered_multiset, std::unordered_map, std::unordered_multimap).
Появились в C++11. Имеется четыре контейнера: std::unordered_set, std::unordered_multiset, std::unordered_map, std::unordered_multimap. Эти контейнеры реализованы с помощью хэш-таблиц, способ разрешения коллизий - метод цепочек. Подробнее на английской википедии: https://en.wikipedia.org/wiki/Hash_table

Документация:

    http://www.cplusplus.com/reference/unordered_set/unordered_set/
    http://www.cplusplus.com/reference/unordered_set/unordered_multiset/ 
    http://www.cplusplus.com/reference/unordered_map/unordered_map/ 
    http://www.cplusplus.com/reference/unordered_map/unordered_multimap/

Кольцевые буферы (boost::circular_buffer, boost::circular_buffer_space_optimized).
Отсутствуют в STL. Являются частью библиотеки Boost.
Документация: http://www.boost.org/doc/libs/1_58_0/doc/html/circular_buffer.html 

#include <iostream>
#include <iostream>

// Пустые классы только
// для теста приведения
struct foo {
    // Сделали полиморфным
    virtual void do_some() {
        std::cout << "foo" << std::endl;
    };
};

struct bar {
    // Сделали полиморфным
    virtual void do_some() {
        std::cout << "bar" << std::endl;
    };
};

// Наследники bar
struct baz : bar {
};

struct quux : bar {
};

int main() {
    // Переменные простых типов и указатели на переменные простых типов
    void* pv = nullptr;

    // Объекты классов
    foo oFoo;
    bar oBar;
    baz oBaz;
    quux oQuux;

    // Указатели на объекты классов
    foo* pFoo = &oFoo;
    bar* pBar = &oBar;
    baz* pBaz = &oBaz;
    quux* pQuux = &oQuux;

    // Приводим указатель на объект bar к указателю на объект foo
    // из разных иерархий
    pFoo = dynamic_cast<foo*>(pBar);
    if (pFoo == nullptr) {
        std::cout << "FAIL" << std::endl; // Ошибка на этапе выполнения!!!
    }

    // Приводим указатель на void к указателю на объект bar
    // pBar = dynamic_cast<foo*>(pv); // Ошибка на этапе компиляции!!!

    // Приводим указатель на bar к указателю на void
    pv = dynamic_cast<void*>(pBar);

    // Перемещение из одной иерархии наследования в другую
    pBar = dynamic_cast<bar*>(pBaz);
    pQuux = dynamic_cast<quux*>(pBar);
    if (pQuux == nullptr) {
        std::cout << "FAIL" << std::endl; // Ошибка на этапе выполнения!!!
    }

    bar* base_ptr = &oQuux;
    pQuux = dynamic_cast<quux*>(base_ptr);
    if (pQuux != nullptr) {
        std::cout << "SUCCES" << std::endl; // ок
    }

    return 0;
}

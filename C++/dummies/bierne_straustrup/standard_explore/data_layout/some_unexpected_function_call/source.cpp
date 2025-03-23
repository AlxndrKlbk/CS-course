#include <iostream>
using namespace std;

class FooInterface {
public:
    virtual ~FooInterface() = default;
    virtual void Foo() = 0;
};

class BarInterface {
public:
    virtual ~BarInterface() = default;

    virtual void Bar() = 0;
};

class Concrete : public FooInterface, public BarInterface {
public:
    void Foo() override { cout << "Foo()" << endl; }
    void Bar() override { cout << "Bar()" << endl; }
};

int main() {
    Concrete c;
    c.Foo();
    c.Bar();

    FooInterface* foo = &c;
    foo->Foo();

    std::cout << &c << std::endl;
    std::cout << &foo << std::endl;

    BarInterface* bar = (BarInterface*)(foo); // опасно делать reinterpret_cast на полиморфные типы
    bar->Bar(); // Выводит "Foo()" - WTF?     // после приведения вызов чере позднее связывание по указателю на vptr для Concrete,
                                              // у которого 1 метод то Foo, 2 метод это Bar. После каста интерпретирует ту же таблицу для concrete
                                              // как указатель на _vptr для BarInterface, у которого 1 метод это Bar(), но в памяти лежит указатель
                                              // на Concrete::Foo
}

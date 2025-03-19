#include <iostream>

const char* BACK_SIMBOL = "\033[A";
const char* MOVE_TO_LINE_END =  "\x1B[30C"; // сдвинуть каретку ввода на 15 символов вправо

class Base
{
public:

    Base(std::string msg) : mMsg(std::move(msg))
    {
        std::cout << "Base " << mMsg << std::endl;
    }

    ~Base() {
        std::cout << "-> ~Base" << std::endl;
    }

private:
    std::string mMsg;

};

class Derived : public Base
{
public:
    Derived(std::string msg) : Base(std::move(msg))
    {
        std::cout << BACK_SIMBOL << MOVE_TO_LINE_END << " -> Derived;" << std::endl;
    }

    ~Derived() {
        std::cout << "~Derived" << std::endl;
    }

};

int main(int argc, char** argv)
{
    Base b("From Stack");
    Derived d("From Stack");

    Base* pBase = new Base("From Heap");
    Base* pDerived = new Derived("From Heap");
    Derived* pDDerived = new Derived("From Heap");

    delete pBase;
    std::cout << "Base over Base* deleted" << std::endl;

    delete pDerived; // срезка, деструктор только только Base
    std::cout << "Derived overe Base* deleted" << std::endl;

    delete pDDerived; // ок, но потребовалось вызывать явно через указатель правильного типа, задействовав раннее связывание. Т.е вызов не полиморфный
    std::cout << "Derived overe Derived* deleted" << std::endl;

    return 0;
}

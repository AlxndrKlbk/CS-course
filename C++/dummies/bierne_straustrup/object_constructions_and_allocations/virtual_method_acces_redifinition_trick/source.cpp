#include <iostream>

class Person
{
public:
    Person(std::string name)
        : name{name}
    {}

    virtual void print() const  // виртуальная функция
    {
        std::cout << "Name: " << name << std::endl;
    }

private:
    std::string name;
};

class Employee: public Person
{
public:
    Employee(std::string name, std::string company)
        : Person{name}
        , company{company}
    {}

private:
    void print() const override // функция переопределена
    {
        Person::print();
        std::cout << "Works in " << company << std::endl;
    }
    std::string company;
};

class Emploee2
{
};

int main(int argc, char** argv)
{
    Employee bob {"Bob", "Microsoft"};
    Person* person {&bob};
    // bob.print();             // так нельзя - функция приватная ))0)
    person->print();            // а так можно)))0)

    Emploee2* e2P = dynamic_cast<Emploee2*>(&bob);
    if (e2P == nullptr) {
        std::cout << "cast to objects from other hierarchy" << std::endl;
    }


    return 0;
}

#include <iostream>

class Person
{
public:
    Person(std::string name): name{name}
    {
    }

    void print() const
    {
        std::cout << "Name: " << name << std::endl;
    }

private:
    std::string name;       //  имя

};

class Employee: public Person
{
public:
    Employee(std::string name, std::string company): Person{name}, company{company}
    {
    }

    void print() const
    {
        Person::print();
        std::cout << "Works in " << company << std::endl;
    }
private:
    std::string company;    // компания
};

int main()
{
    Person tom {"Tom"};
    Person* person {&tom};
    person->print();     // Name: Tom

    Employee bob {"Bob", "Microsoft"};
    person = &bob;
    person->print();    // Name: Bob
    Employee* employ = &bob;
    employ->print();
    return 0;
}

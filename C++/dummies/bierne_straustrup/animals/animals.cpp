#include <iostream>
#include <string>
#include <memory>
#include <vector>


class Animal
{
private:
    std::string name = "default_name";

public:
    Animal(const std::string& n)
        : name(n)
    {
    }

    const std::string& GetName() const
    {
        return name;
    }

    virtual std::string Voice() const = 0;

    virtual ~Animal() {
        std::cout << "Animal end ..." << std::endl;
    }
};

class Cat: public Animal
{
public:
    Cat(const std::string& n)
        : Animal(n)
    {
    }

    std::string Voice() const override
    {
        return "Meow!";
    }
};

class Dog: public Animal
{
public:
    Dog(const std::string& n)
        : Animal(n)
    {
    }

    std::string Voice() const override
    {
        return "Woof!";
    }
};

void Process(const Animal& creature)
{
    std::cout << creature.GetName() << ": " << creature.Voice() << std::endl;
}

int main()
{
    std::vector<std::unique_ptr<Animal>> zoo;

    zoo.emplace_back(std::make_unique<Cat>("Tom"));
    zoo.emplace_back(std::make_unique<Dog>("Buffa"));

    Process(*zoo[0]);  // Tom: Meow!
    Process(*zoo[1]);  // Buffa: Woof!

    Cat tom2 = *static_cast<Cat *>(zoo[0].get());
    Process(tom2);
}

#include <iostream>

class PoweredDevice {
public:
    PoweredDevice(int power = 0) : mValue(power) {
        std::cout << "PoweredDevice: " << power << '\n';
    }

    virtual int get_value() { return mValue; }
private:
    int mValue;
};

class Scanner : virtual public PoweredDevice {
public:
    Scanner(int scanner, int power) : PoweredDevice(power), mValue(power) {
        std::cout << "Scanner: " << scanner << '\n';
    }

    // int get_value() override { return mValue; }

private:
    int mValue;
};

class Printer : virtual public PoweredDevice {
public:
    Printer(int printer, int power) : PoweredDevice(power), mValue(power) {
        std::cout << "Printer: " << printer << '\n';
    }

    // int get_value() override { return mValue; }

private:
    int mValue;
};

// Possibilities to construct base class (PoweredDevice) for Copier
// - default constructor
// - default argument for PoweredDevice constructor with parameter
// - explicit call PoweredDevice constructor for initialization list of Copier
class Copier : public Scanner, public Printer {
public:
    Copier(int scanner, int printer, int power) : PoweredDevice(power), Scanner(scanner, scanner), Printer(printer, printer) {
        std::cout << "Copier: " << '\n';
    }

    // int get_value() override { return Printer::get_value(); }

};

int main() {
    Copier copier(1, 2, 100);
    std::cout << copier.get_value() << std::endl;
    return 0;
}

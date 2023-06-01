#include "Krone.h"
#include <iostream>
#include <iomanip>
#include <sstream>

Krone::Krone() : Currency(), currency_name("Krone") {}

Krone::Krone(double amount) : Currency(amount), currency_name("Krone") {}

Krone::Krone(const Krone& other) : Currency(other), currency_name("Krone") {}

Krone::~Krone() {}

void Krone::print() const {
    std::cout << getWholePart() << '.' << std::setw(2) << std::setfill('0') << getFractionalPart() << ' ' << currency_name << std::endl;
}

bool Krone::isValidUnit(const std::string& unit) const {
    return unit == "Krone";
}

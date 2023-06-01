#ifndef KRONE_H
#define KRONE_H

//Import currency base header file
#include "Currency.h"

//Declare the Krone class as a derived class of the Currency base class
class Krone : public Currency {
private:
    std::string currency_name;

public:

    //Default constructor, initializes whole_part and fractional_part to 0 and currency_name to "Krone"
    Krone() : Currency(), currency_name("Krone") {}

    //Constructor that takes an amount, initializes whole_part and fractional_part and currency_name to "Krone"
    Krone(double amount) : Currency(amount), currency_name("Krone") {}

    //Copy constructor, initializes the Krone object with the values of another Krone object ("other")
    Krone(const Krone& other) : Currency(other), currency_name("Krone") {}

    //Destructor
    ~Krone() {}

    //Print out Krone value and name
    void print() const override {
        std::cout << whole_part << '.' << (fractional_part < 10 ? "0" : "") << fractional_part << ' ' << currency_name << std::endl;
    }

    //Boolean function that checks currency type and user-implicit currency type 
    bool isValidUnit(const std::string& unit) const override {
        return unit == "Krone";
    }


    bool operator<(const Krone& other) const;
    bool operator>(const Krone& other) const;
    bool operator==(const Krone& other) const;


};

#endif

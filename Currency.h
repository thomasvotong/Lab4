// File defines the Currency class, representing a currency "value"
// It has two integer variables for the whole and fractional parts of the currency
// Public member functions (constructors, setters, getters, and misc) functions for adding, subtracting, and comparing currencies


#ifndef CURRENCY_H
#define CURRENCY_H


//Import libraries
#include <iostream>
#include <iomanip>  
#include <sstream>  


//Class currency with protected data
class Currency {
protected:
    int whole_part;
    int fractional_part;


public:

    Currency() : whole_part(0), fractional_part(0) {}


    // Constructor that initializes the whole and fractional parts from a double value
    Currency(double amount) {

        //Exception thrown if value is negative
        if (amount < 0) {
            throw std::string("Negative value objects are not allowed");
        }
        whole_part = static_cast<int>(amount);
        fractional_part = static_cast<int>((amount - whole_part) * 100 + 0.5);
    }

    //// Copy constructor that copies the whole and fractional parts from another Currency object
    Currency(const Currency& other) : whole_part(other.whole_part), fractional_part(other.fractional_part) {}

    //Destructor
    ~Currency() {}


    //Setter function for whole part
    void setWholePart(int whole) {

        //Exception thrown if value is negative
        if (whole < 0) {
            throw std::string("Negative value objects are not allowed");
        }
        whole_part = whole;
    }


    // Setter for the fractional part
    void setFractionalPart(int fractional) {

        //Exception thrown if value is negative
        if (fractional < 0) {
            throw std::string("Negative value objects are not allowed");
        }
        fractional_part = fractional;
    }

    //Getter function for whole part
    int getWholePart() const {
        return whole_part;
    }


    //Getter function for fractional part
    int getFractionalPart() const {
        return fractional_part;
    }


    //Adder function that adds another currency object
    void add(const Currency& other) {
        whole_part += other.whole_part;
        fractional_part += other.fractional_part;
        if (fractional_part >= 100) {
            whole_part += fractional_part / 100;
            fractional_part %= 100;
        }
    }

    //Subtracter function that subtracts another currency object 
    void subtract(const Currency& other) {
        if (isGreater(other)) {
            whole_part -= other.whole_part;
            if (fractional_part < other.fractional_part) {
                whole_part -= 1;
                fractional_part += 100;
            }
            fractional_part -= other.fractional_part;
        }
        else {
            //Exception thrown for a negative value
            throw std::string("Subtraction results in a negative value, which is not allowed");
        }
    }

    //Comparison function for currency objects to check if currencies are equal
    bool isEqual(const Currency& other) const {
        return whole_part == other.whole_part && fractional_part == other.fractional_part;
    }

    //Comparison function for currency objects to check if other currency is greater than this currency object
    bool isGreater(const Currency& other) const {
        return whole_part > other.whole_part || (whole_part == other.whole_part && fractional_part > other.fractional_part);
    }

    //Virtual function that prints the currency value
    virtual void print() const = 0;


    //Virtual function that checks if currency and the user-implicit currency type match 
    virtual bool isValidUnit(const std::string& unit) const {
        return false; // Default implementation, should be overridden in derived classes
    }

    //Function that provides the amount to calls
    double getAmount() const {
        return whole_part + fractional_part / 100.0;
    }

    //Function that provides a value to 2 decimal places as a string 
    std::string toString() const {
        std::stringstream ss;
        ss << std::fixed << std::setprecision(2) << getAmount();
        return ss.str();
    }

    bool operator<(const Currency& other) const {
        return getAmount() < other.getAmount();
    }

    bool operator>(const Currency& other) const {
        return getAmount() > other.getAmount();
    }

    bool operator==(const Currency& other) const {
        return getAmount() == other.getAmount();
    }



};

#endif 

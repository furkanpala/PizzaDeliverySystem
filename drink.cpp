// Furkan Pala


#ifndef DRINK
#define DRINK

#include <string>

// Drink.h START

class Drink
{
    std::string name;
    double price;

public:
    Drink() : name(""), price(0) {}
    Drink(std::string);
    std::string getName() const { return name; };
    double getPrice() const { return price; };
    bool operator==(const Drink &) const;
};

// Drink.h END

// Drink.cpp START

bool Drink::operator==(const Drink &drink) const
{
    return name == drink.name && price == drink.price;
}

// Drink.cpp END

// Drink.cpp START

Drink::Drink(std::string drinkName) : name(drinkName)
{
    if (drinkName == "cola")
        price = 4;
    else if (drinkName == "soda")
        price = 2;
    else if (drinkName == "ice tea")
        price = 3;
    else
        price = 3.5;
}

// Drink.cpp END
#endif
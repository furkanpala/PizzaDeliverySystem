// Furkan Pala


#ifndef ORDER
#define ORDER

#include <string>
#include <iostream>
#include "list.cpp"
#include "pizza.cpp"
#include "drink.cpp"

// Order.h START

class Order
{
    std::string customer;
    List<Pizza *> pizza;
    List<Drink *> drink;

public:
    Order(std::string, const List<Pizza *> &, const List<Drink *> &);
    Order(std::string, const List<Pizza *> &);
    double getPrice();
    void printOrder();
    std::string getCustomerName() const { return customer; };
};

// Order.h END

// Order.cpp START
Order::Order(std::string customer_name, const List<Pizza *> &pizzas, const List<Drink *> &drinks)
    : customer(customer_name), pizza(pizzas), drink(drinks)
{
}

Order::Order(std::string customer_name, const List<Pizza *> &pizzas)
    : customer(customer_name), pizza(pizzas)
{
}

double Order::getPrice()
{
    double total = 0;
    for (int i = 0; i < pizza.getSize(); i++)
        total += pizza[i]->getPrice();
    for (int i = 0; i < drink.getSize(); i++)
        total += drink[i]->getPrice();

    return total;
}

void Order::printOrder()
{
    std::cout << "---------------" << std::endl;
    std::cout << "Name: " << customer << std::endl
              << std::endl;
    for (int i = 0; i < pizza.getSize(); i++)
    {
        std::cout << pizza[i]->getName() << " (";
        for (int j = 0; j < pizza[i]->getIngredients().getSize(); j++)
        {
            std::cout << pizza[i]->getIngredients()[j];
            if (j != pizza[i]->getIngredients().getSize() - 1)
                std::cout << ", ";
        }
        std::cout << ")" << std::endl;
        std::cout << "size: " << pizza[i]->getSize() << ", crust: " << pizza[i]->getCrustType() << std::endl
                  << std::endl;
    }

    // Count the drinks
    Drink cola("cola"), soda("soda"), ice_tea("ice tea"), fruit_juice("fruit juice");
    int colaCount = drink.count(&cola);
    int sodaCount = drink.count(&soda);
    int iceTeaCount = drink.count(&ice_tea);
    int fruitJuiceCount = drink.count(&fruit_juice);

    if (colaCount != 0)
    {
        std::cout << colaCount << " cola, ";
    }
    if (sodaCount != 0)
    {
        std::cout << sodaCount << " soda, ";
    }

    if (iceTeaCount != 0)
    {
        std::cout << iceTeaCount << " ice tea, ";
    }
    if (fruitJuiceCount != 0)
    {
        std::cout << fruitJuiceCount << " fruit juice, ";
    }

    std::cout << std::endl
              << "---------------" << std::endl;
}

// Order.cpp END
#endif
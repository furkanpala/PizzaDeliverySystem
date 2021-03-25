// Furkan Pala


#ifndef ORDERLIST
#define ORDERLIST

#include <iostream>
#include <string>

#include "list.cpp"
#include "pizza.cpp"
#include "drink.cpp"
#include "order.cpp"

// OrderList.h START

class OrderList
{
    int n;
    List<Order *> head;

public:
    OrderList() : n(0) {} // Default constructor of List class makes the head of the list null
    void takeOrder();
    void listOrders() const;
    void deliverOrders();
};

// OrderList.h END

// OrderList.cpp START

void OrderList::takeOrder()
{
    int pizzaType, amount, drinkType;
    std::string size, crustType, customerName;

    std::string input;
    bool error = false;

    std::cout << "Pizza Menu" << std::endl;
    std::cout << "1. Chicken Pizza (mozarella, chicken, mushroom, corn, onion, tomato)" << std::endl;
    std::cout << "2. Broccoli Pizza (mozarella, broccoli, pepperoni, olive, corn, onion)" << std::endl;
    std::cout << "3. Sausage Pizza (mozarella, sausage, tomato, olive, mushroom, corn)" << std::endl;
    std::cout << "0. Back to main menu" << std::endl;

    try
    {
        getline(std::cin, input);
        pizzaType = std::stoi(input);
    }
    catch (...)
    {
        error = true;
    }

    while (error || (pizzaType != 0 && pizzaType != 1 && pizzaType != 2 && pizzaType != 3))
    {
        std::cout << "Invalid choice" << std::endl
                  << std::endl;
        std::cout << "Pizza Menu" << std::endl;
        std::cout << "1. Chicken Pizza (mozarella, chicken, mushroom, corn, onion, tomato)" << std::endl;
        std::cout << "2. Broccoli Pizza (mozarella, broccoli, pepperoni, olive, corn, onion)" << std::endl;
        std::cout << "3. Sausage Pizza (mozarella, sausage, tomato, olive, mushroom, corn)" << std::endl;
        std::cout << "0. Back to main menu" << std::endl;

        error = false;
        try
        {
            getline(std::cin, input);
            pizzaType = std::stoi(input);
        }
        catch (...)
        {
            error = true;
        }
    }
    if (pizzaType == 0)
        return;

    std::cout << "Select size: small (15 TL), medium (20 TL), big (25 TL)" << std::endl;
    getline(std::cin, size);

    while (size != "small" && size != "medium" && size != "big")
    {
        std::cout << "Invalid choice" << std::endl
                  << std::endl;
        std::cout << "Select size: small (15 TL), medium (20 TL), big (25 TL)" << std::endl;
        getline(std::cin, size);
    }

    std::cout << "Select crust type: thin, normal, thick" << std::endl;
    getline(std::cin, crustType);

    while (crustType != "thin" && crustType != "normal" && crustType != "thick")
    {
        std::cout << "Invalid choice" << std::endl
                  << std::endl;
        std::cout << "Select crust type: thin, normal, thick" << std::endl;
        getline(std::cin, crustType);
    }

    std::cout << "Enter the amount:";
    error = false;
    try
    {
        getline(std::cin, input);
        amount = std::stoi(input);
    }
    catch (...)
    {
        error = true;
    }

    while (error || amount <= 0)
    {
        std::cout << "Amount must be a positive whole number" << std::endl
                  << std::endl;
        std::cout << "Enter the amount:";

        error = false;
        try
        {
            getline(std::cin, input);
            amount = std::stoi(input);
        }
        catch (...)
        {
            error = true;
        }
    }
    // Create a list to store pizzas
    List<Pizza *> pizzas;

    // Create pizza
    Pizza *pizza = new Pizza(size, crustType, pizzaType);

    // And push to the list
    pizzas.push_back(pizza);

    // Copy constructors are invoked here if amount is more than one
    for (int i = 0; i < amount - 1; i++)
        pizzas.push_back(new Pizza(*pizza));

    // Create a list to store drinks;
    List<Drink *> drinks;

    std::cout << "Please choose a drink:" << std::endl;
    std::cout << "0. no drink" << std::endl;
    std::cout << "1. cola 4 TL" << std::endl;
    std::cout << "2. soda 2 TL" << std::endl;
    std::cout << "3. ice tea 3 TL" << std::endl;
    std::cout << "4. fruit juice 3.5 TL" << std::endl;
    std::cout << "Press -1 for save your order" << std::endl;

    bool noDrink = false;

    while (true && !noDrink)
    {
        if (error)
        {
            std::cout << "Invalid choice" << std::endl
                      << std::endl;

            std::cout << "Please choose a drink:" << std::endl;
            std::cout << "0. no drink" << std::endl;
            std::cout << "1. cola 4 TL" << std::endl;
            std::cout << "2. soda 2 TL" << std::endl;
            std::cout << "3. ice tea 3 TL" << std::endl;
            std::cout << "4. fruit juice 3.5 TL" << std::endl;
            std::cout << "Press -1 for save your order" << std::endl;
        }
        error = false;
        try
        {
            getline(std::cin, input);
            drinkType = std::stoi(input);
        }
        catch (...)
        {
            error = true;
            continue;
        }

        if (drinkType < -1 || drinkType > 4)
            error = true;
        else if (drinkType == 0)
            noDrink = true;
        else if (drinkType == -1)
            break;
        else
        {
            if (drinkType == 1)
                drinks.push_back(new Drink("cola"));
            else if (drinkType == 2)
                drinks.push_back(new Drink("soda"));
            else if (drinkType == 3)
                drinks.push_back(new Drink("ice tea"));
            else if (drinkType == 4)
                drinks.push_back(new Drink("fruit juice"));

            error = false;
        }
    }

    std::cout << "Please enter your name:" << std::endl;
    getline(std::cin, customerName);

    Order *order;

    if (!noDrink)
        order = new Order(customerName, pizzas, drinks);
    else
        order = new Order(customerName, pizzas);

    head.push_back(order);
    n++;

    std::cout << std::endl
              << "Your order is saved, it will be delivered when it is ready..." << std::endl;

    order->printOrder();
}

void OrderList::listOrders() const
{
    if (n == 0)
        std::cout << "There is no order" << std::endl;
    else
    {
        for (int i = 0; i < n; i++)
        {
            std::cout << i + 1 << std::endl;
            head[i]->printOrder();
        }
    }
}

void OrderList::deliverOrders()
{
    if (n == 0)
        std::cout << "There is no order to deliver" << std::endl;
    else
    {
        listOrders();

        std::string customerName;

        std::cout << "Please write a customer name in order to deliver his/her order: ";

        getline(std::cin, customerName);

        Order *orderToBeDelivered = head.getOrder(customerName);

        while (orderToBeDelivered == nullptr)
        {
            std::cout << "An order with customer name " << customerName << " could not be found" << std::endl;
            std::cout << "Please write a customer name in order to deliver his/her order: ";
            getline(std::cin, customerName);
            orderToBeDelivered = head.getOrder(customerName);
        }
        std::cout << "Following order is delivering..." << std::endl;
        orderToBeDelivered->printOrder();

        std::cout << "Total price: " << orderToBeDelivered->getPrice() << std::endl;

        std::string answer;
        std::string promotionCode;

        bool error = false;
        bool isPromotionCodeCorrect = false;
        bool promotionCodeError = false;

        while (true)
        {
            if (error)
                std::cout << "Enter y or n" << std::endl;

            if (promotionCodeError)
                std::cout << "Promotion code is not accepted" << std::endl;

            std::cout << "Do you have a promotion code? (y/n)" << std::endl;
            getline(std::cin, answer);

            if (answer != "y" && answer != "n")
            {
                error = true;
                promotionCodeError = false;
                continue;
            }

            else if (answer == "n")
                break;

            error = false;
            std::cout << "Please enter your code: ";
            getline(std::cin, promotionCode);

            if (promotionCode == "I am a student")
            {
                isPromotionCodeCorrect = true;
                promotionCodeError = false;
                break;
            }
            else
            {
                isPromotionCodeCorrect = false;
                promotionCodeError = true;
            }
        }

        if (isPromotionCodeCorrect)
            std::cout << "Discounted price: " << orderToBeDelivered->getPrice() * 9 / 10 << std::endl;

        head.remove(orderToBeDelivered);
        n--;
        std::cout << "The order is delivered successfully!" << std::endl
                  << std::endl;
    }
}

// OrderList.cpp END
#endif
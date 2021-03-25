// Furkan Pala

// How to compile
// g++ -std=c++11 main.cpp -o main

#include <string>
#include <iostream>

#include "orderlist.cpp"

int main()
{
    OrderList orderList;

    bool error = false;
    while (true)
    {
        if (error)
        {
            std::cout << "Invalid choice" << std::endl
                      << std::endl;
        }

        std::cout << "Welcome to Unicorn Pizza!" << std::endl;
        std::cout << "1. Add an order" << std::endl;
        std::cout << "2. List orders" << std::endl;
        std::cout << "3. Deliver order" << std::endl;
        std::cout << "4. Exit" << std::endl;

        error = false;

        int choice;
        std::string input;
        try
        {
            getline(std::cin, input);
            choice = std::stoi(input);
        }
        catch (...)
        {
            error = true;
            continue;
        }

        if (choice == 1)
            orderList.takeOrder();
        else if (choice == 2)
            orderList.listOrders();
        else if (choice == 3)
            orderList.deliverOrders();
        else if (choice == 4)
            break;
        else
            error = true;
    }

    std::cout << "Goodbye..." << std::endl;

    return 0;
}

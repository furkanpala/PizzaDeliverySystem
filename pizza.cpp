// Furkan Pala


#ifndef PIZZA
#define PIZZA

#include <string>
#include <iostream>
#include "list.cpp"

// Pizza.h START

class Pizza
{
    std::string name;
    std::string size;
    std::string crust_type;
    List<std::string> ingredients;
    double price;

public:
    Pizza();
    Pizza(std::string, std::string, int);
    Pizza(Pizza &);

    std::string getName() const { return name; };
    std::string getSize() const { return size; };
    std::string getCrustType() const { return crust_type; };
    const List<std::string> &getIngredients() const { return ingredients; }
    double getPrice() const { return price; };
};

// Pizza.h END

// Pizza.cpp START

Pizza::Pizza()
{
    size = "medium";
    crust_type = "normal";
    ingredients.push_back("mozarella");
    price = 20;
}

Pizza::Pizza(std::string size, std::string crust_type, int pizza_type)
{
    this->size = size;
    this->crust_type = crust_type;
    if (pizza_type == 1)
    {
        name = "Chicken Pizza";
        ingredients.push_back("mozarella");
        ingredients.push_back("chicken");
        ingredients.push_back("mushroom");
        ingredients.push_back("corn");
        ingredients.push_back("onion");
        ingredients.push_back("tomato");
    }
    else if (pizza_type == 2)
    {
        name = "Broccoli Pizza";
        ingredients.push_back("mozarella");
        ingredients.push_back("broccoli");
        ingredients.push_back("pepperoni");
        ingredients.push_back("olive");
        ingredients.push_back("corn");
        ingredients.push_back("onion");
    }
    else if (pizza_type == 3)
    {
        name = "Sausage Pizza";
        ingredients.push_back("mozarella");
        ingredients.push_back("sausage");
        ingredients.push_back("tomato");
        ingredients.push_back("olive");
        ingredients.push_back("mushroom");
        ingredients.push_back("corn");
    }
    if (size == "small")
        price = 15;
    else if (size == "medium")
        price = 20;
    else
        price = 25;
}

Pizza::Pizza(Pizza &pizza)
{
    name = pizza.name;
    size = pizza.size;
    crust_type = pizza.crust_type;
    ingredients = pizza.ingredients;
    price = pizza.price;

    List<std::string> toBeRemoved;

    std::cout
        << "Please enter the number of ingredient you want to remove from your pizza" << std::endl;
    for (int i = 0; i < ingredients.getSize(); i++)
        std::cout << i + 1 << ". " << ingredients[i] << std::endl;
    std::cout << "Press 0 to save it" << std::endl;

    bool error = false;
    bool alreadyChoosed = false;

    while (toBeRemoved.getSize() < ingredients.getSize())
    {
        if (error)
        {
            std::cout << "Invalid choice" << std::endl
                      << std::endl;
        }

        if (alreadyChoosed)
        {
            std::cout << "You have already choosen this ingredient" << std::endl
                      << std::endl;
        }

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
            alreadyChoosed = false;
        }

        if (choice < 0 || choice > ingredients.getSize())
        {
            error = true;
            alreadyChoosed = false;
        }
        else if (choice == 0)
            break;
        else if (toBeRemoved.contains(pizza.ingredients[choice - 1]))
            alreadyChoosed = true;
        else
        {
            toBeRemoved.push_back(pizza.ingredients[choice - 1]);
            error = false;
            alreadyChoosed = false;
        }
    }

    for (int i = 0; i < toBeRemoved.getSize(); i++)
        ingredients.remove(toBeRemoved[i]);
}

// Pizza.cpp END
#endif
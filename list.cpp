// Furkan Pala


#ifndef LIST
#define LIST

#include <string>
#include "node.cpp"

// List.h START

template <typename T>
class List
{
    Node<T> *head;
    int size;

public:
    List() : head(nullptr), size(0) {}   // Default constructor for List
    List(const List<T> &);               // Copy constructor for List
    int getSize() const;                 // Returns the current size of the list
    int count(const T &) const;          // Counts given data in the list
    void push_back(T);                   // Inserts one element to end of the list
    void remove(T);                      // Removes an element from the list
    bool contains(T);                    // Checks if given data exists in list
    const T getOrder(std::string) const; // Searches an order with given customer name and returns if it is in the list
    T &operator[](int) const;            // Overloading [] operator.
    void operator=(const List<T> &);     // Overloading = operator
    ~List();                             // Destructor for List
};

// List.h END

// List.cpp START

template <typename T>
List<T>::List(const List<T> &list) : head(nullptr), size(0)
{
    for (int i = 0; i < list.getSize(); i++)
        push_back(list[i]);
}

template <typename T>
int List<T>::getSize() const
{
    return size;
}

template <typename T>
int List<T>::count(const T &data) const
{
    int count = 0;
    Node<T> *traverse = head;
    while (traverse)
    {
        if (*(traverse->data) == *data)
            count++;
        traverse = traverse->next;
    }

    return count;
}

template <typename T>
void List<T>::push_back(T data)
{
    // Create new Node with data
    Node<T> *nn = new Node<T>(data);

    // Find insert position
    if (head == nullptr)
    {
        head = nn;
        size++;
        return;
    }

    Node<T> *traverse = head;
    while (traverse->next)
        traverse = traverse->next;

    // Traverse points to end of the list

    traverse->next = nn;
    size++;
}

template <typename T>
void List<T>::remove(T data)
{
    Node<T> *traverse = head;

    // Removing head
    if (head->data == data)
        head = head->next;
    else
    {
        Node<T> *traverse2 = head;

        while (traverse && traverse->data != data)
        {
            traverse2 = traverse;
            traverse = traverse->next;
        }

        traverse2->next = traverse->next;
    }

    delete traverse;
    size--;
}

template <typename T>
bool List<T>::contains(T data)
{
    Node<T> *traverse = head;
    bool found = false;
    while (traverse)
    {
        if (traverse->data == data)
        {
            found = true;
            break;
        }
        traverse = traverse->next;
    }

    return found;
}

template <typename T>
const T List<T>::getOrder(std::string customerName) const
{
    Node<T> *traverse = head;
    while (traverse)
    {
        if (traverse->data->getCustomerName() == customerName)
            break;

        traverse = traverse->next;
    }
    if (traverse == nullptr)
        return nullptr;
    return traverse->data;
}

template <typename T>
T &List<T>::operator[](int index) const
{
    if (index + 1 > size)
    {
        std::cerr << "Index is out of bound, exiting" << std::endl;
        exit(1);
    }

    int count = 0;
    Node<T> *traverse = head;
    while (traverse && count < index)
    {
        traverse = traverse->next;
        count++;
    }
    return traverse->data;
}

template <typename T>
void List<T>::operator=(const List<T> &list)
{
    for (int i = 0; i < list.getSize(); i++)
        push_back(list[i]);
}

template <typename T>
List<T>::~List()
{
    Node<T> *traverse = head;

    while (head)
    {
        traverse = head;
        head = head->next;
        delete traverse;
    }
}

// List.cpp END
#endif
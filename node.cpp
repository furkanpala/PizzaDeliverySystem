// Furkan Pala


#ifndef NODE
#define NODE

// Node.h START

template <typename T>
struct Node
{
    T data;
    Node<T> *next;
    Node(T);
};

// Node.h END

// Node.cpp START

template <typename T>
Node<T>::Node(T data)
{
    this->data = data;
    next = nullptr;
}

// Node.cpp END
#endif
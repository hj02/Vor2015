#include <iostream>

using namespace std;

class EmptyStackException { };

template<class T>
class Stack
{
    private:
		template<class T>
		struct Node
		{
			T data;
			Node<T> *link;
		};

        Node<T> *head;

    public:
        // Initializes an empty stack.
        Stack();

        // Determines whether the stack is empty.
        bool empty();

        // Adds 'item' to the top of the stack.
        void push(T item);

        // Removes the top of the stack (i.e. removes the element that was added
        // most recently), and returns it.
        T pop();

        // Retrieves the top of the stack.
        T top();
};


template<class T>
Stack<T>::Stack()
{
    head = NULL;
}


template<class T>
bool Stack<T>::empty()
{
    return (head == NULL);
}

template<class T>
void Stack<T>::push(T item)
{
    Node<T> *tmp = new Node<T>();
    tmp->data = item;
    tmp->link = head;
    head = tmp;
}

template<class T>
T Stack<T>::pop()
{
    if(empty()) {
        throw EmptyStackException();
    }

    T t = head->data;
    Node<T> *next = head->link;
    delete head;
    head = next;
    return t;
}

template<class T>
T Stack<T>::top()
{
    if(empty()) {
        throw EmptyStackException();
    }
    return head->data;
}

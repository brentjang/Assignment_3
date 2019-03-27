#include <iostream>
#include "InvalidStackOperationException.h"
using namespace std;

template <class T>
class GenStack
{
private:
    int size;
    int top;
    T *myArray;
    T *tempArray;

public:
    GenStack();
    GenStack(int maxSize);
    ~GenStack();
    void push(T d);
    T pop();
    T peek();
    bool isFull();
    bool isEmpty();
};

template<class T>
GenStack<T>::GenStack()
{
    //default constructor for stack of type T
    myArray = new T[100];
    size = 100;
    top = -1;
}

template<class T>
GenStack<T>::GenStack(int maxSize)
{
    myArray = new T[maxSize];
    size = maxSize;
    top = -1;
}

template<class T>
GenStack<T>::~GenStack()
{
    delete myArray;
    delete tempArray;
}

template<class T>
void GenStack<T>::push(T d)
{
    if(isFull())
    {
        //if stack is full, copy to new stack and increase, then copy back to old stack
        int oldSize = size;
        size += 1;

        tempArray = new T[size];
        for(int i = 0; i < oldSize; i++)
        {
            tempArray[i] = myArray[i];
        }

        myArray = new T[size];
        for(int i = 0; i < oldSize; i++)
        {
            myArray[i] = tempArray[i];
        }

        push(d);
    }
    else
    {
        myArray[++top] = d;
    }
}

template<class T>
T GenStack<T>::pop()
{
    try
    {
        if(isEmpty())
        {
            throw InvalidStackOperationException("Cannot pop an empty stack.");
        }
        return myArray[top--];
    }
    catch (InvalidStackOperationException& msg)
    {
        cout << msg.getMessage() << endl;
    }
}

template<class T>
T GenStack<T>::peek()
{
    try
    {
        if(isEmpty())
        {
            throw InvalidStackOperationException("Cannot peek an empty stack.");
        }
        return myArray[top];
    }
    catch (InvalidStackOperationException& msg)
    {
        cout << msg.getMessage() << endl;
    }
}

template<class T>
bool GenStack<T>::isFull()
{
    return (top == size-1);
}

template<class T>
bool GenStack<T>::isEmpty()
{
    return (top == -1);
}

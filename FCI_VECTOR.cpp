/*
//
// Created by omara on 12/14/2019.
//

#include "FCI_VECTOR.h"

template<class T>
int FCI_VECTOR<T>::getSize()
{
    return size; // return number of elements
}

template<class T>
int FCI_VECTOR<T>::getCapacity()
{
    return capacity; // allocated memory
}

template<class T>
bool FCI_VECTOR<T>::empty()
{
    if(size==0)
        return true;
    return false; // vector is not empty
}

template<class T>
void FCI_VECTOR<T>::insert(T * position, T val)
{

}

template<class T>
void FCI_VECTOR<T>::push_back(T element)
{
    if (size == capacity) // check if there's already an element, then we double the capacity and allocate a new one
    {                     // with the new capacity
        int* temp = new int[2 * capacity];

        for (int i = 0; i < capacity; i++)
            temp[i] = elements[i]; // copying the content of the old array to the new temporary array.

        delete[] elements;  // deallocate the old elements array
        capacity *= 2;      // double the capacity
        elements = temp;    // now the elements list points to temp address
    }

    // Inserting data
    elements[size] = element;
    size++;
}

template<class T>
void FCI_VECTOR<T>::pop_back()
{
    size--; // size < actual capacity
}

template<class T>
void FCI_VECTOR<T>::clear()
{
    delete [] elements;
    elements=new T[1];
    capacity=1;
    size=0;
}

template<class T>
void FCI_VECTOR<T>::erase(T * position)
{

}

template<class T>
T &FCI_VECTOR<T>::back()
{
    return elements[size];
}

template<class T>
T &FCI_VECTOR<T>::front()
{
    return elements[0];
}

template<class T>
T *FCI_VECTOR<T>::begin()
{

}

template<class T>
FCI_VECTOR<T>::FCI_VECTOR() // creating a new vector of size zero but it can allocates one element (capacity =1)
{

    elements=new T[1];
    capacity=1;
    size=0;
}

template<class T>
T &FCI_VECTOR<T>::operator[](int index) {
    if (index >= size)
    {
        cout << "List index out of bound, exiting";
        exit(0);
    }
    return elements[index];
}


*/

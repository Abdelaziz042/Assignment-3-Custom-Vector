//
// Created by omara on 12/14/2019.
//

// ID       : 20180178
// Group   : G9 / G10
// Name   : Omar Abdelaziz Gamal Eldin Ahmed

#ifndef ASS3_FCI_VECTOR_H
#define ASS3_FCI_VECTOR_H

#include <iostream>
#include "Student.h"
using namespace std;
// Creating a template class
template <class T>
class FCI_VECTOR
{
private:
    int size,capacity;
    T* elements;
public:
    FCI_VECTOR() // create an empty vector
    {
        elements=new T[1];
        capacity=1;
        size=0;
    }
    /*
     ~FCI_VECTOR() // deletes the allocation and points elements pointer to null
    {
        delete [] elements;
        elements=0; // now it points to nothing
    }*/

    int getSize()  {return size;}

    int getCapacity(){return capacity;}

    bool empty(){
        if(size==0)
            return true;
        return false; // vector is not empty
         }

    T &operator[](int index)
    {
        if (index >= size || index<0) //edited
            throw out_of_range("Your position is out of range!");
        return elements[index];
    }

    T* begin(){return &elements[0];}

    T& front()
    {
        if(size==0)
            throw invalid_argument("The list is empty");
        else return elements[0];
    }

    T& back()
    {
        if(size ==0)
        {
            throw invalid_argument("The list is empty");
        }
        else
        return elements[size-1];
    }

    void insert(T* pos ,T value)
   {
        int index=0;
        if(capacity>size)
        {
            ShiftnAssign(pos,value);
        }
        else if (capacity==size)
        {
            for(int i=0;i < size ; i++)
            {
                if(pos==&elements[i])
                    index=i;
            }
            if(index == 0) // which means i need to push back the value at index [5] for example
                push_back(value);
            else if (index < size)
            {
                doubleCapacity();
                for(int i=capacity-1;i>=index;i--)
                    elements[i]=elements[i-1];

                elements[index]=value;
                size++;
            }
        }
    }

    void erase(T* pos)  // pos is equal to begin() + the position of the desired element - 1
    {
        int index=-1;

        if(size==0)
        {
            throw(invalid_argument("You are trying to erase an element that doesn't exist. Please fill the list"));
        }

        // an iteration that searches if the position exists, else index still be zero and an exception is thrown.

        for (int i = 0; i < size; i++ )
        {
            if(pos==&elements[i])
                index=i;
        }

        if(index == -1)
        {
            throw(out_of_range("Position is out of range"));
        }
        else
            {
            for (int i = index; i < size; i++)
                elements[i] = elements[i + 1]; //shift the vector to the left
            size--;
            }
    }

    void push_back(T element)
    {
        if (size == capacity)
        {
            doubleCapacity();
        }
        // Inserting data
        elements[size] = element;
        size++;
    }

    void pop_back()
    {
            if(size!=0)
            {
                size=size-1;
            }
            // size < actual capacity ; which means i have the allocated capacity which is 2 for example
            // but i have  one element
    }

    void clear()
    {
        delete [] elements;
        elements=0;
        elements=new T[1];
        capacity=1;
        size=0;
    }

    // Additional Methods

    friend ostream& operator <<(ostream &out,FCI_VECTOR<T>&list)
    {
            for (int i = 0; i < list.getSize(); i++)
                out << list[i] << endl;
        return out;
    }

    void doubleCapacity()
    {
        T* temp = new T[2 * capacity];      // we double the capacity of the list
                                            // and allocate a new one with the new capacity
        for (int i = 0; i < capacity; i++)
            temp[i] = elements[i];          // copying the content of the old array to the new temporary array.

        delete[] elements; // deallocate the old elements array
        elements=0;         // now elements points to nothing
        capacity *= 2;      // double the capacity
        elements = temp;    // now the elements list points to temp address
    }

    void ShiftnAssign(T* pos, T value)
    {
        int index=0;

        for(int i=0;i < size ; i++)
        {
            if(pos==&elements[i])
                index=i;
        }

        for(int i=capacity-1;i>=index;i--) // shift the vector to right
            elements[i]=elements[i-1];

        elements[index]=value; // assigns the value at index with the new value
        size++;
    }

    void addElement(FCI_VECTOR<T>&list , int ListElement)
    {
        for(int i=0;i<ListElement;i++)
        {
            T element;
            cout << "Add Element : ";
            cin >> element;
            cin.ignore();
            list.push_back(element);
            cout << "\nElement Added " << endl;
        }
        cout << "All elements are added successfully ! " << endl;
    }
};



#endif //ASS3_FCI_VECTOR_H

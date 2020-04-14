// ID       : 20180178
// Group   : G9 / G10
// Name   : Omar Abdelaziz Gamal Eldin Ahmed

// Libraries
#include <iostream>
#include <cstdlib>
using namespace std;

// Class Headers
#include "Student.h"
#include "Course.h"
#include "FCI_VECTOR.h"

using namespace std;

// Function Prototypes

void displayType();
void displayOperation();

template <class T>
void operationSwitch(FCI_VECTOR<T>&list); // Internal switch used whenever a list is created and do operations on it.

int main()
{
     int choice;
     while(true) // Loops until the user exit the program

    { // Start of the main while loop
        system("cls");

        displayType();
        cout << "Choice: ";

            while(!(cin>>choice)) // Input Validation Loop
            {
                cout << "Your choice must be a number!" << endl;
                cin.clear();
                cin.ignore(100,'\n'); // to accept any number of wrong input and ignore it.
                cout << "Choice: ";
            }

        switch(choice)
        { // Start of switch
            // Creating a list and calling operation function.
            case 1:
                {
                    cout << "A List of integers has been created successfully." << endl;
                    system("cls");
                    FCI_VECTOR<int> list;
                    operationSwitch(list);
                    break;
                 }
            case 2:
                {
                    cout << "A List of characters has been created successfully." << endl;
                    system("cls");
                    FCI_VECTOR<char> list;
                    operationSwitch(list);
                    break;
                 }
            case 3:
                {
                    cout << "A List of strings has been created successfully." << endl;
                    system("cls");
                    FCI_VECTOR<string> list;
                    operationSwitch(list);
                    break;
                }
            case 4:
                {
                     cout << "A List of floats has been created successfully." << endl;
                     system("cls");
                     FCI_VECTOR<float> list;
                     operationSwitch(list);
                     break;
                }
            case 5:
                {
                     cout << "A List of students has been created successfully." << endl;
                     system("cls");
                     FCI_VECTOR<Student> list;
                     operationSwitch(list);
                     break;
                }
            case 6:
                     system("cls");

                     cout << "Thanks for using the program." << endl;
                     return 0;

            default:
                    cout << "Not an Option!\n\n";

                  system("pause");
                 system("cls");

        } // End of switch

    } // End of the main while loop
}

// Function Definitions

void displayType()
{
    cout << "Insert type of vector you would like to create: \n\n";
    cout << "1. List of Integers \n"
         << "2. List of Characters \n"
         << "3. List of Strings \n"
         << "4. List of Floats \n"
         << "5. List of Students \n"
         << "6. Exit \n\n";
}

void displayOperation()
{
    cout << "What kind of operation would you like to perform? \n\n";
    cout << "\t1.  Add element \n"
         << "\t2.  Remove last element \n"
         << "\t3.  Insert element at certain position \n"
         << "\t4.  Erase element from a certain position \n"
         << "\t5.  Clear \n"
         << "\t6.  Display first element \n"
         << "\t7.  Display last element \n"
         << "\t8.  Display element at certain position \n"
         << "\t9.  Display vector size \n"
         << "\t10. Display vector capacity \n"
         << "\t11. Is Empty \n"
         << "\t12. Display Elements \n"
         << "\t13. Back \n\n";
}

template <typename T>
void operationSwitch(FCI_VECTOR <T> &list)
{
    int elements; // number of elements to add

    int position; // position variable used in erase and insert functions

    T insertElement; // used in insert function

    int choice; // switch choice

    bool if_back=true; // Loop Terminator

    while(if_back)
    {
        system("cls");
        displayOperation();
        cout << "Choice : ";

        while(!(cin>>choice)) // Input Validation Loop
        {
            cout << "Your choice must be a number!" << endl;
            cin.clear();
            cin.ignore(100,'\n');
            cout << "- Choice: ";
        }

        switch(choice)
        {
            case 1: // push_back
                    cout << "- Number of elements to add : ";
                    cin >> elements;
                    list.addElement(list,elements);
                    break;
            case 2: //Remove last element.
                try
                {
                    list.pop_back();
                }
                catch (invalid_argument &e)
                {
                    cout << e.what();
                }
                break;
            case 3: // Insert element at certain position.
                cout << "- Enter the element you want to add : ";
                cin >> insertElement;
                cout << "- Enter the position do you want to insert your element : ";
                cin >> position;

                list.insert(list.begin()+position-1, insertElement);
                break;
            case 4: // Erase element from a certain position.
                cout << "- Enter the position of the element you want to erase : ";
                cin >> position;
                position--;
                try
                {
                    list.erase(list.begin()+position);
                }
                catch(out_of_range &exception)
                {
                       cout << "An exception error occurred: " << exception.what() << endl;
                }
                catch (invalid_argument &exception)
                {
                    cout << exception.what() << endl;
                }
                break;
            case 5: // Clear.
                list.clear();
                cout << "- The list has been reset" << endl;
                break;
            case 6: // Display first element.
                   try{ cout << "- First element of the list is : " << list.front() << endl;}
                   catch(invalid_argument &exception) {cout << "An exception error occurred: " << exception.what() << endl;}
                break;
            case 7: //  Display last element.
                try
                {
                    if(list.getSize()==1)
                        {
                        cout << "- Last element of the list is  : " << list.front() << endl;
                        }
                    else
                    cout << "- Last element of the list is  : " << list.back() << endl;
                }
                catch(invalid_argument &exception) {cout << "An exception error occurred: " << exception.what() << endl;}
                break;
            case 8:  //Display element at certain position.
                cout << "- Enter the position : ";
                cin >> position;
                position--;
                try
                {
                    cout << "- Value at index ( " << (position+1) << " ) is " << list[position] << endl;
                }
                catch(out_of_range &exception)
                {
                    cout << "An exception error occurred: " << exception.what() << endl;
                }
                break;
            case 9: // Display vector size.
                cout << "- Size of the list is : " << list.getSize() << endl;
                break;
            case 10: // Display vector capacity.
                cout << "- Capacity of the list is : " << list.getCapacity() << endl;
                break;
            case 11: //Is empty
                  if(list.empty()) cout << "The list is empty \n\n";
                  else cout << "- The list is not empty \n\n";
                break;
            case 12: // Print all elements in the list
                    cout << list; // using operator overloading
                break;
            case 13: // Back to main menu
                if_back=false; // Loop Terminates at case 12
                break;
            default:
                cout << "Not an Option!\n\n";
                break;
        }
    }
}

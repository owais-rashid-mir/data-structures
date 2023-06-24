/* Program to implement multiple stacks.
Suppose there is an array stack[size] and it is divided into two stacks- STACK A and STACK B, where size = 10.
STACK A expands from the left to the right, i.e., from 0th element.
STACK B expands from the right to the left, i.e., from 10th element.
*/

#include <iostream>
#include <stdlib.h>

using namespace std;

#define SIZE 10

int stack[SIZE];
int topA = -1, topB = SIZE;

// STACK A operations.
void pushIntoStackA(int val)
{
    if(topA == topB-1)
        cout << "\n Stack A is full- Stack overflow." << endl;

    else
    {
        topA += 1;
        stack[topA] = val;
    }
}

int popFromStackA()
{
    int val;

    if(topA == -1)
    {
        cout << "\n Stack A is empty- Stack underflow";
    }

    else
    {
        val = stack[topA];
        topA--;
    }
    return val;
}

void displayStackA()
{
    if(topA == -1)
        cout << "\n Stack A is empty." << endl;

    else
    {
        for(int i = topA; i >= 0; i--)
        cout << stack[i] << endl;
    }
}

// STACK B operations.
void pushIntoStackB(int val)
{
    if(topB-1 == topA)
        cout << "\n Stack B is full- Stack overflow." << endl;

    else
    {
        topB -= 1;
        stack[topB] = val;
    }
}

void popFromStackB()
{
    int val;

    if(topB == SIZE)
    {
        cout << "\n Stack B is empty- Stack underflow." << endl;
    }

    else
    {
        val = stack[topB];
        topB++;
    }
}

void displayStackB()
{
    if(topB == SIZE)
    cout << "\n Stack B is empty." << endl;

    else
    {
        for(int i = topB; i < SIZE; i++)
        cout << stack[i] << endl;
    }
}


int main()
{
    int choice, val;
    do
    {
        cout << "\nMultiple Stacks - Operations : \n \n";
        cout << "\n 1) Push an element into STACK A";
        cout << "\n 2) Push an element into STACK B";
        cout << "\n 3) Pop an element from STACK A";
        cout << "\n 4) Pop an element from STACK B";
        cout << "\n 5) Display STACK A";
        cout << "\n 6) Display STACK B";
        cout << "\n 7) Exit";

        cout << "\n Enter your choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                cout << "\n Enter a value to push into STACK A :";
                cin >> val;

                pushIntoStackA(val);
                break;

            case 2:
                cout << "\n Enter a value to push into STACK B :";
                cin >> val;

                pushIntoStackB(val);
                break;

            case 3:
                cout << "\n Popped value from STACK A = " << val;
                popFromStackA();
                break;

            case 4:
                cout << "\n Popped value from STACK B = " << val;
                popFromStackB();
                break;

            case 5:
                cout << "\n Elements in STACK A :\n";
                displayStackA();
                break;

            case 6:
                cout << "\n Elements in STACK B :\n";
                displayStackB();
                break;

            case 7:
                exit(0);
                break;

            default:
                cout <<"Invalid choice." << endl;
        }   //End of switch.
    } while(choice != 7);

    return 0;
}
//Stack implementation using a static array - Menu driven program.
#include <iostream>
#include<stdlib.h>

using namespace std;

#define SIZE 5
int ARR[SIZE];
int top = -1; //stack is empty.

int isEmpty()
{
    if(top == -1)
        return 1;

    else
        return 0;
}


void push()
{
    int value;
    cout<<"Enter an element to be inserted into the stack : \n";
    cin>>value;

    if(top == SIZE-1)
    {
        cout<<"Stack is full - Stack Overflow \n";
    }

    else
    {
        top++ ; //Because initially TOP is set to -1
        ARR[top] = value;
    }
}

void pop()
{

    if( isEmpty() )
    {
        cout<<"Stack is empty - Stack Underflow \n";
    }

    else
    {
        top-- ;
        //cout<<"Element popped \n";
    }
}

void displayStack()
{
    int i;

    if( isEmpty() )
    {
        cout<<"Stack is empty . \n ";
    }

    else
    {   cout<<"Element(s) in stack are: \n";

        for(i=0 ; i<=top ; i++)
        {
            cout<<ARR[i]<<endl;
        }
    }
}

void showTop()
{
    if( isEmpty() )
    {
        cout<<"Stack is empty . \n ";
    }

    else
    {
        cout<<"Element at top is : "<<ARR[top] <<endl;
    }
}

int main()
{

    int choice;
    do{
        cout<<"\n\n--------Menu-----------\n";
        cout<<"1. Push. \n";
        cout<<"2. Pop. \n";
        cout<<"3. Display element at Top. \n";
        cout<<"4. Display Stack. \n";
        cout<<"5. Exit \n";

        cout<<"-----------------------";
        cout<<"\nEnter your choice:\t";
        cin>>choice;

        cout<<"\n \n";

        switch(choice)
        {
            case 1:         push();
                            break;

            case 2:         pop();
                            break;

            case 3:         showTop();
                            break;

            case 4:         displayStack();
                            break;

            case 5:         exit(0);
                            break;

            default:
                            cout<<"\nInvalid choice.\n";
                            break;
        }
    }while(choice!=5);

    return 0;
}

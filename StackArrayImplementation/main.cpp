//Stack implementation using a static array
#include <iostream>

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


void push(int value)
{
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
    {
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
    push(2);
    push(3);
    push(4);
    push(5);

    //displayStack();
    pop();
    pop();

    showTop();


    displayStack();

    return 0;
}

//Queue implementation using a static array - Menu driven program.
#include <iostream>
#include<stdlib.h>

using namespace std;

#define SIZE 5
int arr[SIZE];

//rear and front = 0 , which means queue is empty.
//instead of keeping rear and front = -1, they're kept 0. when front and rear are pointing to the same
//...location, it means queue is empty.

int rear = 0;   //for element insertion
int front = 0;   //for element deletion



void enqueue()
{
    int val;
    cout<<"Enter an element to be inserted into the queue : \n";
    cin>>val;

    if(SIZE==rear)
    {
        cout<<"Queue is full. \n";
    }

    else
    {
        arr[rear] = val;
        rear++;
    }
}


void dequeue()
{

    int i;
    if(front == rear)
    {
        cout<<"Queue is empty. \n";
    }

    else
    {
        cout<<"Deleted element is : "<<arr[front]<<endl;

        //shifting to left . concept of circular queue is used
        for(i=0 ; i<rear ; i++)
        {
            arr[i] = arr[i+1];
        }
        rear-- ;
    }
}


void displayQueue()
{
    int i;

    if(front == rear)
        cout<<"Queue is empty. \n";


    else
    {
        cout<<"Elements in queue are: \n";
        for(i=0 ; i<rear ; i++)
        {
            cout<<arr[i]<<endl;
        }
    }

}


int main()
{

    int choice;
    do{
        cout<<"\n\n--------Menu-----------\n";
        cout<<"1. Enqueue - Element Insertion. \n";
        cout<<"2. Dequeue - Element deletion. \n";
        cout<<"3. Display Queue. \n";
        cout<<"4. Exit \n";

        cout<<"-----------------------";
        cout<<"\nEnter your choice:\t";
        cin>>choice;

        cout<<"\n \n";

        switch(choice)
        {
            case 1:         enqueue();
                            break;

            case 2:         dequeue();
                            break;

            case 3:         displayQueue();
                            break;

            case 4:         exit(0);
                            break;

            default:
                            cout<<"\nInvalid choice.\n";
                            break;
        }
    }while(choice!=4);

    return 0;
}

#include <iostream>

using namespace std;

#define SIZE 5
int arr[SIZE];

//rear and front = 0 , which means queue is empty.
//instead of keeping rear and front = -1, they're kept 0. when front and rear are pointing to the same
//...location, it means queue is empty.

int rear = 0;   //for element insertion
int front = 0;   //for element deletion

void enqueue(int val)
{
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
    {
        cout<<"Queue is empty. \n";
    }

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
    enqueue(1);
    enqueue(2);
    enqueue(3);

    dequeue();

    displayQueue();

    return 0;
}

#include<iostream>
#include<stdlib.h>

using namespace std;

int a[30];
int m,size,p,item,i,j,loc;

/*Function Prototype*/
void create();
void display();
void insert();
void del();

int main()
{
        int choice;
        do{
                cout<<"\n\n--------Menu-----------\n";
                cout<<"1.Create\n";
                cout<<"2.Display\n";
                cout<<"3.Insert\n";
                cout<<"4.Delete\n";

                cout<<"5.Exit\n";
                cout<<"-----------------------";
                cout<<"\nEnter your choice:\t";
                cin>>choice;


                switch(choice)
                {
                        case 1:         create();
                                        break;

                        case 2:         display();
                                        break;

                        case 3:         insert();
                                        break;

                        case 4:         del();
                                        break;

                        case 5:         exit(0);
                                        break;

                        default:        cout<<"\nInvalid choice:\n";
                                        break;
                }
        }while(choice!=5);

    return 0;
}


void create() //creating an array
{
        cout<<"\nEnter the size of the array elements: \n";
        cin>>size;

        cout<<"\nEnter the elements for the array:\n";
        for(i=0; i<size; i++)
        {
                cin>>a[i];
        }
}//end of create()


void display()  //displaying array elements
{
        int i;
        cout<<"\nThe array elements are:\n";
        for(i=0;i<size;i++)
        {
                cout<<a[i]<<"\t";
        }

 }//end of display()


void insert()   //inserting an element in to an array
{
    cout<<"\nEnter the location for the new element:\t";
    cin>>loc;

    cout<<"\nEnter the element to be inserted :\t";
    cin>>item;


    for(i=size-1; i>=loc; i--)
    {
        a[i+1] = a[i];
    }
        a[loc]=item;
        size++;

}//end of insert()


void del()      //deleting an array element
{
        cout<<"\nEnter the position of the element to be deleted:\t";
        cin>>loc;

        //val=a[pos];
        for(i=loc; i<size; i++)
        {
                a[i]=a[i+1];
        }
        //n=n-1;
        cout<<"\nThe deleted element is "<<item;
}//end of delete()

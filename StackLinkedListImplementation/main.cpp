//Here, insertion and deletion of nodes is  performed at/from one end only.
// We will insert and delete at/from FRONT end.
//IMPORTANT : YOU DON'T NEED TO CHECK THE STACK OVERFLOW CONDITIONS BECAUSE LL IS NOT
//... STATIC. THEY CAN BE EXPANDED ACCORDING TO OUR NEED. But Underflow condition is checked.

//Stack implementation using singly LL - Menu driven program.
#include <iostream>
#include<stdlib.h>

using namespace std;

struct node
{
    int data;
    struct node *link;
};
struct node *start = NULL;


struct node* createNode()
{
    struct node *n;   // 'n'pointer contains the adresss of this node
    //Instead of writing 'sizeof(structnode)' , we could've written 4 (data = 2bytes + link = 2bytes...
    //... but we are giving this task of calculation to sizeof operator.
    //(struct node *) at the beginning is a typecast.
    n=(struct node *) malloc( sizeof(struct node) );
    return(n);   //returns address of struct node type
};

void push()   //insertNodeAtFront
{
    //assume 'temp' is the new node to be added - check.
    struct node *temp;
    temp = createNode();

    cout<<"Enter a value : \n";  //we can also enter this value as an argument in push() .
    cin>>temp->data;

    if(start == NULL)   //If LL is empty
    {
        start = temp;
        start->link = NULL;
    }

    else
    {
        temp->link = start;
        start = temp;
    }

}

void pop()  //deleteNodeFirst
{
    struct node *r; // 'r' will store the value of 'start', which contains the address of first node
                    //... that is about to be deleted.

    if(start == NULL) //Checking first whether list is empty or not.if it's empty,we cannot delete anything.
    {
        cout<<"Stack (List) is empty. \n";
    }

    else
    {
        r=start;
        start = start->link;  //'start' will now contain start->link. start->link contains the address of
                              // 2nd node . So 'start' will now contain the address of 2nd node.
                              //since 'start' or any other thing is now NOT pointing towards 1st node,
                              // its reference from memory gets deleted, that is , ist node gets deleted.

        free(r);   // Further, free() is used to completely delete this node from memory.
    }

}

void displayStack()  //displayList
{
    struct node *t;  //another variable like start, since we don't want to disturb the purpose of 'start'.

    if(start==NULL) //Checking if the list is empty. If it is then we can't display anything.
    {
        cout<<"List is empty. \n";
    }

    else
    {
        t=start;  // now 't' will also point to the first node, just like 'start'.
        while(t!=NULL) //Until 't' is not equal to NULL, means until we reach last node, display/traverse all the
                        //values in the list.
        {
            cout<<t->data<<endl;
            t = t->link;  // 't' pointing to the successive nodes while printing data.
        }
    }

}


int main()
{

    int choice;
    do{
        cout<<"\n\n--------Menu-----------\n";
        cout<<"1. Push. \n";
        cout<<"2. Pop. \n";
        cout<<"3. Display Stack. \n";
        cout<<"4. Exit \n";

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

            case 3:         displayStack();
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

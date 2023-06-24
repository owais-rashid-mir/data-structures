//Here, insertion is done at Rear end (from end of the list) and deletion of nodes is done from Front end.
//IMPORTANT : YOU DON'T NEED TO CHECK THE OVERFLOW CONDITION BECAUSE LL IS NOT
//... STATIC. THEY CAN BE EXPANDED ACCORDING TO OUR NEED. But Underflow condition is checked.

//Queue implementation using singly LL - Menu driven program.
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
    struct node *n;   // 'n'pointer cdeleteNodeFirstontains the adresss of this node
    //Instead of writing 'sizeof(structnode)' , we could've written 4 (data = 2bytes + link = 2bytes...
    //... but we are giving this task of calculation to sizeof operator.
    //(struct node *) at the beginning is a typecast.
    n=(struct node *) malloc( sizeof(struct node) );
    return(n);   //returns address of struct node type
};

void enqueue()  //insertNodeAtEnd
{
    //Address in 'n' is now stored in 'temp' and 'temp' points to the node.
    struct node *temp , *t;
    temp = createNode();

    cout<<"Enter a value : \n";  //we can also enter this value as an argument in insertNodeAtEnd() .
    cin>>temp->data;

    temp->link=NULL;  //NULL because this node is to be added at the end and 'link' of last node is NULL.

    /*now we have to add this node at end of LL. There can be 2 situations. 1) there is no node in LL.
    2) LL already has some nodes */
    if(start==NULL)   //means there is no node in LL. If this is the case, put value of 'temp' into 'start' .
        start=temp;

    else   //means 'start; does not have NULL and contains address of first node... Means LL already
           // ... has some nodes and we have to add this node at the end of existing nodes.
    {
        t=start;  //Now 't' (as well as 'start')initially points to Ist node.

        while(t->link!=NULL)  // We've to check if the node to which 't' is pointing contains NULL or not.
            //...until the 'link' of node doesn't have NULL, we have to keep moving till we get NULL.
        {
            t= t->link;
        }

        //once we've got NULL, we will put value of 't->link' into 'temp'. Means that we will put the
        //address of our new node (which is in 'temp'), into the link of node that was
        //...initially the last node (last-but-one node).
        t->link = temp;
    }

}

void dequeue()  //deleteNodeFirst
{
    struct node *r; // 'r' will store the value of 'start', which contains the address of first node
                    //... that is about to be deleted.

    if(start == NULL) //Checking first whether list is empty or not.if it's empty,we cannot delete anything.
    {
        cout<<"Queue (List) is empty. \n";
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

void displayQueue()  //displayList
{
    struct node *t;  //another variable like start, since we don't want to disturb the purpose of 'start'.

    if(start==NULL) //Checking if the list is empty. If it is then we can't display anything.
    {
        cout<<"Queue (List) is empty. \n";
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
        cout<<"1. Enqueue. \n";
        cout<<"2. Dequeue. \n";
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

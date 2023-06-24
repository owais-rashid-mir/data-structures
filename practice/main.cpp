//Inserting the node at the end and deleting the first node

#include<iostream>
#include<stdlib.h>       //contains malloc() and exit()

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
    //n=(struct node *) malloc( sizeof(struct node) );
    n = new node();

    return(n);   //returns address of struct node type
};


void insertNodeAtFront()
{
    //assume 'temp' is the new node to be added - check.
    struct node *temp;
    temp = createNode();

    cout<<"Enter a value : \n";  //we can also enter this value as an argument in insertNodeAtEnd() .
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


void insertNodeAtEnd()
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


void insertNodeAtPosition()
{
    //This function doesn't work if we give position = 0 . in all the other cases, it works.
    // if there is no node, it will still ask for position. Here, enter the position = 0.

    int pos,i;
    struct node *cur;   //current
    struct node *prev;  //previous

    struct node *temp;
    temp = createNode();

    cout<<"Enter a value : \n";  //we can also enter this value as an argument in insertNodeAtEnd() .
    cin>>temp->data;

    temp->link=NULL;

    cout<<"Enter a position where you want to insert the node: \n";
    cin>>pos;

    if(start == NULL)
    {
        start = temp;
        //start->link = NULL;
    }

    else
    {
        cur = start;
        for(i=0 ; i<pos ; i++)
        {
            prev = cur;
            cur = cur->link;
        }

        prev->link = temp;
        temp->link = cur;
    }
}


void deleteNodeFirst()
{
    struct node *r; // 'r' will store the value of 'start', which contains the address of first node
                    //... that is about to be deleted.

    if(start == NULL) //Checking first whether list is empty or not.if it's empty,we cannot delete anything.
    {
        cout<<"List is empty. \n";
    }

    else
    {
        r=start;
        start = start->link;  //'start' will now contain start->link. start->link contains the address of
                              // 2nd node . So 'start' will now contain the address of 2nd node.
                              //since 'start' or any other thing is now NOT pointing towards 1st node,
                              // its reference from memory gets deleted, that is , ist node gets deleted.

        //free(r);   // Further, free() is used to completely delete this node from memory.
        delete(r);
    }

}


void deleteNodeLast()
{
    struct node *prev , *temp;

    if(start == NULL) //Scenario 1
                    //Checking first whether list is empty or not.if it's empty,we cannot delete anything.
    {
        cout<<"List is empty. \n";
    }

    else   //here we are traversing. TEMP will point to the last node and PREV will point to the last-but-one node
        // after completing WHILE iteration.
        // the last node towards which TEMP is pointing will be deleted and the node towards which PREV is pointing
        // will be set to NULL (link part of this node will be set to NULL.
    {
        temp=start;
        prev=NULL;

        while(temp->link != NULL)
        {
            prev = temp;
            temp = temp->link;
        }



        if(prev == NULL)  //Scenario 2
                            //If there's only 1 element in LL.
                        // if this is the case, while loop will not execute.. so, as previously initialised
                        //... PREV will be equal to NULL..
        {
            start = NULL;
        }

        else  //Scenario 3
             //If there're more than 1 elements in LL.
        {
            prev->link =NULL;
            //free(temp);    //TEMP was pointing to the last node. Now since we,re FREEing (deleting) TEMP, we are
                            // basically deleting this last node.

            delete(temp);
        }

    }   //end of outer ELSE


}


void deleteNodeAtPosition()
{
    //here, if you enter position =1 , 1st element will get deleted. It should have been the case when you enter
    //position = 0.... still, it is working so leave it as it is.
    int pos,i;
    struct node *temp1 = start;

    cout<<"Enter the position where from where you want to delete the node : \n";
    cin>>pos;

    if(start == NULL) //Scenario 1
                    //Checking first whether list is empty or not.if it's empty,we cannot delete anything.
    {
       cout<<"List is empty. \n";
    }

    //cout<<"Enter the position where from where you want to delete the node : \n";
    //cin>>pos;

    //struct node *temp1 = start;
    // don't write here COUTS,CINS,STRUCTS etc between IF and ELSE IF.. This program will not run then.

    else if(pos==1)  // if there is only 1 element in LL
    {
        start = temp1->link;
        //free(temp1);
        delete(temp1);
    }

    else
    {
        for(i=1 ; i<=pos-2 ; i++)
        {
            temp1 = temp1->link;
        }

        struct node *temp2 = temp1->link;
        temp1->link = temp2->link;
        //free(temp2);
        delete(temp2);
    }


}




void displayList()
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
        cout<<"1. Insert a node at the front. \n";
        cout<<"2. Insert a node at the end. \n";
        cout<<"3. Insert a node at a specific position. \n";

        cout<<"4. Delete the first node. \n";
        cout<<"5. Delete the last node. \n";
        cout<<"6. Delete a node at a specific position. \n";

        cout<<"7. Display the list. \n";

        cout<<"8. Exit \n";

        cout<<"-----------------------";
        cout<<"\nEnter your choice:\t";
        cin>>choice;

        cout<<"\n \n";

        switch(choice)
        {
            case 1:         insertNodeAtFront();
                            break;

            case 2:         insertNodeAtEnd();
                            break;

            case 3:         insertNodeAtPosition();
                            break;

            case 4:         deleteNodeFirst();
                            break;

            case 5:         deleteNodeLast();
                            break;

            case 6:         deleteNodeAtPosition();
                            break;

            case 7:         displayList();
                            break;

            case 8:         exit(0);
                            break;

            default:
                            cout<<"\nInvalid choice.\n";
                            break;
        }
    }while(choice!=8);


    return 0;
}

//Inserting element at the beginning of array
#include <iostream>

using namespace std;

int main()
{

    int a[30],size,i,item;

    cout<<"Enter the size of the array: \n";
    cin>>size;

    cout<<"Enter array elements: \n";
    for(i=0 ; i<size ; i++)
    {
        cin>>a[i];
    }

    cout<<"Enter the new element which you want to insert at the beginning of the array: \n";
    cin>>item;

    for(i=size-1 ; i>=0 ; i--)
    {
        a[i+1] = a[i];
    }
    a[0] = item;

    cout<<endl;
    for(i=0 ; i<=size ; i++)
    {

        cout<<a[i]<<endl;
    }




    return 0;
}

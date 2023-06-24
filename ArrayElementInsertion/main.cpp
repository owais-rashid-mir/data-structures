#include <iostream>

using namespace std;

int main()
{

    int a[30],size,i,item, loc;

    cout<<"Enter the size of the array: \n";
    cin>>size;

    cout<<"Enter array elements: \n";
    for(i=0 ; i<size ; i++)
    {
        cin>>a[i];
    }

    cout<<"Enter the location where you want to insert the new element: \n";
    cin>>loc;

    cout<<"Enter the new element which you want to insert in the array: \n";
    cin>>item;

    for(i=size-1 ; i>=loc ; i--)
    {
        a[i+1] = a[i];
    }
    a[loc] = item;

    for(i=0 ; i<=size ; i++)
    {

        cout<<a[i]<<endl;
    }




    return 0;
}

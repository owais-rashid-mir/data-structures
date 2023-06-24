#include <iostream>

using namespace std;

int main()
{

    int a[30],size,i,loc;

    cout<<"Enter the size of the array: \n";
    cin>>size;

    cout<<"Enter array elements: \n";
    for(i=0 ; i<size ; i++)
    {
        cin>>a[i];
    }

    cout<<"Enter the location from where you want to delete any existing element: \n";
    cin>>loc;


    for(i=loc ; i<size-1;i++)
    {
       a[i] = a[i+1];
    }


    for(i=0 ; i<size-1 ; i++)
    {

        cout<<a[i]<<endl;
    }


    return 0;
}

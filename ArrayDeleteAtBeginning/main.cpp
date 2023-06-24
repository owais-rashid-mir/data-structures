#include <iostream>

using namespace std;

int main()
{

    int a[30],size,i;

    cout<<"Enter the size of the array: \n";
    cin>>size;

    cout<<"Enter array elements: \n";
    for(i=0 ; i<size ; i++)
    {
        cin>>a[i];
    }


    for(i=0 ; i<size-1;i++)
    {
       a[i] = a[i+1];
    }

    cout<<endl;
    cout<<"After deleting the first element, the array is: \n";
    for(i=0 ; i<size-1 ; i++)
    {

        cout<<a[i]<<endl;
    }


    return 0;
}

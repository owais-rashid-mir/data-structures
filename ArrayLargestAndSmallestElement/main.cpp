#include <iostream>

using namespace std;

int main()
{

    int a[30],size,i,large,small;

    cout<<"Enter the size of the array: \n";
    cin>>size;

    cout<<"Enter array elements: \n";
    for(i=0 ; i<size ; i++)
    {
        cin>>a[i];
    }

    small = a[0];
    large = a[0];


    for(i=1 ; i<size ; i++)
    {
        if(a[i] < small)
        {
            small= a[i];
        }

        if(a[i] > large)
        {
            large= a[i];
        }

    }

    cout<<"Largest element in array : "<<large<<endl;
    cout<<"Smallest element in array : "<<small<<endl;




    return 0;
}

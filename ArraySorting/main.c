#include<stdio.h>

int main()
{
    int arr[20], i,j,n,temp;

    printf("Enter no. of elements: \n");
    scanf("%d" ,&n);

    printf("Enter elements: \n");
    for(i=0 ; i<n ; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Entered elements are: \n");
    for(i=0 ; i<n ; i++)
    {
        printf("%d\n", arr[i]);
    }

    //Sorting
    for(i=0 ; i<n ; i++)
    {
        for(j=i+1 ; j<n ; j++)
        {
            if(arr[j] < arr[i])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    printf("Sorted Array : \n");
    for(i=0 ; i<n ; i++)
    {
        printf("%d\n", arr[i]);
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arr[20],item,n,i,loc=0;

    printf("Enter the number of elements: \n");
    scanf("%d", &n);

    printf("Enter elements: \n");
    for(i=0 ; i<n ; i++)
    {
        scanf("%d",&arr[i]);
    }

    printf("Entered elements are: \n");
    for(i=0 ; i<n ; i++)
    {
        printf("%d\n",arr[i]);
    }

    printf("Enter the element to be searched: \n");
    scanf("%d", &item);

    for(i=0 ; i<n ;i++)
    {
        if(arr[i] == item)
        {
            loc = i+1;
            break;
        }
    }

    if(loc > 0)
        printf("%d is present at location %d \n", item,loc);

    else
        printf("Element is not present.\n");


    return 0;
}

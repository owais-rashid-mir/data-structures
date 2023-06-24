#include<stdio.h>

int main()
{
    int arr[5];
    int i;

    printf("Enter elements: \n");
    for(i=0 ; i<5 ; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("The entered elements are: \n");
    for(i=0 ; i<5 ; i++)
    {
        printf("%d\n", arr[i]);
    }

    return 0;

}

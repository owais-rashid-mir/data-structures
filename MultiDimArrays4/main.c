#include<stdio.h>

int main()
{
    int arr[2][3];
    int i,j;

    printf("Enter elements: \n");
    for(i=0 ; i<2 ; i++)
    {
        for(j=0 ; j<3 ; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    printf("The entered elements are: \n");
    for(i=0 ; i<=1; i++)
    {
        for(j=0 ; j<=2; j++)
        {
            printf("%d \t", arr[i][j]);
        }
        printf("\n");
    }


    return 0;

}

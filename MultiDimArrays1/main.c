#include<stdio.h>

int main()
{
    int arr[2][3];

    arr[0][0] = 10;
    arr[1][2] = 16;

    printf("%d\n", arr[0][0]);
    printf("%d\n", arr[1][2]);

    return 0;
}

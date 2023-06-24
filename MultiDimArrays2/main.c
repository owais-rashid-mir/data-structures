#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arr[2][3] = {
                        {1,2,3},
                        {4,5,6}
                    };

    printf("%d\n", arr[0][0]);   //prints 1
    printf("%d\n", arr[1][1]);   //prints 5
    printf("%d\n", arr[1][0]);    //prints 4

    return 0;
}

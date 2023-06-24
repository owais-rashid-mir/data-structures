#include<stdio.h>

int main()
{
    //Keep the 2 dimensions of 'mat' and 'tp' same, otherwise it doesn't work properly
    int mat[3][3] , tp[3][3];   //tp = transpose;
    int i,j;

    printf("Enter elements for the Matrix : \n");
    for(i=0; i<3 ; i++)
    {
        for(j=0 ; j<3 ; j++)
        {
            scanf("%d",&mat[i][j]);
        }
    }



    printf("Entered elements in Matrix 1:\n" );
    for(i=0; i<3 ; i++)
    {
        for(j=0 ; j<3 ; j++)
        {
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }

    printf("\n");


    //Transposing the Matrix
    for(i=0; i<3 ; i++)
    {
        for(j=0 ; j<3 ; j++)
        {
            tp[j][i] = mat[i][j];
        }

    }


    printf("The transpose of the Matrix = \n");
    for(i=0; i<3 ; i++)
    {
        for(j=0 ; j<3 ; j++)
        {
            printf("%d\t", tp[i][j]);
        }
        printf("\n");
    }



    return 0;
}

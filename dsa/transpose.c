// WAP to find the transpose of sparse matrix ( input - row major , output - column major )

#include<stdio.h>

main()
{
    int rowmaj[100][3],colmaj[60][3],row,i,j,k=1;

    printf("enter total number of rows in the row major matrix : ");
    scanf("%d",&row);

    //input to row major matrix
    printf("enter the values to the matrix : \n");
    for(i=0;i<row;i++)
    {
        for(j=0;j<3;j++)
        {
            scanf("%d",&rowmaj[i][j]);
        }
    }

    //display the row major matrix
    printf("\nvalues are\n");
    for(i=0;i<row;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%d ",rowmaj[i][j]);
        }
        printf("\n");
    }

    //convert to column major matrix
    colmaj[0][0]=rowmaj[0][1];
    colmaj[0][1]=rowmaj[0][0];
    colmaj[0][2]=rowmaj[0][2];

    for(i=0;i<colmaj[0][0];i++)
    {
        for(j=1;j<=colmaj[0][2];j++)
        {
            if(rowmaj[j][1]==i)
            {
                colmaj[k][0]=rowmaj[j][1];
                colmaj[k][1]=rowmaj[j][0];
                colmaj[k][2]=rowmaj[j][2];
                k++;
            }
        }
    }


    //display the column major matrix
    printf("\nvalue of column major matrix\n");

    for(i=0;i<row;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%d ",colmaj[i][j]);
        }
        printf("\n");
    }
}

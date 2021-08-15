/*WAP to convert a sparse matrix into row major triplet format */
#include<stdio.h>
void main()
{
    int sparse[30][20],rowmajor[60][3],row,col,i,j,nzero=0,temp=1;
    printf("Enter total rows and column: ");
    scanf("%d%d",&row,&col);
    printf("Enter value: ");
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            scanf("%d",&sparse[i][j]);
        }
    }
    printf("\nValues are:\n");
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            printf("%d\t",sparse[i][j]);
        }
        printf("\n");
    }

    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            if(sparse[i][j]!=0)
            {
                nzero++;
            }
        }
    }
    rowmajor[0][0]=row;
    rowmajor[0][1]=col;
    rowmajor[0][2]=nzero;
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            if(sparse[i][j]!=0)
            {
                rowmajor[temp][0]=i;
                rowmajor[temp][1]=j;
                rowmajor[temp][2]=sparse[i][j];
                temp++;
            }
        }
    }
    printf("\nValues of Triplet Matrix are:\n");
    for(i=0;i<=nzero;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%d\t",rowmajor[i][j]);
        }
        printf("\n");
    }
}

/*WAP to convert a sparse matrix into column  major triplet format */
#include<stdio.h>
void main()
{
    int sparse[30][20],resultant[60][3],row,col,i,j,nzero=0,k=1;
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
    for(j=0;j<col;j++)
    {
        for(i=0;i<row;i++)
        {
            if(sparse[i][j]!=0)
            {
                nzero++;
            }
        }
    }
    resultant[0][0]=col;
    resultant[0][1]=row;
    resultant[0][2]=nzero;
    for(j=0;j<col;j++)
    {
        for(i=0;i<row;i++)
        {
            if(sparse[i][j]!=0)
            {
                resultant[k][0]=j;
                resultant[k][1]=i;
                resultant[k][2]=sparse[i][j];
                k++;
            }
        }
    }
    printf("\nValues of Triplet Matrix are:\n");
    for(i=0;i<=nzero;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%d\t",resultant[i][j]);
        }
        printf("\n");
    }
}

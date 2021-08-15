//wap to transpose row major to column major
#include<stdio.h>
int main()
{
 int rowmaj[100][3],colmaj[60][3],row;
 int i,j,k=1;
 printf("Enter the number of rows: ");
 scanf("%d",&row);
 printf("The elements in the matrix are: \n");
 for(i=0;i<row;i++)
 {
 for(j=0;j<3;j++)
 {
 scanf("%d",&rowmaj[i][j]);
 }
 }
 printf("\nValues are\n");
 for(i=0;i<row;i++)
 {
 for(j=0;j<3;j++)
 {
 printf("%d ",rowmaj[i][j]);
 }
 printf("\n");
 }
 colmaj[0][0]=rowmaj[0][1];
 colmaj[0][1]=rowmaj[0][0];
 colmaj[0][2]=rowmaj[0][2];
 for(i=0;i<colmaj[0][0];i++){
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
 printf("\nThe coloumn major matrix is \n");
 for(i=0;i<row;i++)
 {
 for(j=0;j<3;j++)
 {
 printf("%d ",colmaj[i][j]);
 }
 printf("\n");
 }
}

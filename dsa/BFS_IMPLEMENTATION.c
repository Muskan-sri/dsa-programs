//BFS IMPLEMENTATION
#include<stdio.h>
#include<stdlib.h>
void BFS(int);
int graph[10][10],visited[10],total;
main()
{
int i,j;
printf("\n enter the total number of vertices in graph\t");
scanf("%d",&total);
//ADJENCY MATRIX OUTPUT
printf("\nenter the adjency matrix----\n");
for(i=0;i<total;i++)
{
for(j=0;j<total;j++)
{
scanf("%d",&graph[i][j]);
}
}
for(i=0;i<total;i++)
{
visited[i] =0;
}
BFS(0);
}
void BFS(int vertex)
{
    int j;
    printf("%d\t",vertex);
    visited[vertex] = 1;
    for(j=0;j<total;j++)
    {


        if(!visited[j] && graph[vertex][j] == 1)
    {
        BFS(j);
    }
    }
}

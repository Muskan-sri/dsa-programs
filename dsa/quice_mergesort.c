//SORTIBG USING QUICK AND MERGE SORT
#include<stdio.h>
#include<stdlib.h>
int arr[100],size;
void input();
void display();
void quicksort(int arr[], int left,int right);
void mergesort(int A[],int low,int high);
int merge(int A[], int mid, int low, int high);
int partition(int arr[],int left,int right);
void main()
{
    int choice;
    while(1)
    {
        printf("ENTER \n1 QUICK SORT\n2 MERGE SORT\n3 EXIT\n");
        printf("\nEnter choice\t: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1: input();
                quicksort(arr,0,size-1);
                break;
            case 2: input();
                mergesort(arr,0,size-1);
                break;
            case 3:exit(0);
            default: printf("wrong choice");
        }
        display();
    }
}

void input()
{
    int i;
    printf("\nEnter size of array : ---\t");
    scanf("%d",&size);

    printf("\nEnter the elements of array : -------\n");
    for(i=0;i<size;i++)
    {
        scanf("%d",&arr[i]);
    }
}

void display()
{
    printf("\n------The sorted array is ---------: \n");
    for(int i=0;i<size;i++)
    {
        printf("%d \t", arr[i]);
    }
    printf("\n");
}
void quicksort(int arr[], int left,int right)
{
    int pospivot;
    if(left<right)
    {
        pospivot= partition(arr,left,right);
        quicksort(arr,left,pospivot-1);
        quicksort(arr,pospivot+1,right);
    }
}
int partition(int arr[],int left,int right)
{
    int pivot,i,j,temp;
    j=left;
    i=j-1;
    pivot=arr[right];
    while(j<right)
    {
        if(arr[j]<=arr[right])
        {
            i++;
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
        j++;
    }
    temp=arr[i+1];
    arr[i+1]=arr[right];
    arr[right]=temp;
    return i+1;
}
int merge(int A[], int mid, int low, int high)
{
    int i,j,k,B[100];
    i=low;
    j=mid+1;
    k=low;

    while(i<=mid && j<=high)
    {
        if(A[i]<=A[j])
        {
            B[k]=A[i];
            i++;
        }
        else
        {
            B[k]=A[j];
            j++;
        }
        k++;
    }
    while(i<=mid)
    {
        B[k]=A[i];
        k++;
        i++;
    }
    while(j<=high)
    {
        B[k]=A[j];
        k++;
        j++;
    }
    for(i=low;i<=high;i++)
    {
        A[i]=B[i];
    }
}
void mergesort(int A[],int low,int high)
{
    int mid;
    if(low<high)
    {
        mid=(low+high)/2;
        mergesort(A,low,mid);
        mergesort(A,mid+1,high);
        merge(A,mid,low,high);
    }
}

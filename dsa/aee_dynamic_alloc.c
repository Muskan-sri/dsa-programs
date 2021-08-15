//array operations using dynamic memory allocation --INSERT --DELETE --LINEAR SEARCH --MIN --MAX

#include<stdio.h>
#include<stdlib.h>

main()
{
    int *arr;
    int size,choice,i;

    printf("\nenter the size : ");
    scanf("%d",&size);
    arr= (int *)malloc(size * sizeof(int));    //memory allocated to array

    if(arr==NULL)
    {
        printf("No memory allocated\n");
        exit(0);
    }

    printf("enter the numbers : \n");
    for(i=0;i<size;i++)
        scanf(" %d",&arr[i]);

    printf("\n1 INSERT \n2 DELETE \n3 LINEAR SEARCH \n4 DISPLAY \n5 MINIMUM \n6 MAXIMUM \n7 EXIT\n");
    while(1)
    {
        printf("\nEnter choice : ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1: insert(arr,&size);
                break;
            case 2: delete(arr,&size);
                break;
            case 3: search(arr,size);
                break;
            case 4: display(arr,size);
                break;
            case 5: min(arr,size);
                break;
            case 6: max(arr,size);
                break;
            case 7: exit(0);
            default: "Wrong choice";
        }
    };
    free(arr);
}

void min(int *arr,int n)
{
    int i,j;
    int min=*arr;

    for(i=1;i<n;i++)
    {
        if(min>*(arr+i))
        {
            min=*(arr+i);
        }
    }
    printf("The minimum element is %d\n",min);
}

void max(int *arr,int n)
{
    int i,j;
    int max=*arr;

    for(i=1;i<n;i++)
    {
        if(max<*(arr+i))
        {
            max=*(arr+i);
        }
    }
    printf("The maximum element is %d\n",max);
}

void display(int *arr,int n)
{
    if(n==0)
    {
        printf("Empty array !");
    }
    else
    {
        printf("the elements are : ");
        for(int i=0;i<n;i++)
        {
            printf("%d  ",*(arr+i));
        }
    }
}

void insert(int *arr,int *n)
{
    int index,ele;
    ele=(int *)malloc(sizeof(int));

    printf("\nEnter the element to be inserted : ");
    scanf("%d",&ele);
    printf("Enter the index of element : ");
    scanf("%d",&index);

    *n=*n+1;
    for(int i=*n-1; i>=index; i--)
    {
        (arr+(i+1))==(arr+i);
    }
    *(arr+index)=ele;
    printf("Element insertion successful\n");
}

void delete(int *arr,int *n)
{
    int index;
    printf("Enter the index to be deleted : ");
    scanf("%d",&index);

    if(*n==0)
    {
        printf("Empty array !\n");
        return 1;
    }
    else if(index>=*n)
    {
        printf("Index not present !\n");
    }
    else
    {
        for(int i=index;i<*n;i++)
        {
            (arr+i)==(arr+i+1);
        }
        printf("Element deletion successful\n");
        *n=*n-1;
    }
}

void search(int *arr,int n)
{
    int i,key;
    printf("Enter the element to be searched : ");
    scanf("%d",&key);

    for(i=0;i<n;i++)
    {
        if(*(arr+i)==key)
        {
            printf("Element is found at index %d",i);
            return 0;
        }
    }
    if(i==n)
    {
        printf("Element not found !");
    }
}

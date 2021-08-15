/*sorting using dynamic memory allocation*/
#include <stdio.h>
#include <stdlib.h>
void bubble();
void selection();
void insertion();
void input();
void display();
int *ptr,size;
int main()
{
    while(1)
    {
        int choice;
        printf("\n1-Bubble sort\n2-Selection Sort\n3-Insertion sort\n4-Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                input();
                bubble();
                display();
                break;
            case 2:
                input();
                selection();
                display();
                break;
            case 3:
                input();
                insertion();
                display();
                break;
            case 4:
                exit(0);
                break;
                break;
            default:
                printf("Wrong Choice");
                break;
        }
    }
}
void input()
{
    int i;
    printf("Enter the size of the array you want to create\n");
    scanf("%d", &size);
    ptr = (int *)malloc(size*sizeof(int));
    printf("How many blocks you will use: \n");
    for (i = 0; i < size; i++)
    {
        scanf("%d", ptr + i);
    }
}
void display()
{
    printf("After sorting the array is: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", *(ptr + i));
    }

}
void bubble()
{
    int i, j, temp;
    for (i = 0; i < size-1; i++)
    {
        for (j = 0; j < size - i - 1; j++)
        {
            if (*(ptr + j) > *(ptr + j + 1))
            {
                temp = *(ptr + j);
                *(ptr + j) = *(ptr + j + 1);
                *(ptr + j + 1) = temp;
            }
        }
    }
}
void insertion()
{
    int key,j,i;
    for(i=1; i<size; i++)
    {
        key = *(ptr+i);
        j= i-1;
        while(j>=0 && *(ptr+j)>=key)
        {
            *(ptr+j+1) = *(ptr+j);
            j = j-1;
        }
        *(ptr+j+1) = key;
    }
}
void selection()
{
    int min, i, j, temp;
    for (i = 0; i < size; i++)
    {
        min = i;
        for (j = i + 1; j < size; j++)
        {
            if (*(ptr+j) < *(ptr+min))
            {
                min = j;
            }
        }
        if (i != min)
        {
            temp = *(ptr + i);
            *(ptr + i) = *(ptr + min);
            *(ptr + min) = temp;
        }
    }
}

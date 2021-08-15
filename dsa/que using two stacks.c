
#include <stdio.h>
#include <stdlib.h>

void insert();
void delete();
void display();
int stack1[50],stack2[50],top1 = -1,top2 = -1,size;
int main()
{
    int choice;
    printf("Enter size of Queue: ");
    scanf("%d",&size);

    printf("\n1 INSERT\n2 DELETE\n3 DISPLAY\n4 EXIT\n");
    while(1)
    {
        printf("\nenter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: insert();
                break;
            case 2: delete();
                break;
            case 3: display();
                break;
            case 4: exit(0);
            default: printf("Wrong Choice");
        }
    }
}

void insert()
{
    if(top1== size-1)
    {
        printf("\nQueue Overflow");
    }
    else
    {
        top1++;
        printf("Enter item to be inserted: ");
        scanf("%d",&stack1[top1]);
    }
}

void delete()
{
    if(top1== -1)
    {
        printf("\nQueue Underflow");
    }
    else
    {
        while(top1 != -1)
        {
            top2++;
            stack2[top2] = stack1[top1];
            top1--;
        }
        printf("\nDeleted value: %d",stack2[top2]);
        top2--;
        while(top2!= -1)
        {
            top1++;
            stack1[top1] = stack2[top2];
            top2--;
        }
    }
}

void display()
{
    int i;
    if(top1== -1)
    {
        printf("\nQueue Underflow");
    }
    else
    {
        printf("\nQueue is :\n");
        for(i=0;i <= top1;i++)
        {
            printf("%d\n",stack1[i]);
        }
    }
}

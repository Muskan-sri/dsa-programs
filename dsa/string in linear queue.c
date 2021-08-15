//STRING USING LIMEAR QUEUE
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void insert();
void delete();
void display();
char queue[40][40];
int size,front=-1,rear=-1;

main()
{
    int choice;
    printf("Enter the size of queue : ");
    scanf("%d",&size);

    while(1)
    {
        printf("\n1 INSERT\n2 DELETE\n3 DISPLAY\n4 EXIT\n");
        printf("enter your choice : ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                insert();
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("wrong input\n");
        }
    }
}

void insert()
{
    char item[50];
    int size;
    if(rear==size-1)
    {
        printf("queue overflow\n");
    }
    else
    {
        printf("Enter item : ");
        scanf("%s",item);
        if(rear==-1)
        {
            rear=rear+1;
            front=front+1;
        }
        else
        {
            rear=rear+1;
        }
        strcpy(queue[rear],item);
    }
}

void delete()
{
    char item[30];
    if(front==-1)
    {
        printf("queue underflow\n");
    }
    else
    {

        strcpy(item,queue[front]);
        if(front==rear)
        {
            front=-1;
            rear=-1;
        }
        else
        {
            front=front+1;
        }
        printf("deleted value= %s\n",item);
    }
}

void display()
{
    int index;
    if(front==-1 || front==rear+1)
    {
        printf("queue underflow\n");
    }
    else
    {
        printf("the values of queue :\n");
        index=front;
        while(index<=rear)
        {
            printf("%s\n",queue[index]);
            index=index+1;
        }
    }
}

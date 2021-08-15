//Linear Queue operations using array -- insert -- delete -- display
#include<stdio.h>
#include<stdlib.h>

void insert();
void delete();
void display();
int queue[20],size,front=-1,rear=-1;

main()
{
    int choice;
    printf("enter the size of queue : ");
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
                printf("wrong choice\n");
        }
    }
}

void insert()
{
    int item;
    if(rear==size-1)
    {
        printf("queue overflow\n");
    }
    else
    {
        printf("enter item : ");
        scanf("%d",&item);
        if(rear==-1)
        {
            rear=rear+1;
            front=front+1;
        }
        else
        {
            rear=rear+1;
        }
        queue[rear]=item;
    }
}

void delete()
{
    int item;
    if(front==-1)
    {
        printf("queue underflow\n");
    }
    else
    {
        item=queue[front];
        if(front==rear)
        {
            front=-1;
            rear=-1;
        }
        else
        {
            front=front+1;
        }
        printf("deleted value= %d\n",item);
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
            printf("%d\n",queue[index]);
            index=index+1;
        }
    }
}

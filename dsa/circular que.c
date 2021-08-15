/*CIRCULAR QUEUE IMPLEMENTATION*/
#include<stdio.h>
#include<stdlib.h>
void insert();
void delete();
void display();
int queue[30],front=-1,rear=-1,size;
int main()
{
   int choice;
   printf("enter the size of queue:");
   scanf("%d",&size);
   while(1)
   {
     printf("\n1.INSERT\n 2.DELETE\n 3.DISPLAY\n4.EXIT\n");
     printf("enter your choice:");
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
        default: printf("WRONG CHOICE");
     }
    }
}
void insert()
{
  int item;
  if(rear==size-1 && front==0 || front==rear+1)
  {
      printf("QUEUE OVERFLOW");
  }
  else
  {
    printf("enter the number you want to enter into the queue:");
    scanf("%d",&item);
    if(rear==-1)
    {
      front = 0;
      rear = 0;
    }
   else if(rear==size-1)
   {
       rear=0;
   }
   else
    rear=rear+1;
    queue[rear]=item;
  }
}

void display()
{
  int index;
  if(front==-1)
  {
      printf("QUEUE IS EMPTY");
      return;
  }
  printf("\n elements are:\n");
  if(rear>=front)
  {
    for(index=front;index<=rear;index++)
    {
       printf("%d ",queue[index]);
    }
  }
    else
    {
        for(index=front;index<size;index++)
            printf("%d ",queue[index]);
        for(index=0;index<=rear;index++)
            printf("%d ",queue[index]);

    }

}
void delete ()
{
    int item;
    if (front == -1)
    {
        printf("Stack underflow");
    }
    else
    {
        item = queue[front];
        printf("The deleted value is : %d", item);
        if (front == rear)
        {
            rear = -1;
            front = -1;
        }
        else
        {
            if (front == size - 1)
            {
                front = 0;
            }
            else
                front++;
        }
    }
}

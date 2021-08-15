/*WAP OF CIRCULAR QUEUE USING STRUCTURE*/
#include<stdio.h>
#include<stdlib.h>
struct cqueue
{
int queue[50];
int size,front,rear;
}cq;
void insert();
void delete();
void display();
int queue[30],front=-1,rear=-1,size;
int main()
{
   int choice;
   cq.rear=-1;
   cq.front=-1;

   printf("enter the size of queue:");
   scanf("%d",&cq.size);
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
  if(cq.rear==cq.size-1 && cq.front==0 || cq.front==cq.rear+1)
  {
      printf("QUEUE OVERFLOW");
  }
  else
  {
    printf("enter the number you want to enter into the queue:");
    scanf("%d",&item);
    if(cq.rear==-1)
    {
      cq.front = 0;
      cq.rear = 0;
    }
   else if(cq.rear==cq.size-1)
   {
       cq.rear=0;
   }
   else
    cq.rear=cq.rear+1;
    cq.queue[cq.rear]=item;
  }
}

void display()
{
  int index;
  if(cq.front==-1)
  {
      printf("QUEUE IS EMPTY");
      return;
  }
  printf("\n elements are:\n");
  if(cq.rear>=cq.front)
  {
    for(index=cq.front;index<=cq.rear;index++)
    {
       printf("%d ",cq.queue[index]);
    }
  }
    else
    {
        for(index=cq.front;index<cq.size;index++)
            printf("%d ",cq.queue[index]);
        for(index=0;index<=cq.rear;index++)
            printf("%d ",cq.queue[index]);

    }

}
void delete ()
{
    int item;
    if (cq.front == -1)
    {
        printf("Stack underflow");
    }
    else
    {
        item = cq.queue[cq.front];
        printf("The deleted value is : %d", item);
        if (cq.front == cq.rear)
        {
            cq.rear = -1;
            cq.front = -1;
        }
        else
        {
            if (cq.front == cq.size - 1)
            {
                cq.front = 0;
            }
            else
                cq.front++;
        }
    }
}

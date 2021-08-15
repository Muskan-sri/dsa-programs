/*write a program to implement linear  queue using structure */
#include<stdio.h>
#include<stdlib.h>
struct queue{
  int queue[30];
  int front;
  int rear;
  int size;
}st;
void insert();
void delete();
void display();
int main()
{
   int choice;
   printf("Enter the size of queue: ");
   scanf("%d",&st.size);
   st.front=-1;
   st.rear=-1;
   while(1)
   {
     printf("\n1.Insert\n 2.Delete\n 3.Display\n4.Exit\n");
     printf("Enter your choice: ");
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
  if(st.rear==st.size-1)
  {
      printf("QUEUE OVERFLOW");
  }
  else
  {
    printf("enter the number you want to enter into the queue:");
    scanf("%d",&item);
    if(st.rear==-1)
    {
      st.front++;
    }
    st.rear++;
    st.queue[st.rear]=item;
  }
}
void delete()
{
  if((st.front==st.rear+1)||(st.front==-1))
  {
      printf("QUEUE UNDERFLOW");
  }
  else
  {
    printf("the deleted item=%d",st.queue[st.front]);
    st.front++;
  }
}
void display()
{
  int index;
  if((st.front==st.rear+1)||(st.front==-1))
  {
      printf("QUEUE UNDERFLOW");
  }
  else
  {
    printf("The queue is:");
    for(index=st.front;index<=st.rear;index++)
    {
       printf("%d ",st.queue[index]);
    }
  }
}

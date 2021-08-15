//stack using structure
#include<stdio.h>
void push();
void pop();
void peep();
void display();
struct stack
{
     int top;
     int size;
     int arr[30];
};
struct stack st;
main()
{
     int choice;
     printf("Enter the size of the stack:");
     scanf("%d",&st.size);
     st.top=-1;
     while(1)
     {
     printf("\n1.PUSH \n2.POP \n3.PEEP \n4.DISPLAY \n");
     printf("Enter your choice:");
     scanf("%d",&choice);
     switch(choice)
     {
         case 1: push();
             break;
         case 2: pop();
             break;
         case 3: peep();
              break;
         case 4: display();
              break;
         default:printf("Wrong choice");
         }
         }
}
void push()
{
       int item;
       printf("Enter a number to be inserted");
       scanf("%d",&item);
       if(st.top==st.size-1)
       {
           printf("Size overflow");
        }
        else
        {
            st.top++;
            st.arr[st.top]=item;
            }
            }
void pop()
{
         int item;
         if(st.top==-1)
         {
             printf("Size underflow");
          }
          else
          {
               item=st.arr[st.top];
               st.top--;
               printf("popped item=%d",item);
               }
               }
void peep()
{
           int item;
           if(st.top==-1)
           {
               printf("Size underflow");
            }
            else
            {
                printf("%d",st.arr[st.top]);
            }
}
void display()
{
        int index;
        if(st.top==-1)
        {
            printf("Stack underflow");
        }
        else
        {
             printf("\nvalues of stack are:");
             for(index=st.top;index>-1;index--)
             {
                 printf("%d\t",st.arr[index]);
             }
       }
}

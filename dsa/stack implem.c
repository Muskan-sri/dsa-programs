/*wap to implement stack usin g array*/
#include<stdio.h>
#include<stdlib.h>
int stack[50],top=-1,size;
void push();
void pop();
void peep();
void display();

main()
{

    int choice;
    printf("enter the size of the stack");
    scanf("%d",&size);

    while(1)
    {

        printf("\nenter the choice\n1:push\n2:pop\n3:peep\n4 display");
        scanf("%d",&choice);
        switch (choice)
        {

        case 1: push();
        break;
        case 2: pop();
        break;
        case 3: peep();
        break;

        case 4: display();
        break;
        case 5: exit(0);
        default : printf("invalid choice");

        }
    }
}
void push()
{

    int item;
    if (top==size-1)
    {
        printf("\nstack overflow");

    }
    else{
        printf("enter value to push\n");
        scanf("%d",&item);
        top++;
        stack[top]=item;

    }
}
void pop()
{

    if(top==-1)
    {
        printf("stack underflow\n");

    }
    else
    {
        printf("\npopped item =%d",stack[top]);
    top--;


    }
}
void peep()
{

    if (top==-1)
    {

        printf("stack is empty");

    }
    else{
        printf("%d\tis the top element",stack[top]);

    }
}

void display()
{

    int index;
    if(top==-1)
    {

        printf("stack under flow");

    }
    else{
        printf("\nelements of stack\n");
        for(index=top;index>=0;index--)
        {

            printf("%d\t",stack[index]);

        }
    }
}

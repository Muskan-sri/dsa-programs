//DECIMAL TO octal/
#include<stdio.h>
int stack[30],top=-1;
void push(int);
int pop();
int main()
{
    int no,rem;
    printf("Enter the value: ");
    scanf("%d",&no);
    while(no!=0)
    {
        rem=no%8;
        push(rem);
        no=no/8;
    }
    while(top!=-1)
    {
        printf("%d ", pop());
        top--;
    }
}
    void push(int item)
    {
        top++;
        stack[top]=item;
    }

    int pop()
    {
        return(stack[top]);
    }

//hexadecimal
#include<stdio.h>
int stack[30],top=-1;
void push(int);
int pop();
int main()
{
    int no,rem,x;
    printf("Enter number in decimal: ");
    scanf("%d",&no);
    while(no!=0)
    {
        rem=no%16;
        push(rem);
        no=no/16;
    }
    while(top!=-1)
    {
        x=pop();
        if (x==10)
            printf("%c",'A');
        else if (x==11)
            printf("%c",'B');
        else if (x==12)
            printf("%c",'C');
        else if (x==13)
            printf("%c",'D');
        else if(x==14)
            printf("%c",'E');
        else if (x==15)
            printf("%c",'F');
        else
            printf("%d",x);
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

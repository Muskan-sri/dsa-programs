/*REVERSE STRING USING STSCK*/
#include<stdio.h>
char stack[30];
int top=-1;
char pop();
void push(char);
int main()
{
    char name[30];
    int index=0;
    printf("Enter your name: ");
    scanf("%[^\n]",name);
    while(name[index]!='\0')
    {
        push(name[index]);
        index++;
    }
    while(top!=-1)
    {
        printf("%c",pop());
        top--;
    }
}
void push(char item)
{
    top++;
    stack[top]=item;
}
char pop()
{
    return(stack[top]);
}

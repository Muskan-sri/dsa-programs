#include<stdio.h>
long int stack[30],fac=1;
int top=-1;
void push(int);
int pop();
main()
{
    int num;
    printf("enter the number:");
    scanf("%d",&num);
    while(num!=0)
    {

        push(num);
        num--;

    }
    while(top!=1)
          {

              fac=fac*pop();
              top--;

          }
          printf("the factorial of the number is %ld");

}
            void push(int item)
            {

                top++;
                stack[top]=item;

            }
            int pop()
            {

                return stack[top];

            }
}

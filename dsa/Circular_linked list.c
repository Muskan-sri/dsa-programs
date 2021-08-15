/*WAP TO IMPLEMENT A CIRCULAR LINKED LIST*/
#include<stdio.h>
#include<stdlib.h>
void create();
void traverse ();
void insert_begin();
void insert_end();
void insert_after_node();
void insert_given_loc();
void del_begin();
void del_end();
void delete_given();
void delete_after_node();

struct node
{

    int info;
    struct node *next;

};
struct node *start=NULL;
int main()
{

    int choice;
    while(1)
    {

        printf("\n0.exit\n1.creation of circular list\n2.traverse\n3.insert at beginning\n4.insert at end\n5.insert after node\n6.insert at a given location\n7.delete at begining\n8.deleter fron end\n9.delete from location\n10delete_after_node\n");
        printf("\nenter your choice");
        scanf("%d",&choice);
        switch(choice)
        {

            case 0:exit(0);
            break;
            case 1:create();
            break;
            case 2:traverse();
            break;
            case 3:insert_begin();
            break;
            case 4:insert_end();
            break;
            case 5:insert_after_node();
            break;
            case 6:insert_given_loc();
            break;
            case 7:del_begin();
            break;
            case 8:del_end();
            break;
            case 9:delete_given();
            break;
            case 10:delete_after_node();
            break;

            default:printf("invalid choice");

        }
    }
}
void create()
{
    int total,item,i;
    struct node *newnode,*temp;
    if(start==NULL)
    {
        printf("\nEnter total number of nodes required: ");
        scanf("%d",&total);
        if(total<=0)
        {
            printf("\nList size must be greater than 0");
        }
        else
        {
            temp=(struct node *)malloc(sizeof(struct node));
            printf("\nEnter the value to keep in node: ");
            scanf("%d",&item);
            temp->info=item;
            temp->next=temp;
            start=temp;

            for(i=2;i<=total;i++)
            {
                newnode=(struct node*)malloc(sizeof(struct node));
                printf("\nEnter the value to keep in node: ");
                scanf("%d",&item);
                newnode->info=item;
                newnode->next=start;
                temp->next=newnode;
                temp=newnode;
            }
            printf("\nList is created\n");
        }
    }
    else
    {
        printf("\nList is already present\n");
    }
}
void traverse()
{
    struct node *temp;
    if(start==NULL)
    {
        printf("List is empty");
    }
    else
    {
        temp=start;
        printf("\nThe values are: \n");
       do
        {
            printf("%d ",temp->info);
            temp=temp->next;
        }
         while(temp!=start);
         printf("\n");
    }
}
void insert_begin()
{
    struct node *newnode,*temp;
    int item;
    newnode=(struct node*)malloc(sizeof(struct node));
    if(newnode==NULL)
    {
        printf("Memory is not allocated");
    }
    else
    {
        printf("Enter the value: ");
        scanf("%d",&item);
        newnode->info=item;
        newnode->next=newnode;
        if(start==NULL)
        {
            start=newnode;
        }
        else
        {
            temp=start;
            while(temp->next!=start)
            {

                temp=temp->next;
            }

            newnode->next=start;
            start=newnode;
            temp->next=newnode;
        }
    }
}
void insert_end()
{
    struct node *newnode,*temp;
    int item;
    newnode=(struct node*)malloc(sizeof(struct node));
    if(newnode==NULL)
    {
        printf("Memory is not allocated");
    }
    else
    {
        printf("Enter the value: ");
        scanf("%d",&item);
        newnode->info=item;
        newnode->next=newnode;
        if (start==NULL)
        {
            start = newnode;
        }
        else
        {
            temp=start;
            while(temp->next!=start)
            {
                temp = temp->next;
            }
            temp->next = newnode;
            newnode->next=start;
        }
    }
}
void insert_after_node()
{
    struct node *newnode,*temp;
    int item,value;
    newnode=(struct node*)malloc(sizeof(struct node));
    if(newnode==NULL)
    {
        printf("Memory is not allocated");
    }
    else
    {

            printf("\nEnter value to be inserted: ");
            scanf("%d",&item);
            newnode->info=item;
            newnode->next=newnode;

       if(start==NULL)
        {
            start=newnode;
        }
        else
    {


        printf("\nEnter the node after which you want to insert: ");
        scanf("%d",&value);
        temp=start;
        do
        {
            temp=temp->next;
        }
         while(temp!=start && temp->info!=value);
         if(temp==NULL)
         {

             printf("node not present");

         }
         else
        {
            newnode->next=temp->next;
            temp->next=newnode;
        }
    }
}
}
void insert_given_loc()
{
    struct node *newnode,*temp,*ptr;
    int item,loc,count=1;
    newnode=(struct node*)malloc(sizeof(struct node));
    if(newnode==NULL)
    {
        printf("Memory is not allocated");
    }
    else
    {
        printf("\nEnter the value to be inserted: ");
        scanf("%d",&item);
        newnode->info=item;
        newnode->next=newnode;
        if(start==NULL)
        {

            start=newnode;
        }
        else
        {
            printf("\nEnter the location: ");
            scanf("%d",&loc);
            temp=start;
          do
        {
            ptr=temp;
            temp=temp->next;
            count++;
        }
         while(temp!=start && count!=loc);

        }
        if(temp==start)
        {
            printf("\nNode is not present\n");
        }
        else
            {
            ptr->next=newnode;
            newnode->next=temp;
        }

    }
}
void del_begin()
{
    struct node *temp,*ptr;
    if (start==NULL)
    {
        printf("list is empty");
    }
    else
    {
        temp=start;
        ptr=start;
        while(ptr->next!=start)
        {

            ptr=ptr->next;
        }

        printf("Deleted value=%d",temp->info);
        start=start->next;
        ptr->next=start;
        free(temp);
    }

}

void del_end()
{
    struct node*temp,*ptr;
    if (start==NULL)
    {
        printf("list is empty");
    }
    else
    {
        temp=start;

        while(temp->next!=start)
        {
            ptr=temp;
            temp = temp->next;
        }
        printf("deleted node is %d",temp->info);
            ptr->next = start;

        free(temp);
    }

}

void delete_given()

{
    struct node *temp,*ptr;
    int loc ,count=1;
    if(start==NULL)
    {
        printf("list is empty");
    }
    else
    {
        printf("Enter the location from which you want to delete: ");
        scanf("%d",&loc);
        temp=start;
        do
        {
            ptr=temp;
            temp=temp->next;
            count++;
        }
        while(temp!=start && count!=loc);
        if(temp==start)
        {
            printf("\nNode is not present\n");
        }
        else
        {
            ptr->next=temp->next;
            printf("\n deleted node=%d\n",temp->info);
            free(temp);
        }
    }
}
void delete_after_node()
{
    struct node *temp, *ptr;
    int item;
    if (start==NULL)
    {
        printf("list is empty");
    }
    else
    {
        printf("\nEnter the value after which you want to delete: ");
        scanf("%d",&item);
        temp=start;
       do
        {
            temp=temp->next;
        }
         while(temp!=start&& temp->info!=item);
        if(temp==NULL)
        {
            printf("\nNode is not present\n");
        }
        else
        {
            ptr=temp->next;
            temp->next=ptr->next;
            printf("the deleated node is %d",temp->info);
            free(ptr);
        }

    }
}


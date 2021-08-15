/* Menu driven Program for Linked List */

#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node *next;
};
struct node *start=NULL, *start1=NULL, *start2=NULL;
void creation();
void create1();
void create2();
void reverse();
void sorting();
void merge();
void insertbegin();
void insertend();
void delbegin();
void delend();
void insertafter();
void deleteafter();
void insertgiven();
void deletegiven();
void display();
void main()
{
    int choice;
    printf("0. CREATION \n1. INSERT AT BEGIN\n2. INSERT AT END\n3. DELETE AT BEGINNING\n4. DELETE AT END\n5. INSERT AFTER NODE");
    printf("\n6. DELETE AFTER NODE\n7. INSERT AT A GIVEN NODE\n8. DELETE AT A GIVEN NODE\n9. REVERSE\n10. SORTING\n11. MERGE\n12. DISPLAY\n13. EXIT");
    while(1)
    {
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 0: creation();
                    break;
            case 1: insertbegin();
                    break;
            case 2: insertend();
                    break;
            case 3: delbegin();
                    break;
            case 4: delend();
                    break;
            case 5: insertafter();
                    break;
            case 6: deleteafter();
                    break;
            case 7: insertgiven();
                    break;
            case 8: deletegiven();
                    break;
            case 9: reverse();
                    break;
            case 10: sorting();
                    break;
            case 11: merge();
                    break;
            case 12: display();
                    break;
            case 13: exit(0);
            default: printf("\nWrong Entry\n");
        }
    }
}
void creation()
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
            temp->next=NULL;
            start=temp;
            for(i=2;i<=total;i++)
            {
                newnode=(struct node*)malloc(sizeof(struct node));
                printf("\nEnter the value to keep in node: ");
                scanf("%d",&item);
                newnode->info=item;
                newnode->next=NULL;
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
void insertbegin()
{
    struct node *newnode;
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
        newnode->next=NULL;
        if(start==NULL)
        {
            start=newnode;
        }
        else
        {
            newnode->next=start;
            start=newnode;
        }
    }
}
void insertend()
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
        newnode->next=NULL;
        if (start==NULL)
        {
            printf("list is empty");
        }
        else
        {
            temp=start;
            while(temp->next!=NULL)
            {
                temp = temp->next;
            }
            temp->next = newnode;
        }
    }
}

void delbegin()
{
    struct node*temp;
    if (start==NULL)
    {
        printf("list is empty");
    }
    else
    {
        temp=start;
        start=temp->next;
        printf("Deleted value=%d",temp->info);
        free(temp);
    }
}
void delend()
{
    struct node*temp,*ptr;
    if (start==NULL)
    {
        printf("list is empty");
    }
    else
    {
        temp=start;
        ptr=start;
        while(temp->next!=NULL)
        {
            ptr=temp;
            temp = temp->next;
        }
        if(temp==start)
        {
            start=NULL;
        }
        else
        {
            ptr->next = NULL;
        }
        free(temp);
    }

}
void display()
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
        while(temp!=NULL)
        {
            printf("%d ",temp->info);
            temp=temp->next;
        }
    }
}
void insertafter()
{
    struct node *newnode,*temp;
    int item,num;
    newnode=(struct node*)malloc(sizeof(struct node));
    if(newnode==NULL)
    {
        printf("Memory is not allocated");
    }
    else
    {
        printf("\nEnter the value after which you want to insert: ");
        scanf("%d",&item);
        temp=start;
        while(temp!=NULL && temp->info!=item)
        {
            temp=temp->next;
        }
        if(temp==NULL)
        {
            printf("\nNode is not present\n");
        }
        else
        {
            printf("\nEnter value to be inserted: ");
            scanf("%d",&num);
            newnode->info=num;
            newnode->next=temp->next;
            temp->next=newnode;
        }
    }
}
void deleteafter()
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
        while(temp!=NULL && temp->info!=item)
        {
            temp=temp->next;
        }
        if(temp==NULL)
        {
            printf("\nNode is not present\n");
        }
        else
        {
            ptr=temp->next;
            temp->next=ptr->next;
        }
        free(ptr);
    }
}
void insertgiven()
{
    struct node *newnode,*temp,*ptr;
    int item,loc,count;
    newnode=(struct node*)malloc(sizeof(struct node));
    if(newnode==NULL)
    {
        printf("Memory is not allocated");
    }
    else
    {
        printf("\nEnter the value to be inserted: ");
        scanf("%d",&item);
        printf("\nEnter the location: ");
        scanf("%d",&loc);
        newnode->info=item;
        newnode->next=NULL;
        count=1;
        temp=start;
        while(temp!=NULL && count!=loc)
        {
            ptr=temp;
            temp=temp->next;
            count=count+1;
        }
        if(temp==NULL)
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
void deletegiven()
{
    struct node *temp, *ptr;
    int loc,count;
    if (start==NULL)
    {
        printf("list is empty");
    }
    else
    {
        printf("\nEnter location where you want delete: ");
        scanf("%d",&loc);
        count=1;
        temp=start;
        while(temp!=NULL && count!=loc)
        {
            ptr=temp;
            temp=temp->next;
            count=count+1;
        }
        if(temp==NULL)
        {
            printf("\nNode is not present\n");
        }
        else
        {
            if(count==1)
            {
                start=temp->next;
                free(temp);
            }
            else
            {
                ptr->next=temp->next;
                free(temp);
            }
        }
    }
}
void reverse()
{
    struct node *temp,*temp1,*temp2;
    if(start==NULL)
    {
        printf("\nList is empty\n");
    }
    else
    {
        temp=start;
        temp1=NULL;
        temp2=NULL;
        while(temp!=NULL)
        {
            temp1=temp->next;
            temp->next=temp2;
            temp2=temp;
            temp=temp1;
        }
        start=temp2;
        printf("\nReverse Completed!!!");
    }
}
void sorting()
{
    int item;
    struct node *temp,*min,*ptr;
    if(start==NULL)
    {
        printf("\nList is empty\n");
    }
    else
    {
        temp=start;
        while(temp->next!=NULL)
        {
            min=temp;
            ptr=temp->next;
            while(ptr!=NULL)
            {
                if(ptr->info < min->info)
                {
                    min=ptr;
                }
                ptr=ptr->next;
            }
            if(temp!=min)
            {
                item=temp->info;
                temp->info=min->info;
                min->info=item;
            }
            temp=temp->next;
        }
        printf("\nSorting Completed!!!\n");
    }
}
void merge()
{
    struct node *temp;
    create1();
    create2();
    temp=start1;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=start2;
    start=start1;
    printf("\nMerging Completed!!!\n");
}
void create1()
{
    int total,item,i;
    struct node *newnode,*temp;
    if(start1==NULL)
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
            temp->next=NULL;
            start1=temp;
            for(i=2;i<=total;i++)
            {
                newnode=(struct node*)malloc(sizeof(struct node));
                printf("\nEnter the value to keep in node: ");
                scanf("%d",&item);
                newnode->info=item;
                newnode->next=NULL;
                temp->next=newnode;
                temp=newnode;
            }
            printf("\nList 1 is created\n");
        }
    }
    else
    {
        printf("\nList 1 is already present\n");
    }
}
void create2()
{
    int total,item,i;
    struct node *newnode,*temp;
    if(start2==NULL)
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
            temp->next=NULL;
            start2=temp;
            for(i=2;i<=total;i++)
            {
                newnode=(struct node*)malloc(sizeof(struct node));
                printf("\nEnter the value to keep in node: ");
                scanf("%d",&item);
                newnode->info=item;
                newnode->next=NULL;
                temp->next=newnode;
                temp=newnode;
            }
            printf("\nList 2 is created\n");
        }
    }
    else
    {
        printf("\nList 2 is already present\n");
    }
}

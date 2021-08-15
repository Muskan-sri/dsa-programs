//wap on double linked list for different operations

#include<stdio.h>
#include<stdlib.h>

void create();
void insertatbegin();
void insertatend();
void deleteatbegin();
void deleteatend();
void insertafternode();
void deleteafternode();
void insertatspecificpos();
void deleteatspecificpos();
void traverse();
void create1();
void create2();
void merge();
void frequency();

struct node
{
    int info;
    struct node *next;
    struct node *prev;
};
struct node *start= NULL,*start1=NULL,*start2=NULL;
main()
{
       int choice;
       while(1)
       {
          printf("\n0 CREATION \n1 INSERT AT BEGINNIGN \n2 INSERT AT END \n3 DELETE FROM BEGGNING \n4 DELETE FROM END \n5 INSERT AFTER NODE \n6 DELETE AFTER NODE \n7 INSERT AT SPECIFIC POS \n8 DELETE AT SPECIFIC POS \n9 TRAVERSE \n10 EXIT \n11 MERGE \n12 FREQUENCY");
          printf("\n enter your choice:");
          scanf("%d",&choice);

          switch(choice)
          {
               case 0: create();
                       break;
               case 1: insertatbegin();
                       break;
               case 2: insertatend();
                       break;
               case 3: deleteatbegin();
                       break;
               case 4: deleteatend();
                       break;
               case 5: insertafternode();
                       break;
               case 6: deleteafternode();
                       break;
               case 7: insertatspecificpos();
                       break;
               case 8: deleteatspecificpos();
                       break;
               case 9: traverse();
                       break;
               case 10: exit(0);
               case 11: merge();
                         break;
               case 12: frequency();
                        break;
               default: printf("wrong choice");
         }
     }
}

void create()
{
     int total,item,index;
     struct node *newnode,*temp;
     if(start==NULL)
     {
         printf("\n the number of nodes you want to keep:");
         scanf("%d",&total);
         if(total<=0)
         {
             printf("\n list size must be greater than zero");
         }
         else
         {
             temp=(struct node*)malloc(sizeof(struct node));
             printf("\n enter the value to keep in the node:");
             scanf("%d",&item);
             temp->info=item;
             temp->next=NULL;
             temp->prev=NULL;
             start=temp;
             for(index=2;index<=total;index++)
             {
                  newnode=(struct node*)malloc(sizeof(struct node));
                  printf("\n enter the value to keep in the node:");
                  scanf("%d",&item);
                  newnode->info=item;
                  newnode->next=NULL;
                  newnode->prev=temp;
                  temp->next=newnode;
                  temp=newnode;
             }
             printf("\n list is created");
         }
     }
     else
     {
        printf("\n list is already present");
     }

}

void traverse()
{
    struct node *temp=start;
    if(start==NULL)
    {
        printf("Empty list\n");
    }
    else
    {
        printf("\nForward Display : ");
        while(temp!=NULL)
        {
            printf("%d  ",temp->info);
            temp=temp->next;
        }
        printf("\nBackward Display : ");
        temp=start;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        while(temp!=NULL)
        {
            printf("%d  ",temp->info);
            temp=temp->prev;
        }
    }
}

void insertatbegin()
{
     struct node *newnode;
     int item;
     newnode=(struct node*)malloc(sizeof(struct node));
     if(newnode==NULL)
     {
         printf("memory is not allocated");
     }
     else
     {
          printf("\n enter the value to insert:");
          scanf("%d",&item);
          newnode->info=item;
          newnode->next=NULL;
          newnode->prev=NULL;
          if(start==NULL)
          {
              start=newnode;
          }
          else
          {
                newnode->next=start;
                start->prev=newnode;
                start=newnode;
          }
    }
}

void insertatend()
{
     struct node *newnode,*temp;
     int item;
     newnode=(struct node*)malloc(sizeof(struct node));
     if(newnode==NULL)
     {
         printf("memory is not allocated");
     }
     else
     {
          printf("\n enter the value to insert:");
          scanf("%d",&item);
          newnode->info=item;
          newnode->next=NULL;
          newnode->prev=NULL;
          if(start==NULL)
          {
              start=newnode;
          }
          else
          {
               temp=start;
               while(temp-> next!= NULL)
               {
                   temp=temp->next;
               }
               temp->next=newnode;
               newnode->prev=temp;
          }
    }
}

 void deleteatbegin()
{
     struct node *temp;
     if(start==NULL)
     {
         printf("\n list is empty");
     }
     else
     {
          temp=start;
          start=start->next;
          start->prev=NULL;
          printf("deleted value=%d",temp->info);
          free(temp);
     }
}

void deleteatend()
{
    struct node *temp,*ptr;
     if(start==NULL)
     {
         printf("\n list is empty");
     }
     else
     {
         temp=start;
         ptr=start;
         while(temp->next!=NULL)
         {
            ptr=temp;
            temp=temp->next;
         }
         ptr->next=NULL;
         printf("\n the deleted node is %d",temp->info);
         free(temp);
    }

}

void insertafternode()
{
     struct node *newnode,*temp,*ptr;
     int item,value;
     newnode=(struct node*)malloc(sizeof(struct node));
     if(newnode==NULL)
     {
         printf("memory is not allocated");
     }
     else
     {
          printf("\n enter the value to insert:");
          scanf("%d",&item);
          newnode->info=item;
          newnode->next=NULL;
          newnode->prev=NULL;
          if(start==NULL)
          {
              start=newnode;
          }
          else
          {
              printf("the value after which you want to insert:");
              scanf("%d",&value);
              temp=start;
              while(temp != NULL && temp->info != value)
              {
                  temp=temp->next;
              }
              if(temp==NULL)
              {
                  printf("node is not present");
              }
              else
              {
                  ptr=temp->next;
                  newnode->next = ptr;
                  ptr->prev=newnode;
                  temp->next = newnode;
                  newnode->prev=temp;
              }
          }
     }
}

void deleteafternode()
{
     struct node *temp,*ptr,*ptr1;
     int value;
     if(start==NULL)
     {
         printf("\n list is empty");
     }
     else
     {
          printf("the value after which you want to delete:");
              scanf("%d",&value);
              ptr=start;
              while(ptr != NULL && ptr->info != value)
              {
                  ptr=ptr->next;
              }
              if(ptr==NULL)
              {
                  printf("node is not present");
              }
              else if(ptr->next ==NULL)
              {
                  printf("\n node is not present after that node");
              }
              else
              {
                  temp=ptr->next;
                  ptr1=temp->next;
                  ptr->next=ptr1;
                  ptr1->prev=ptr;
                  printf("\n the deleted node is %d",temp->info);
                  free(temp);
              }
     }

}

void insertatspecificpos()
{
     struct node *newnode,*temp,*ptr;
     int item,loc,count=1;
     newnode=(struct node*)malloc(sizeof(struct node));
     if(newnode==NULL)
     {
         printf("memory is not allocated");
     }
     else
     {
          printf("\n enter the value to insert:");
          scanf("%d",&item);
          newnode->info=item;
          newnode->next=NULL;
          newnode->prev=NULL;
          if(start==NULL)
          {
              start=newnode;
          }
          else
          {
              printf("\n the location at which insertion will be done:");
              scanf("%d",&loc);
              if(loc==1)
              {
                   newnode->next=start;
                   start->prev=newnode;
                   start=newnode;
              }
              else
              {
                  temp=start;
                 while(temp!=NULL && count!=loc)
                 {
                      ptr=temp;
                     temp=temp->next;
                      count++;
                 }
                 if(temp==NULL)
                 {
                     printf("\n Node is not present");
                 }
                 else
                 {
                      ptr->next=newnode;
                      newnode->prev=ptr;
                      newnode->next=temp;
                      temp->prev=newnode;
                  }
              }
          }
     }
}

void deleteatspecificpos()
{
      struct node *temp,*ptr,*ptr1;
      int loc,count=1;
     if(start==NULL)
     {
         printf("\n list is empty");
     }
     else
     {

              printf("\n the location at which deletion will be done:");
              scanf("%d",&loc);
              ptr=start;
              while(ptr!=NULL && count!=loc)
              {
                  ptr1=ptr;
                  ptr=ptr->next;
                  count++;
              }
              if(ptr==NULL)
              {
                  printf("\n Node is not present");
              }
              else if(loc == 1 )
              {
                  start=start->next;
                  start->prev=NULL;
                  printf("\n deleted node is %d",ptr->info);
                  free(ptr);
              }
              else
              {
                  temp=ptr->next;
                  ptr1->next=temp;
                  temp->prev=ptr1;
                  printf("\n deleted node is %d",ptr->info);
                  free(ptr);
              }
     }
}
void create1()
{
     int total,item,index;
     struct node *newnode,*temp;
     if(start1==NULL)
     {
         printf("\n the number of nodes you want to keep:");
         scanf("%d",&total);
         if(total<=0)
         {
             printf("\n list size must be greater than zero");
         }
         else
         {
             temp=(struct node*)malloc(sizeof(struct node));
             printf("\n enter the value to keep in the node:");
             scanf("%d",&item);
             temp->info=item;
             temp->next=NULL;
             temp->prev=NULL;
             start1=temp;
             for(index=2;index<=total;index++)
             {
                  newnode=(struct node*)malloc(sizeof(struct node));
                  printf("\n enter the value to keep in the node:");
                  scanf("%d",&item);
                  newnode->info=item;
                  newnode->next=NULL;
                  newnode->prev=temp;
                  temp->next=newnode;
                  temp=newnode;
             }
             printf("\n list 1 is created");
         }
     }
     else
     {
        printf("\n list 1 is already present");
     }

}
void create2()
{
     int total,item,index;
     struct node *newnode,*temp;
     if(start==NULL)
     {
         printf("\n the number of nodes you want to keep:");
         scanf("%d",&total);
         if(total<=0)
         {
             printf("\n list size must be greater than zero");
         }
         else
         {
             temp=(struct node*)malloc(sizeof(struct node));
             printf("\n enter the value to keep in the node:");
             scanf("%d",&item);
             temp->info=item;
             temp->next=NULL;
             temp->prev=NULL;
             start2=temp;
             for(index=2;index<=total;index++)
             {
                  newnode=(struct node*)malloc(sizeof(struct node));
                  printf("\n enter the value to keep in the node:");
                  scanf("%d",&item);
                  newnode->info=item;
                  newnode->next=NULL;
                  newnode->prev=temp;
                  temp->next=newnode;
                  temp=newnode;
             }
             printf("\n list 2 is created");
         }
     }
     else
     {
        printf("\n list 2 is already present");
     }

}
void merge()
{
    struct node *temp;
    create1();
    create2();
    temp = start1;
    while(temp->next != NULL)
    {
        temp=temp->next;

    }
    temp->next = start2;
    start2->prev=temp;
    start=start1;
}
void frequency()
{
    struct node *temp,*ptr;
    int count=0,ele;
    if(start==NULL)
    {
        printf("\n list is not present");
    }
    else
    {
        printf("\n enter the element you wanna search:");
        scanf("%d",&ele);
        temp=start;
        while(temp->next!=NULL)
        {
            if(temp->info==ele)
            {
                count++;
            }
            temp=temp->next;
        }
        printf("%d is present %d times",ele,count);
    }
}

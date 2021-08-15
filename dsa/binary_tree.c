//BINARY TREE
#include<stdio.h>
#include<stdlib.h>

struct node
{
     int info;
     struct node *lchild;
     struct node *rchild;
};

void inorder(struct node*);
void preorder(struct node*);
void postorder(struct node*);
void minvalue(struct node*);
void maxvalue(struct node*);
void insert();
void delete_1();
void caseA(struct node *, struct node *);
void caseB(struct node *, struct node *);
void caseC(struct node *, struct node *);

struct node *root = NULL;

main()
{
        int choice;
        while(1)
        {
            printf("\n1.Insert\n2.Inorder Traversal\n3.Preorder Traversal\n4.Postorder Traversal\n5.Mnimum\n6.Maximum\n7.Exit\n8.DELETE FROM BST\n");
            printf("\n Enter your choice:");
            scanf("%d",&choice);
            switch(choice)
            {
                  case 1:insert();
                          break;
                  case 2:if(root == NULL)
                         {
                               printf("\n Tree is empty\n");
                         }
                         else
                         {
                              printf("\n Values of the inorder traversal are:");
                              inorder(root);
                         }
                         break;
                  case 3:if(root == NULL)
                         {
                               printf("\n Tree is empty\n");
                         }
                         else
                         {
                              printf("\n Values of the preorder traversal are:");
                              preorder(root);
                         }
                         break;
                   case 4:if(root == NULL)
                         {
                               printf("\n Tree is empty\n");
                         }
                         else
                         {
                              printf("\n Values of the postorder traversal are:");
                              postorder(root);
                         }
                         break;
                   case 5: minvalue(root);
                           break;
                   case 6: maxvalue(root);
                           break;


                    case 7:exit(0);
                    case 8: delete_1();

                  default:printf("\n Wrong Choice\n");
             }
        }
}

void inorder(struct node *temp)
{
     if(temp != NULL)
     {
         inorder(temp->lchild);
         printf(" %d ",temp->info);
         inorder(temp->rchild);
     }
}
void preorder(struct node *temp)
{
     if(temp != NULL)
     {
         printf(" %d ",temp->info);
         preorder(temp->lchild);
         preorder(temp->rchild);
     }
}
void postorder(struct node *temp)
{
     if(temp != NULL)
     {
         postorder(temp->lchild);
         postorder(temp->rchild);
         printf(" %d ",temp->info);
     }
}

void insert()
{
     struct node *temp,*ptr,*par;
     int item;
     temp=(struct node *)malloc(sizeof(struct node));
     if(temp==NULL)
     {
            printf("\n memory is not allocated\n");
     }
     else
     {
            printf("\nEnter the values to be inserted:");
            scanf("%d",&item);
            temp->info = item;
            temp->lchild=NULL;
            temp->rchild=NULL;
            if(root == NULL)
            {
                  root=temp;
            }
            else
            {
                  ptr=root;
                  while(ptr!=NULL)
                  {
                       par=ptr;
                       if(item<ptr->info)
                       {
                             ptr=ptr->lchild;
                       }
                       else if(item>ptr->info)
                       {
                           ptr=ptr->rchild;
                       }
                       else
                       {
                            printf("\n duplicate element can not be inserted\n");
                            break;
                       }
                  }
                  if(ptr == NULL)
                  {
                        if(item<par->info)
                        {
                              par->lchild=temp;
                        }
                        else
                        {
                               par->rchild=temp;
                        }
                  }
            }

        }
}
void minvalue(struct node* temp)
{
    while(temp->lchild != NULL)
    {
        temp=temp->lchild;
    }
    printf("\nMinimum value is:%d",temp->info);
}

void maxvalue(struct node* temp)
{
    while(temp->rchild != NULL)
    {
        temp=temp->rchild;
    }
    printf("\nMaximum value is:%d",temp->info);
}
   void delete_1()
   {

       struct node *ptr,*par;
       int item;
       if(root==NULL)
       {

           printf("\n THE TREE IS EMPTY");

       }
       else
        {
        ptr = root;
        par  =NULL;
        printf("\nENTER THE NODE TO BE DELEATED\N");
        scanf("%d",&item);
        while(ptr!=NULL)
            {

                if(ptr->info==item)
                {
                    break;
                }
                par =ptr;
                if(item<ptr->info)
                {
                    ptr =ptr->lchild;
                }
                else
                {
                    ptr =ptr->rchild;
                }

            }
       if(ptr ==NULL)
       {
           printf("\NNODE NOT PRESENT\N");

       }
       else{
        printf("\n DELEATED NODE IS %d\n",ptr->info);
        if((ptr->lchild==NULL)&&(ptr->rchild==NULL))
        {
            caseA(par,ptr);
        }
        else if((ptr->lchild!=NULL)&&(ptr->rchild!=NULL))
        {
            caseC(par,ptr);
        }
        else
        {
            caseB(par,ptr);
        }


       }
               }
   }
   void caseA(struct node *par,struct node *ptr)
   {
       if(par==NULL)//DELETE THE SINGLE ROOT NODE
       {

           root==NULL;
           free(ptr);

       }
       else{
        if(ptr->info<par->info)
        {

            par->lchild=NULL;
        }
        else{
            par->rchild =NULL;
        }
        free(ptr);
       }
   }
   void caseB(struct node *par, struct node *ptr)
   {   struct node *child;
       if(ptr->lchild!=NULL)
       {
           child = ptr->lchild;
       }
       else
       {
           child = ptr->rchild;
       }
       if(par==NULL)
       {
           root = child;
           free(ptr);
       }
       else
       {
           if(ptr == par->lchild)
           {
               par->lchild =child;
           }
           else
           {
               par->rchild=child;
           }
           free(ptr);
       }
   }

void caseC(struct node *par,struct node *ptr)
{
struct node *pptr,*ppar;
pptr = ptr->rchild;
ppar = ptr;
while(pptr->lchild != NULL)
{

    ppar = pptr;
    pptr = pptr->lchild;
}
ptr->info = pptr->info;
if(pptr->rchild!=NULL)
{
    caseB(ppar,pptr);
}
else{
    caseA(ppar,pptr);
}
}

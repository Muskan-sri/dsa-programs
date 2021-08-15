//double linked list
#include<stdio.h>
#include<stdlib.h>
void create_node();
void display();
void insert_begin();
void insert_end();
void insert_afternode();
void insert_at_location();
struct node
{
	int info;
	struct node *next;
    struct node *prev;
};
struct node *start=NULL;

int main()
{
	int choice;
	while(1)
	{
		printf("\n0.Create  \n1.display\n2.Insert at begin\n3.insert at end\n4.Insert after a node\n5.Insert at a location\n6.Exit\n");
		printf("\nEnter your choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 0:create_node();
					break;
			case 1:display();
					break;
		    case 2:insert_begin();
					break;
			case 3:insert_end();
					break;
			case 4:insert_afternode();
				break;
			case 5:insert_at_location();
				break;
			case 6:exit(0);
			default:printf("\nWrong Choice\n");
					break;
		}
	}
}
void create_node()
{
	int total,item,index;
	struct node *newnode,*temp;
	if(start == NULL)
	{
		printf("\nEnter the total number of nodes you want to keep\n");
		scanf("%d",&total);
		if(total<=0)
		{
			printf("\nList size must be greater than zero\n");
		}
		else
		{
			temp = (struct node *)malloc(sizeof(struct node));
			printf("\nEnter the value to keep in the node\n");
			scanf("%d",&item);
			temp->info = item;
			temp->next = NULL;
            temp->prev=NULL;//Addition in double lined list
			start = temp;
			for(index=2;index<=total;index++)
			{
				newnode = (struct node *)malloc(sizeof(struct node));
				printf("\nEnter the value to keep in the node\n");
				scanf("%d",&item);
				newnode->info = item;
				newnode->next = NULL;
                newnode->prev=temp;
				temp->next = newnode;
				temp = newnode;
			}
			printf("\nList is created\n");
		}
	}
	else
	{
		printf("\nList is already present\n");
	}

}

void display()
{
	struct node *temp;
	if(start == NULL)
	{
		printf("\nList is empty\n");
	}
	else
	{
		temp = start;
		printf("\nValues of list are\n");
		while(temp!=NULL)
		{
			printf("%d\t",temp->info);
			temp = temp->next;
		}
		printf("\n");
		printf("\nValues in reverse order\n");
		temp=start;
		while(temp->next!=NULL)
		{
			temp = temp->next;
		}
		while(temp!=NULL)
		{
			printf("%d\t",temp->info);
			temp = temp->prev;
		}



	}
}

void insert_begin()
{
	struct node *newnode;
	int item;
	newnode = (struct node *)malloc(sizeof(struct node));
	if(newnode == NULL)
	{
		printf("\nMemory is not allocated\n");
	}
	else
	{
		printf("\nEnter the value to insert\n");
		scanf("%d",&item);
		newnode->info = item;
		newnode->next = NULL;
		newnode->prev = NULL;

		if(start == NULL)
		{
			start = newnode;
		}
		else
		{
			newnode->next = start;
			start->prev= newnode;
			start=newnode;
		}
	}
}
void insert_end()
{
	struct node *newnode,*temp;
	int item;
	newnode = (struct node *)malloc(sizeof(struct node));
	if(newnode == NULL)
	{
		printf("\nMemory is not allocated\n");
	}
	else
	{
		printf("\nEnter the value to insert\n");
		scanf("%d",&item);
		newnode->info = item;
		newnode->next = NULL;
		newnode->prev= NULL;
		if(start == NULL)
		{
			start = newnode;
		}
		else
		{
			temp = start;
			while(temp->next !=NULL)
			{
				temp = temp->next;
			}
			temp->next = newnode;
			newnode->prev= temp;
		}
	}
}
void insert_afternode()
{
	struct node *temp,*ptr,*temp1;
	int item,value;
	temp = (struct node *)malloc(sizeof(struct node));
	if(temp == NULL)
	{
		printf("\nMemory is not allocated\n");
	}
	else
	{
		printf("\nEnter the value to insert\n");
		scanf("%d",&item);
		temp->info = item;
		temp->next = NULL;
		temp->prev=NULL;
		if(start == NULL)
		{
			start = temp;
		}
		else
		{
			printf("\nEnter the node after which you want to insert\n");
			scanf("%d",&value);
			ptr=start;
			while(ptr!=NULL && ptr->info!=value)
			{
				ptr=ptr->next;
			}
			if(ptr == NULL)
			{
				printf("\nNode is not present\n");
			}
			else
			{	temp1=ptr->next;
				temp->next = temp1;
				temp1->prev=temp;
				ptr->next = temp;
				temp->prev=ptr;
			}
		}
	}
}
void insert_at_location()
{
	struct node *temp,*ptr,*newnode;
	int count=1,loc;
	int item;
	newnode = (struct node *)malloc(sizeof(struct node));
	if(newnode == NULL)
	{
		printf("\nMemory is not allocated\n");
	}
	else
	{
		printf("\nEnter the value to insert\n");
		scanf("%d",&item);
		newnode->info = item;
		newnode->next = NULL;
		newnode->prev = NULL;
		if(start == NULL)
		{
			start = newnode;
		}
		else
		{
			printf("\nEnter the location at which you want to insert\n");
			scanf("%d",&loc);
			if(loc == 1)
			{
				newnode->next = start;
				start->prev=newnode;
				start = newnode;
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
				if(temp == NULL)
				{
					printf("\nNode is not present\n");
				}
				else
				{
					ptr->next = newnode;
					newnode->prev = ptr;
					newnode->next = temp;
					temp->prev = newnode;
				}
			}
		}
	}
}

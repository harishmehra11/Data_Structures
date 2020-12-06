#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct node
{
	int data;
	struct node *next;
};
struct node *head=NULL;
void insert_beg()
{
	struct node *new_node;
	new_node=(struct node*)malloc(sizeof(struct node));
	printf("Enter the element:");
	scanf("%d",new_node->data);
	if(head==NULL)
	{
		head=new_node;
		new_node=head;
	}
	else
	{
		new_node->next=head;
		head=new_node;
	}
}

void insert_spec()
{
	struct node *new_node,*temp;
	int pos,i;
	if(pos==1)
	{
		insert_beg();
	}
	else
	{
		new_node=(struct node*)malloc(sizeof(struct node));
		printf("Enter the element to be deleted:");
		scanf("%d",&new_node->data);
		new_node->next=NULL;
		temp=head;
		for(i=1;i<pos-1;i++)
		temp=temp->next;
		new_node->next=temp->next;
		temp->next=new_node;
	}
}

void insert_end()
{
	struct node *new_node,*last=head;
	new_node=(struct node*)malloc(sizeof(struct node));
	printf("Enter the element:");
	scanf("%d",new_node->data);
	printf("Enter the element to be deleted:");
	scanf("%d",&new_node->data);
	new_node->next=NULL;
	if(head==NULL)
	{
		head=new_node;
		return;
	}
	else
	{
		while(last->next!=NULL)
		{
			last=last->next;
			last =new_node;
		}
	}
	
}


void display()
{
	struct node *temp;
	temp=head;
	
	if(temp==NULL)
	{
		printf("Empty list");
	}
	else
	{
	 while(temp->next!=NULL)
	 {
		printf("\t%d",temp->data);
		temp=temp->next;
	 }
	}
}

void del_beg()
{
	struct node *ptr;
	if(head==NULL)
	{
		printf("List is empty");
	}
	else
	{
		ptr=head;
		head=ptr->next;
		free(ptr);
		printf("The item is deleted.");
	}
}

void del_end()
{
	struct node *ptr,*ptr1;
	if(head==NULL)
	{
		printf("List is empty.");
	}
	else if(head->next==NULL)
	{
		head=NULL;
		free(head);
		printf("Only item is deleted.");
	}
	else
	{
		ptr=head;
		while(ptr->next!=NULL)
		{
			ptr1=ptr;
			ptr=ptr->next;
		}
		ptr1->next=NULL;
		free(ptr);
		printf("Deleted item from the last.");
	}
}

void del_spec()
{
	struct node*ptr,*ptr1;
	int pos,i;
	printf("Enter the location:");
	scanf("%d",&pos);
	ptr=head;
	for(i=0;i<pos;i++)
	{
		ptr1=ptr;
		ptr=ptr->next;
		if(ptr==NULL)
		{
			printf("There are less than %d elements.",pos);
			return;
		}
	}
	ptr1->next=ptr->next;
	free(ptr);
	printf("\n Deleted %d node",&pos);
}

void main()
{
	int choice;
	
	while(1)
	{
		printf("\n1.Insert at the beginning:");
		printf("\n2.Insert at the last:");
		printf("\n3.Insert at the specified position:");
		printf("\n4.Delete from the beginnning:");
		printf("\n5.Delete fromt he last:");
		printf("\n6.Delete from a specified position:");
		printf("\n7.Display the list");
		printf("\n8.Exit");
		printf("Enter your choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:insert_beg();
				break;
			case 2:insert_end();
			break;
			case 3:insert_spec();
			break;
			case 4:del_beg();
			break;
			case 5:del_end();
			break;
			case 6:del_spec();
			break;
			case 7:display();
			break;
			case 8:exit(0);
		}
	}
	
}






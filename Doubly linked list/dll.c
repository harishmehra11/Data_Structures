#include <stdio.h>
#include <stdlib.h>
// A linked list node

struct Node {

    int data;
    struct Node* next;
    struct Node* prev;
    };
/* Given a reference (pointer to pointer) to the head of a list

   and an int, inserts a new node on the front of the list. */
void push(struct Node** head_ref, int new_data)
{

    /* 1. allocate node */
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

    /* 2. put in the data  */
    new_node->data = new_data;

    /* 3. Make next of new node as head and previous as NULL */
    new_node->next = (*head_ref);
    new_node->prev = NULL;

    /* 4. change prev of head node to new node */
    if ((*head_ref) != NULL)
        (*head_ref)->prev = new_node;

    /* 5. move the head to point to the new node */
    (*head_ref) = new_node;
    }


void printList(struct Node* node)
{

    struct Node* last;
    printf("List:");
    while (node != NULL) {
        printf(" %d ", node->data);
        last = node;
        node = node->next;
    }

   
    }







void deleteNode(struct Node** head_ref, int n)
{ struct Node* current = *head_ref;

   
    if (*head_ref == NULL )
	{printf("Empty list.");}
	else if(head_ref->next==NULL)
	{
		free(head_ref);
		head_ref=NULL:
	}

   
	
	else{
		
    while(current->next!=NULL)
	{
		current=current->next;
		if(current->data==n)
		{
			current->prev->next=current->next;
			current->next->prev=current->prev;
			free(current);
		}
		
	}
	 printf("Element is not there in the list.");
	}
   
       
    }
	
	
	
int main()
{
	int ele;

    
    struct Node* head = NULL;
	int choice,item;
		while(1)
		{
			printf("\n1.Enter the element in the list 1");
			printf("\n2.Delete");
			printf("\n3.Display");
			
			
			printf("\nEnter your choice:");
			scanf("%d",&choice);
			switch(choice)
			{
				case 1:printf("Enter the element ");
				scanf("%d",&item);
				push(&head,item);
				break;
				case 2:printf("Enter the element to be deleted:");
					scanf("%d",&ele);
				deleteNode(&head,ele);
				break;
				case 3:printList(head);
				break;
				
				default:exit(0);
			}
		}

    

    
	
 
	

    getchar();
    return 0;
    }

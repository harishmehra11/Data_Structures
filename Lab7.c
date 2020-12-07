


#include <stdio.h>
#include <stdlib.h>
/* Link list node */
struct Node {
    int data;
        struct Node* next;
        };
/* Function to reverse the linked list */
static void reverse(struct Node** head_ref)
{
    struct Node* prev = NULL;
        struct Node* current = *head_ref;
            struct Node* next = NULL;
                while (current != NULL) {
                        // Store next
                                next = current->next;
        // Reverse current node's pointer
                current->next = prev;
        // Move pointers one position ahead.
                prev = current;
                        current = next;
                            }
                                *head_ref = prev;
                                }
/* Function to push a node */
void push(struct Node** head_ref, int new_data)
{
    struct Node* new_node
            = (struct Node*)malloc(sizeof(struct Node));
                new_node->data = new_data;
                    new_node->next = (*head_ref);
                        (*head_ref) = new_node;
                        }
/* Function to print linked list */
void printList(struct Node* head)
{
    struct Node* temp = head;
        while (temp != NULL) {
                printf("%d  ", temp->data);
                        temp = temp->next;
                            }
}
void sortedInsert(struct Node** head_ref, struct Node* new_node)
{
    struct Node* current;
        /* Special case for the head end */
            if (*head_ref == NULL || (*head_ref)->data >= new_node->data)
                {
                        new_node->next = *head_ref;
                                *head_ref = new_node;
                                    }
                                       else
                                            {
                                                    /* Locate the node before the point of insertion */
                                                            current = *head_ref;
                                                                    while (current->next!=NULL &&
                                                                                   current->next->data < new_node->data)
                                                                                           {
                                                                                                       current = current->next;
                                                                                                               }
                                                                                                                       new_node->next = current->next;
                                                                                                                               current->next = new_node;
                                                                                                                                   }
                                                                                                                                   }
void insertionSort(struct Node **head_ref)
{
    // Initialize sorted linked list
        struct Node *sorted = NULL;
    // Traverse the given linked list and insert every
        // node to sorted
            struct Node *current = *head_ref;
                while (current != NULL)
                    {
                            // Store next for next iteration
                                    struct Node *next = current->next;
        // insert current in sorted linked list
                sortedInsert(&sorted, current);
        // Update current
                current = next;
                    }
    // Update head_ref to point to sorted linked list
        *head_ref = sorted;
        }
		
							
/* Driver code*/
int main()
{
    /* Start with the empty list */
        struct Node* head = NULL;
		int choice,item;
		while(1)
		{
			printf("\n1.Enter the element in the list");
			printf("\n2.Reverse");
			printf("\n3.Display");
			printf("\n4.Sort the list");
			printf("\nEnter your choice");
			scanf("%d",&choice);
			switch(choice)
			{
				case 1:printf("Enter the element ");
				scanf("%d",&item);
				push(&head,item);
				break;
				case 2:reverse(&head);
				break;
				case 3:printList(head);
				break;
				case 4:insertionSort(&head);
				break;
				default:exit(0);
			}
		}
    
                        getchar();
                        }
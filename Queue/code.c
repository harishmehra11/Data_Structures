#include<stdio.h>
#include<stdbool.h>
# define size 100
int queue[];
int front=-1,rear=-1;
bool isfull()
{
    if (rear==size-1)
        return true;
    else
        return false;
}
bool isempty()
{
    if(rear==-1&&front==-1)
       return true;
    else
       return false;
}

void enqueue()
{
    int x;
 if(isfull())
  {
    printf("Queue is full.");
  }
 else if(isempty())
  {
      printf("ENter the element to be entered:");
      scanf("%d",&x);
     rear=0;
     front=0;
     queue[rear]=x;
  }
 else
  {  printf("ENter the element to be entered:");
      scanf("%d",&x);
     rear++;
     queue[rear]=x;
  }
}
void dequeue()
{
    if(isempty())
    {
        printf("Queue is empty.");
    }
    else if(rear==front)
    {

        printf("Deleted element is:%d",queue[front]);
        rear=-1;
        front=-1;

    }
    else
    {

        printf("Deleted element is:%d",queue[front]);
        front++;
    }

}
void display()
{
    int i;
    if(isempty())
    {
        printf("Queue is empty.");
    }
    else
    {
        printf("Queue is :");
        for(i=front;i<=rear;i++)
        {
            printf("\t%d",queue[i]);
        }
    }

}
void main()
{
    int ch;
    while(1)
    {
        printf("\n1.INsert element.");
        printf("\n2.Delete element.");
        printf("\n3.Display queue.");
        printf("\n4.Exit");
        printf("\nEnter the choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:enqueue();
                   break;
            case 2:dequeue();
                   break;
            case 3:display();
                   break;
            case 4:exit(1);
                   break;
            default:printf("Invalid choice.");
        }
    }
}

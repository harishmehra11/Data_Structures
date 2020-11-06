#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
# define size 10
int stack[size], top=-1;
void push(int value)
{
 if(top==size-1)
 {
     printf("Stack is full.");
 }
 else{
        top++;
 stack[top]=value;
 }
}

void pop()
{
    if (top==-1){printf("EMpty Stack");}
    else{printf("The deleted element from the stack is:",stack[top]);
        top--;
    }
}
void display()
{
    int i;
    printf("The elements of the stacks are:");
    for(i=top;i>-1;i--)
    {       printf("%d\n",stack[i]);
    }
}


void main()
{
    char cont;
    while(1){int choice,value;
    printf("********MENU********\n");
    printf("1.Push\n2.Pop\n3.Display\n4.Exit");
    printf("Enter the choice:");
    scanf("%d",&choice);
    if(choice==1){
        printf("Enter the value to be pushed in the stack: ");
        scanf("%d",&value);
        push(value);
    }
    else if(choice==2){pop();}
    else if(choice==3){display();}
    else if(choice==4){exit(0);}
    else
        {printf("Invalid choice");}
    printf("Continue?Press y or n:");
    scanf("%c",&cont);
    }
    getch();

}


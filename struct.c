#include<stdio.h>
#define size 100
struct student
{
int id;
int age;
int marks;
}s[size];
void main()
{
   int num,i;
   printf("Enter total number of students:");
   scanf("%d",&num);
   for(i=0;i<num;i++)
   {
   printf("Enter the id:");
   scanf("%d",&s[i].id);
   printf("Enter the age:");
   scanf("%d",&s[i].age);
   printf("Enter the marks:");
   scanf("%d",&s[i].marks);
   }
   printf("**********Results*********");
   for(i=0;i<num;i++)
   {
   if(s[i].age>20)
   {
   if(s[i].marks>=65)
   {printf("\nStudent %d is eligible.",i+1);}
   else printf("\nMarks are not as required for student%d.",i+1);
   }
   else printf("\nAge of the candidate is less than 20 for student%d",i+1);
   }
}

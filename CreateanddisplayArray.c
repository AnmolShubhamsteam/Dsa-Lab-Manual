//  1. Design, Develop and Implement a menu driven Program in C for the following Array 
// Operations
// a. Creating an Array of N Integer Elements
// b. Display of Array Elements with Suitable Headings
// c. Exit.
// Support the program with functions for each of the above operations.
#include<stdio.h>
#include<stdlib.h>
int a[20];
int n,val,i,pos;
void create()
{
printf("\nEnter the size of the array elements:\t");
scanf("%d",&n);
printf("\nEnter the elements for the array:\n");
for (int i=0; i<n; i++)
{
    scanf("%d",&a[i]);
}
}
void display()
{
int i;
printf("\nThe array elements are :\n");
for(i=0;i<n;i++)
{
printf("%d\t",a[i]);
}
}
int main()
{
int choice=1;
while(choice)
{
printf("\n\n--------MENU-----------\n");
printf("1.CREATE\n");
printf("2.DISPLAY\n");
printf("3.EXIT\n");
scanf("%d",&choice);
switch(choice)
{
case 1:
create();
break;
case 2:
display();
break;
case 3:
exit(0);
default:
printf("\nInvalid choice:\n");
}
}
return 0;
}


// 2. Design, Develop and Implement a menu driven Program in C for the following Array 
// operations
// a. Inserting an Element (ELEM) at a given valid Position (POS)
// b. Deleting an Element at a given valid Position POS)
// c. Display of Array Elements
// d. Exit.
// Support the program with functions for each of the above operations.
#include<stdio.h>
#include<stdlib.h>
int a[20];
int n,val,i,pos;
/*Function Prototype*/
void create();
void display();
void insert();
void delete();
int main()
{
int choice=1;
while(choice)
{
printf("\n\n--------MENU-----------\n");
printf("1.CREATE\n");
printf("2.DISPLAY\n");
printf("3.INSERT\n");
printf("4.DELETE\n");
printf("5.EXIT\n");
printf("-----------------------");
printf("\nENTER YOUR CHOICE:\t");
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
insert();
break;
case 4:
delete();
break;
case 5:
exit(0);
default:
printf("\nInvalid choice:\n");
break;
}
}
return 0;
}
//creating an array
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
void insert()
{
printf("\nEnter the position for the new element:\t");
scanf("%d",&pos);
printf("\nEnter the element to be inserted :\t");
scanf("%d",&val);
if(pos>=n||pos<0){
printf("Invalid position\n");
}
else{
for(i=n-1;i>=pos;i--)
{
a[i+1]=a[i];
}
a[pos]=val;
n=n+1;
}
}
void delete()
{
printf("\nEnter the position of the element to be deleted:\t");
scanf("%d",&pos);
if(pos>=n||pos<0){
printf("Invalid position\n");
}
else{
    val=a[pos];
    for (int i=pos;i <n-1;i++)
    {
        a[i]=a[i+1];
    }
    n=n-1;
    printf("\nThe deleted element is =%d",val);
}
}

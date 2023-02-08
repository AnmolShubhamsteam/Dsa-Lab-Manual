#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int count = 0;
struct node
{
    int sem;
    char name[30], branch[30], usn[30];
    struct node *link;
} *first = NULL, *last = NULL, *temp = NULL;

void create()
{
    int sem;
    char name[30], branch[30], usn[30];
    temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter name,usn,branch,semester of student\n");
    scanf("%s%s%s%d", name, usn, branch, &sem);
    strcpy(temp->usn, usn);
    strcpy(temp->name, name);
    strcpy(temp->branch, branch);
    temp->sem = sem;
    temp->link = NULL;
    count++;
}
void insert_end()
{
    if (first == NULL)
    {
        create();
        first = temp;
        last = temp;
    }
    else
    {
        create();
        last->link = temp;
        last = temp;
    }
}
void delete_front()
{
    if (first == NULL)
    {
        printf("The list is empty\n");
        return;
    }
    temp = first;
    if (temp->link == NULL)
    {
        printf("Deleted student is %s\n%s\n%s\n%d\n", temp->name, temp->usn, temp->branch, temp->sem);
        free(temp);
        first = NULL;
    }
    else
    {
        printf("Deleted student is %s\n%s\n%s\n%d\n", temp->name, temp->usn, temp->branch, temp->sem);
        first = first->link;
        free(temp);
    }
    count--;
}
void display()
{
    if (first == NULL)
    {
        printf("List is empty\n");
        return;
    }
    else
    {
        temp = first;
        printf("The list contains:\n");
        while (temp != NULL)
        {
            printf("%s\n%s\n%s\n%d\n", temp->name, temp->usn, temp->branch, temp->sem);
            printf("---------------\n");
            temp = temp->link;
        }
        printf("\n");
    }
    printf("No of students =%d\n", count);
}
int main()
{
    int ch, n, i;
    printf("----------queue of students using list--------\n");
    printf("1.Create a sll queue of n students\n");
    printf("2.Display from beginning\n");
    printf("3.Insert at end\n");
    printf("4.Delete at front\n");
    printf("5.Exit\n");
    printf("---------------\n");
    while (1)
    {
        printf("Enter choice : \n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the number of students\n");
            scanf("%d", &n);
            for (i = 0; i < n; i++)
            {
                insert_end();
            }
            break;
        case 2:
            display();
            break;
        case 3:
            insert_end();
            break;
        case 4:
            delete_front();
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("Invalid choice \n");
        }
    }
    return 0;
}

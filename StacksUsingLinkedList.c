#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *link;
} *first = NULL, *temp = NULL, *last = NULL;

void create()
{
    int d;
    temp = malloc(sizeof(struct node));
    printf("enter the data :\n");
    scanf("%d", &d);
    temp->data = d;
    temp->link = NULL;
}
void insert_front()
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
        temp->link = first;
        first = temp;
    }
}
void delete_front()
{
    temp = first;
    if (first == NULL)
    {
        printf("list is empty;\n:");
        return;
    }
    else if (temp->link == NULL)
    {
        printf("the deleted elemen is %d ", temp->data);
        free(temp);
        first = NULL;
    }
    else
    {
        first = first->link;
        printf("the deleted element is %d", temp->data);
        free(temp);
    }
}
void display()
{
    temp = first;
    if (first == NULL)
    {
        printf("the list is empty\n");
        return;
    }
    else
    {
        printf("the elements of the list are:\n");
        while (temp != NULL)
        {
            printf("%d\t", temp->data);
            temp = temp->link;
        }
    }
}
void linear_search(int key)
{
    if (first == NULL)
    {
        printf("the list is empty\n");
        return;
    }
    else
    {
        temp = first;
        while (temp != NULL)
        {
            if (key == temp->data)
            {
                printf("search is successful\n");
                return;
            }
            temp = temp->link;
        }
    }
    printf("key not found\n");
}
int main()
{
    int ch, n, i, key;
    printf("--------Stack of integers using list--------\n");
    printf("-------------menu-------------\n");
    printf("1.create SLL stack of integers\n2.display\n3.insert_front\n4.delete_front\n5.linear  search\n6.exit\n");
    while (1)
    {
        printf("\nenter your choice:\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("enter the no of nodes:\n");
            scanf("%d", &n);
            for (i = 0; i < n; i++)
            {
                insert_front();
            }
            break;
        case 2:
            display();
            break;
        case 3:
            insert_front();
            break;
        case 4:
            delete_front();
            break;
        case 5:
            printf("enter the key to be searched:\n");
            scanf("%d", &key);
            linear_search(key);
            break;
        case 6:
            exit(0);
        default:
            printf("invalid choice");
        }
    }
    return 0;
}

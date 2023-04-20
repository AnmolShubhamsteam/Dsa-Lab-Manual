#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
    struct node* prev;
};
typedef struct node* NODE;
NODE insert_front(NODE head){
    NODE temp=(NODE)malloc(sizeof(struct node));
    int d;
    printf("Enter data ");
    scanf("%d",&d);
    temp->data=d;
    temp->next=NULL;
    temp->prev=NULL;
    if(head==NULL){
        return temp;
    }
    else{
        temp->next=head;
        head->prev=temp;
        return temp;
    }
}
NODE insert_rear(NODE head){
    NODE temp=(NODE)malloc(sizeof(struct node));
    NODE cur=head;
    int d;
    printf("Enter data ");
    scanf("%d",&d);
    temp->data=d;
    temp->next=NULL;
    temp->prev=NULL;
    if(head==NULL){
        head=temp;
        return head;
    }
    else
    {
        while(cur->next!=NULL){
            cur=cur->next;
        }
        cur->next=temp;
        temp->prev=cur;
    }
    return head;
}
NODE insertmid(NODE head,int pos){
    NODE temp=(NODE)malloc(sizeof(struct node));
    NODE cur=head;
    int d;
    printf("Enter data ");
    scanf("%d",&d);
    temp->data=d;
    temp->next=NULL;
    temp->prev=NULL;
    if(head==NULL){
        return temp;
    }
    else{
        if(pos==1){
            temp->next=head;
            head->prev=temp;
            return temp;
        }
        for (int i = 1; i <pos-1; i++)
        {
            cur=cur->next;
            if(cur==NULL){
                printf("insertion not possible ");
                return head;
            }
        }
        temp->next=cur->next;
        cur->next=temp;
        temp->prev=cur;
        return head;
}
}
NODE delete_rear(NODE head){
    if(head==NULL){
        printf("Empty");
        return NULL;
    }
    if(head->next==NULL){
        return NULL;
    }
    NODE cur=head;
    while(cur->next!=NULL){
        cur=cur->next;
    }
    NODE pre=cur->prev;
    pre->next=NULL;
    free(cur);
    return head;
}
NODE delete_front(NODE head){
    if(head==NULL){
        printf("Empty ");
        return NULL;
    }
    if(head->next==NULL)
    {
        return NULL;
    }
    else{
        NODE temp=head;
        head=head->next;
        head->prev=NULL;
        free(temp);
        return head;
    }
}
NODE concat(NODE head,NODE secondhead)
{
    if(head==NULL){
        printf("Empty");
        return head;
    }
    NODE temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=secondhead;
    secondhead->prev=temp;
    return head;
}
int search(NODE head,int key){
    NODE cur=head;
    int c=1;
    if(head==NULL){
        return -1;
    }
    else{
        while(cur!=NULL){
            if(cur->data==key)
            {
                return c;
            }
            cur=cur->next;
            c=c+1;
        }
        return -1;
    }
}
void print(NODE head){
    NODE temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
}
int main(){
    NODE head=NULL;
    for (int i = 0; i < 5; i++)
    {
        head=insert_rear(head);
    }
    print(head);
    printf("\n");
    NODE secondhead=NULL;
    // for (int i = 0; i < 5; i++)
    // {
    //     secondhead=insert_rear(secondhead);
    // }
    // head=concat(head,secondhead);
    // print(head);
    // int key;
    // printf("Enter ele you want to search ");
    // scanf("%d",&key);
    // if(search(head,key)==-1){
    //     printf("Key not found");
    // }
    // else{
    //     printf("Key found at index %d",search(head,key));
    // }
    // printf("\n");
    // for (int i = 0; i < 5; i++)
    // {
    //     head=insert_front(head);
    // }
    // print(head);
    // printf("\n");
    // head=delete_rear(head);
    // head=delete_rear(head);
    // printf("\n");
    // print(head);
    // printf("\n");
    // head=delete_front(head);
    // head=delete_front(head);
    // print(head);
    printf("\n");
    head=insertmid(head,2);
    head=insertmid(head,3);
    print(head);
    return 0;
}
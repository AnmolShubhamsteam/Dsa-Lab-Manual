#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int size=50;
struct node{
    int Data;
    struct node* left;
    struct node* right;
};
typedef struct node* NODE;
void push(NODE item,int *top,NODE s[])
{
    if(*top==size-1){
        printf("Stack overflow \n");
        return ;
    }
    *top=*top+1;
    s[*top]=item;
}
NODE pop(int *top,NODE s[]){
    NODE item;
    if(*top==-1){
        return -1;
    }
    item=s[*top];
    *top=*top-1;
    return (item);
}
NODE create_exp_tree(char postfix[]){
    NODE s[size],temp;
    int i,n,top;
    char symbol;
    top=-1;
    n=strlen(postfix);
    for (int i=0;i<n; i++)
    {
        symbol=postfix[i];
        if(symbol=='+'||symbol=='-'||symbol=='*'||symbol=='/'||symbol=='%'||symbol=='^'||symbol=='$')
        {
            temp=(NODE)malloc(sizeof(struct node));
            temp->Data=symbol;
            temp->right=pop(&top,s);
            temp->left=pop(&top,s);
            push(temp,&top,s);
        }
        else
        {
            temp=(NODE)malloc(sizeof(struct node));
            temp->Data=symbol-'0';
            temp->right=NULL;
            temp->left=NULL;
            push(temp,&top,s);
        }
    }
    return(pop(&top,s));
}
int evaluate(NODE root){
    if(root->left==NULL&&root->right==NULL){
        return root->Data;
    }
    if(root->Data=='+'){
        return(evaluate(root->left)+evaluate(root->right));
    }
    else if(root->Data=='-'){
        return(evaluate(root->left)-evaluate(root->right));
    }
    else if(root->Data=='*'){
        return(evaluate(root->left)*evaluate(root->right));
    }
    else if(root->Data=='/'){
        return(evaluate(root->left)/evaluate(root->right));
    }
    else if(root->Data=='%'){
        return(evaluate(root->left)%evaluate(root->right));
    }
    else if(root->Data=='^'){
        return((int)pow(evaluate(root->left),evaluate(root->right)));
    }
}
int main(){
    int res;
    NODE root=NULL;
    char postfix[50];
    printf("Enter Expression\n");
    scanf("%s",postfix);
    root=create_exp_tree(postfix);
    res=evaluate(root);
    printf("%d ",res);
    return 0;
}
// Given an array of elements, construct a complete binary tree from this array in level order 
// fashion. That is, elements from left in the array will be filled in the tree level wise starting 
// from level 0. Ex: Input : arr[] = {1, 2, 3, 4, 5, 6}
// Output : Root of the following tree
// 1
// / \
// 2 3
// / \ /\
// 4 5 6
#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *left;
struct node* right;
};
typedef struct node * NODE;
int max(int a, int b)
{
if(a>b){
return a;
}
else{
return b;
}
}
int height(NODE root)
{
if(root == NULL)
return 0;
else
return( max( height(root->left), height(root->right) ) + 1);
}
void printcurretLevel(NODE root,int level){
    if(root==NULL){
        return;
    }
    if(level==1){
        printf("%d ",root->data);
    }
    else if(level>1){
        printcurretLevel(root->left,level-1);
        printcurretLevel(root->right,level-1);
    }
}
void printLevelOrder(NODE root){
    int h=height(root);
    for (int i=1; i <=h; i++)
    {
        printcurretLevel(root,i);
        printf("\n");
    }
    
}
NODE newNode(int data){
    NODE Node;
    Node=(NODE)malloc(sizeof(NODE));
    Node->data=data;
    Node->left=NULL;
    Node->right=NULL;
    return Node;
}
NODE insertlevelOrder(int arr[],int i,int n,NODE root)
{
    if(i<n){
        NODE temp;;
        temp=newNode(arr[i]);
        root=temp;
        root->left=insertlevelOrder(arr,2*i+1,n,root->left);
        root->right=insertlevelOrder(arr,2*i+2,n,root->right);
    }
    return root;
}
int main(){
    int size;
    printf("Enter size");
    scanf("%d",&size);
    int arr[size];
    printf("Enter elements in array");
    for(int i = 0; i < size; ++i) 
    {
     scanf("%d", &arr[i]);
    }
    NODE root=insertlevelOrder(arr,0,size,root);
    printf("\n");
    printf("Level order traversal \n");
    printLevelOrder(root);
    return 0;
}

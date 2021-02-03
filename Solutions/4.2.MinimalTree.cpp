#include <stdio.h>
class Node{
public:
  int data;
  Node* left=NULL;
  Node* right=NULL;
};
class Tree{
public:
    Node * top=NULL;
};
Node* arrToBST(int arr[], int l, int r){
    if(l>r)
        return NULL;
    int mid=(r+l+1)/2;
    Node * node=new Node();
    node->data=arr[mid];
    node->left=arrToBST(arr,l,mid-1);
    node->right=arrToBST(arr,mid+1,r);
    return node;
    
}
void preOrder(Node* node)  
{  
    if (node == NULL)  
        return;  
    printf("%d  ",node->data);
    preOrder(node->left);  
    preOrder(node->right);  
} 
int main()
{
    int n=8;
    int arr[n]={5,4,3,8,6,12,15,7};
    Tree * t= new Tree();
    printf("Hello World\n");
    t->top=arrToBST(arr,0,n-1);
    preOrder(t->top);
    return 0;
}

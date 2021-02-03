#include <stdio.h>
#include<bits/stdc++.h> 
#define COUNT 2 
#define MAX 1000 
#define MIN -1000
using namespace std;
class Node{
public:
  int data;
  Node* left=NULL;
  Node* right=NULL;
};
class Tree{
public:
    Node * top=new Node();
};
void arrToTree(int arr[], int l, int r, Node* node){
    if(l>r)
        return;
    int mid=(r+l+1)/2;
    node->data=arr[mid];
    if(l<=mid-1){
        node->left=new Node();
        arrToTree(arr,l,mid-1,node->left);
    }
    if(mid+1<=r){
        node->right=new Node();
        arrToTree(arr,mid+1,r,node->right);
    }
}

void checkBSTHelper(Node* node, int* flag, int max, int min)
{
    if(node!=NULL){
        checkBSTHelper(node->left,flag,node->data,min);
        if(node->data>max || node->data<=min)
            *flag=1;
        checkBSTHelper(node->right,flag,max,node->data);
    }
}
int checkBST(Node* node)
{
    int flag=0;
    checkBSTHelper(node,&flag,MAX,MIN);
    flag>0?printf("Not BST"):printf("BST");
}

Node* newNode( int data){
    Node* node=new Node();
    node->data=data;
    return node;
}

void print2DUtil(Node *root, int space)  
{  
    if (root == NULL)  
        return;  
    space += COUNT;  
    print2DUtil(root->right, space);  
    cout<<endl;  
    for (int i = COUNT; i < space; i++)  
        cout<<" ";  
    cout<<root->data;  
    print2DUtil(root->left, space);  
}  
void print2D(Node *root)  
{   
    print2DUtil(root, 0);  
}  

int main()
{
    int n=9;
    int arr[n]={1,2,3,4,5,6,7,8,9};
    Tree * t= new Tree();
    // arrToTree(arr,0,n-1,t->top);
    Node * node=t->top;
    node->data=4;
    node->left=newNode(3);
    node->left->left=newNode(3);
    node->right=newNode(8);
    node->right->left=newNode(7);
    node->right->right=newNode(10);
    node->right->right->left=newNode(9);
    // t->top = insertLevelOrder(arr, t->top, 0, n);
    print2D(node);
    printf("\n");
    checkBST(t->top);
    // printf("\n");
    return 0;
}

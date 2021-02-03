#include <stdio.h>
#include<bits/stdc++.h> 
#define COUNT 5 
#define MAX 1000 
#define MIN -1000
using namespace std;
class Node{
public:
  int data;
  Node* left=NULL;
  Node* right=NULL;
  Node* parent=NULL;
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
        node->left->parent=node;
        arrToTree(arr,l,mid-1,node->left);
    }
    if(mid+1<=r){
        node->right=new Node();
        node->right->parent=node;
        arrToTree(arr,mid+1,r,node->right);
    }
}

Node* newNode( int data, Node* parent){
    Node* node=new Node();
    node->data=data;
    node->parent=parent;
    return node;
}

void print2DUtil(Node *root, int space){  
    if (root == NULL)  
        return;  
    space += COUNT;  
    print2DUtil(root->right, space);  
    cout<<endl;  
    for (int i = COUNT; i < space; i++)  
        cout<<" ";
    int parentData=0;
    if(root->parent!=NULL)
        parentData=root->parent->data;
    cout<<root->data<<"("<<parentData<<")";  
    print2DUtil(root->left, space);  
}  

void print2D(Node *root){   
    print2DUtil(root, 0);  
}  

void check(Node* node, Node* a, Node*b, int* flag){
    if(node==NULL)
        return;
    if(node==a || node==b)
        *flag+=1;
    check(node->left,a,b,flag);
    check(node->right,a,b,flag);
    
}

void commonAncesterUtil(Node* node, Node* a, Node*b, Node* common){
    if(node==NULL)
        return;
    if(node==a || node==b){
        common=node==a?a:b;
        return;
    }
    int flag=-1;
    
    check(node->left,a,b,&flag);
    
    switch(flag)
    {
        case -1:
            commonAncesterUtil(node->right,a,b,common);
            break;
        case 0:
            common=node;
            break;
        case 1:
            commonAncesterUtil(node->left,a,b,common);
            break;
        
    }
    
        
}

Node* commonAncester(Node* node, Node* a, Node*b){
    Node* common=NULL;
    commonAncesterUtil(node, a, b, common);
}

int main()
{
    int n=9;
    int arr[n]={1,2,3,4,5,6,7,8,9};
    Tree * t= new Tree();
    Node * root=t->top;
     
    // arrToTree(arr,0,n-1,root);
   
    
    root->data=4;
    root->left=newNode(3,root);
    root->left->left=newNode(3,root->left);
    root->right=newNode(8,root);
    root->right->left=newNode(7,root->right);
    root->right->right=newNode(10,root->right);
    root->right->right->left=newNode(9,root->right->right);
    
    print2D(root);
    printf("\n");
    Node* a=root->right->left;
    Node* b=root->right->right->left;
    
    Node* common=commonAncester(root,a,b);
    printf("\n");
    printf("%d,%d=%d",a->data,b->data,common->data);
    

    return 0;
}

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



void inorderSuccessorUtil(Node* given, Node* node, int* next, int* flag)
{
    if(node!=NULL){
        inorderSuccessorUtil(given,node->left,next,flag);
        if(*flag==1)
        {
            *flag=0;
            *next=node->data;
        }
        if(given==node)
            *flag=1;
        
        inorderSuccessorUtil(given,node->right,next,flag);
    }
}
int inorderSuccessor(Node* given,Node* node)  //Root node given here
{
    int next=MAX;
    int flag=0;
    inorderSuccessorUtil(given,node,&next,&flag);
    return next;
}

int inorderSuccessor(Node* node)  //Root node not given,so using parent link 
{
    if(node==NULL)
        return 0;
    Node* temp;
    if(node->right!=NULL)
    {
        temp=node->right;
        while(temp->left!=NULL)
            temp=temp->left;
        return temp->data;
    }
    temp=node;
    while(temp->parent!=NULL && temp->parent->left!=temp)
    {
        temp=temp->parent;
    }
    return temp->parent->data;
}


Node* newNode( int data, Node* parent){
    Node* node=new Node();
    node->data=data;
    node->parent=parent;
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
    int parentData=0;
    if(root->parent!=NULL)
        parentData=root->parent->data;
    cout<<root->data<<"("<<parentData<<")";  
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
    Node* find=root->left->left;
    printf("%d\n",inorderSuccessor(find,root));
    printf("%d\n",inorderSuccessor(find));
    

    return 0;
}

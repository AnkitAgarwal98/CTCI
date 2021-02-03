#include <stdio.h>
#include<bits/stdc++.h> 
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
void preOrder(Node* node)  
{  
    if (node == NULL)  
        return;  
    printf("%d  ",node->data);
    preOrder(node->left);  
    preOrder(node->right);  
}
void listOfDepths(Node* node, vector<vector <int>> &lists, int counter)
{
    if (node == NULL)  
        return;
    if(lists.size()<=counter)
    {
        lists.push_back({});
    }
    lists[counter].push_back(node->data);
    listOfDepths(node->left,lists,counter+1);
    listOfDepths(node->right,lists,counter+1);
}
int main()
{
    int n=7;
    int arr[n]={5,4,2,3,8,6,9};
    Tree * t= new Tree();
    arrToTree(arr,0,n-1,t->top);
    vector<vector<int>> lists;
    listOfDepths(t->top,lists,0);
    // lists.push_back({1,5,6});
    // lists.push_back({18,2});
    // lists[1].push_back(4);
    for(int i=0;i<lists.size();i++)
    {
            for(int j=0; j<lists[i].size();j++)
            {
                printf("%d  ",lists[i][j]);
            }
            printf("\n");
    }
    return 0;
}

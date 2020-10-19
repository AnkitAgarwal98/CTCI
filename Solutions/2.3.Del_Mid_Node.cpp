#include <stdio.h>
#include <iostream>
#include <bits/stdc++.h> 
using namespace std; 
class Node{
    public:
        int data;
        Node* next=NULL;
};
void printList(Node* n) 
{ 
    while (n != NULL) { 
        cout << n->data << " "; 
        n = n->next; 
    } 
}
Node* arr2ll(int arr[],int n)
{
    int i;
    Node * start = new Node();
    Node * p=start;
    p->data=arr[0];
    for (i=1;i<n;i++){
        p->next=new Node();
        p=p->next;
        p->data=arr[i];
    }
    return start;
}
void del(Node* b)
{
    if(b==NULL)
        return;
    Node * c =b->next;
    b->data=c->data;
    b->next=c->next;
    
}
int main()
{
    int arr[]={10,20,10,30,20,10,50};
    int k=1;
    int n = sizeof(arr)/sizeof(arr[0]),i=0;
    Node * start = arr2ll(arr,n);
    //To get address of element k
    Node * b=start;
    for(i=0;i<k-1;i++)
    {
        if(b==NULL)
            break;
        b=b->next;
    }
    
    printList(start);
    cout << "\n";
    del(b);
    printList(start);
    
    
    
}

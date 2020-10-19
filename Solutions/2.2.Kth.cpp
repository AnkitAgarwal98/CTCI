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
Node* kth1(Node* start, int k)
{
    Node *p1=start;
    Node *p2=start;
    for(int i=0;i<k;i++)
        p2=p2->next;
        
    while(p2!=NULL)
    {
        p2=p2->next;
        p1=p1->next;
    }
    return p1;
}
Node* kth2(Node* head, int k, int * i)
{
    if(head==NULL)
        return NULL;
    Node * p =kth2(head->next,k, i);
    (*i)++;
    if(*i==k)
        return head;
    return p;
}

int main()
{
    int arr[]={10,20,10,30,20,10,50};
    int k=3;
    int n = sizeof(arr)/sizeof(arr[0]),i=0;
    Node * start = arr2ll(arr,n);
    
    printList(start);
    cout << "\n";
    cout << kth1(start,k)->data;  //Iterative method using runner in O(n) time
    cout << "\n";
    cout << kth2(start,k,&i)->data;  //Recursive method 
    
    
    
}

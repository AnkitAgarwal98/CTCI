#include <stdio.h>
#include <iostream>
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
void partition1(Node * start, int x)
{
    Node * p1=start;
    Node * p2=p1;
    int temp;
    while(1)
    {
        while(p1->data<x){
            if(p1->next==NULL) return;
            p1=p1->next;
        }
        p2=p1;
        while(p2->data>=x){
            if(p2->next==NULL) return;
            p2=p2->next;
        }
        temp=p1->data;
        p1->data=p2->data;
        p2->data=temp;
    }
}
int main()
{
    int arr[]={5,9,11,7,9,2,9};
    int x=9;
    int n = sizeof(arr)/sizeof(arr[0]),i;
    Node * start = arr2ll(arr,n);
    printList(start);
    cout << "\n";
    
    partition1(start,x);
    printList(start);
    

}

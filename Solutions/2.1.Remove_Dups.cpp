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
void check(Node * p1, int elem)
{
    Node * p2=p1;
    while(p2->next!=NULL)
    {
        if(p2->next->data==elem)
            p2->next=p2->next->next;
        else
            p2=p2->next;
    }
}
void removeDups1(Node * start)
{
    Node * p1=start;
    while(p1->next!=NULL)
    {
        check(p1,p1->data);
        p1=p1->next;
    }
}

void removeDups2(Node * start)
{
    Node * p1=start;
    unordered_set<int> intSet;
    intSet.insert(p1->next->data);
    while(p1->next!=NULL)
    {
        if(intSet.find(p1->next->data)==intSet.end()) 
        // .find() : If found, returns that index, if not found then returns end
        {
            intSet.insert(p1->next->data);
            p1=p1->next;
        }
        else
        {
            
            p1->next=p1->next->next;
        }
    }
}

int main()
{
    int arr[]={10,20,10,30,20,10,50};
    int n = sizeof(arr)/sizeof(arr[0]),i;
    Node * start = arr2ll(arr,n);
    
    printList(start);
    cout << "\n";
    
    //removeDups1(start);   //Doesn't use additional space but O(n^2) time
    
    removeDups2(start); //Uses hash set to have O(1)
    
    printList(start);
    
    
    

}

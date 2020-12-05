#include <stdio.h>
#include <bits/stdc++.h>
using namespace std; 
class Node{
public:
	int data;
	int min;
	Node * next=NULL;
};

class Stack{
private:
	int size=0;
	Node * head;
public:
	void push(int elem)
	{
	    size++;

	    if(head==NULL)
	    {
			head=new Node();
			head->data=elem;
			head->min=elem;
			head->next=NULL;
	    }
	    else{

            Node* node=new Node();
            node->data=elem;
            node->min=elem<head->min?elem:head->min;
            node->next=head;
            head=node;
            
            
	    }
	    
	}
	bool pop()
	{
	    if(head==NULL)
	    {
	        printf("Empty");
	        return false;
	    }
	    else{    
	       	Node * next =head;
	    	head=head->next;
	    	free(next);
	        return true;
	    }
	}
	void show()
	{
		if(head==NULL){
	        printf("Empty");
	    }
	    else{    
	        Node * temp=head;
	        while(temp!=NULL)
	        {
	        	printf("%d  ",temp->data);
	        	temp=temp->next;
	        } 
	        printf("\n");
	    }
	}
	void min()
	{
	    if(head==NULL){
	        printf("Empty");
	        return;
	    }
	    printf("%d",head->min);
	}
};





int main()
{
	    
    Stack * myStack=new Stack();
    
    myStack->push(25);
    myStack->push(19);
    myStack->push(11);
    myStack->push(38);
    myStack->pop();
    myStack->push(95);
    myStack->push(3);
    myStack->push(18);
    myStack->push(68);
    myStack->pop();
    myStack->pop();
    myStack->push(99);
    myStack->pop();
    myStack->pop();
    myStack->show();
    myStack->min();

    return 0;
}

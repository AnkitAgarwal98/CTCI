#include <stdio.h>
#include <bits/stdc++.h>
#define MAX 4
using namespace std; 
class Node{
public:
	int arr[MAX+1]={0};
	Node * next=NULL;
};

class Stack{
private:
	Node * head=new Node();
	int numberOfArr=0;
public:
	void push(int elem)
	{
	    if(head->arr[0]==MAX)
	    {
			Node* node=new Node();
            node->arr[node->arr[0]+1]=elem;
            node->arr[0]++;
            node->next=head;
            head=node;
	    }
	    else{
            head->arr[head->arr[0]+1]=elem;
            head->arr[0]++;
            
            
	    }
	    
	}

	bool pop()
	{
	    if(head->arr[0]==0)
	    {
	        printf("Empty");
	        return false;
	    }
	    else{    
	       	
	       	head->arr[head->arr[0]]=0;
	       	head->arr[0]--;
	       	
	       	if(head->arr[0]==0){
    	       	Node * next =head;
    	    	head=head->next;
    	    	free(next);	       	    
	       	}

	        
	        
	        return true;
	    }
	}
	void show()
	{
	        Node * temp=head;
	        while(temp!=NULL)
	        {
	            for(int i=temp->arr[0];i>=1;i--)
	        	    printf("%d  ",temp->arr[i]);
	        	temp=temp->next;
	        	printf("\n");
	        } 
	    
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

    myStack->show();

    return 0;
}

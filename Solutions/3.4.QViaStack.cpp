#include <bits/stdc++.h> 
using namespace std; 
class MyQueue{
private:
	stack <int> s1;
	stack <int> s2;
public:
    void add(int elem)
    {
        s1.push(elem);
    }
    void del()
    {
        if(s2.empty())
        {
            int x;
            while(!s1.empty())
            {
                x=s1.top();
                s1.pop();
                s2.push(x);
            }
        }
        s2.pop();
    }
    int peek()
    {
        if(s2.empty())
        {
            int x;
            while(!s1.empty())
            {
                x=s1.top();
                s1.pop();
                s2.push(x);
            }
        }
        return s2.top();
    }

};

int main () 
{ 
	MyQueue * q =new MyQueue();
	q->add(10); 
	q->add(30); 
	q->add(20); 
	q->add(5); 
	q->add(1);
	q->del();
    printf("%d",q->peek());
	return 0; 
} 

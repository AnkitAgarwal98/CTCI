#include <stdio.h>
#include <math.h>
#include<bits/stdc++.h> 
#define MAXBITS 32
using namespace std;
int main()
{
    int num=1775;
    
    int i=0;
    int max=1;
    int prev=0;
    
    while(num>0)
    {
        if((num&1)==1)
            i++;
        else{
            if((num&2)==0)
                i=0;
            else{
                prev=i;
                i=0;
            }
        }
        
        max=max>i+prev+1?max:i+prev+1;
        
        num=num>>1;
    }
    
    printf("%d",max);
    
}

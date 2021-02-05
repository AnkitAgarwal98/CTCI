#include <stdio.h>
#include <math.h>
#include<bits/stdc++.h> 
#define MAXBITS 32
using namespace std;

int main()
{
    for (int n = 0; n <= 32; n++) {
        int e=n & (n-1);
        printf("n=%d,n&(n-1)=%d =>%d\n",n,e, e==0);
    }
    
    //Returns true if n is power of 2 or 0, else returns false
    
}

#include <stdio.h>
#include <math.h>
#include<bits/stdc++.h> 
#define MAXBITS 32
using namespace std;

int swap(int n){
    return (((n & 0xaaaaaaaa)>>1) | ((n & 0x55555555)<<1));
}
int main()
{
    int n=5;
    printf("%d",swap(n));
    
    
}

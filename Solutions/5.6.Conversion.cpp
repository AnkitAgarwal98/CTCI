#include <stdio.h>
#include <math.h>
#include<bits/stdc++.h> 
#define MAXBITS 32
using namespace std;

int getDifferentBits(int A, int B){
    int i=0;
    int count=0;
    
    while(i<MAXBITS){
        int currentBitA= (A & (1<<i))!=0;
        int currentBitB= (B & (1<<i))!=0;    
        if(currentBitA!=currentBitB){
            count++;
        }
        i++;
    }
    return count;
}
int main()
{
    int A=29,B=15;
    int bits=getDifferentBits(A,B);
    
    
    printf("%d , %d -> %d",A,B,bits);
    
    
}

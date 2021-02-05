#include <stdio.h>
#include <math.h>
#include<bits/stdc++.h> 
#define MAXBITS 32
using namespace std;
int getBigger(int num){
    int i=1;
    int currentBit,prevBit;
    while(pow(2,i-1)<=num){
        currentBit=pow(2,i);
        prevBit=currentBit/2;
        if((num & currentBit)/currentBit==1){
            i++;
        }
        else{
            if((num & prevBit)/prevBit==1){
                num=num | currentBit;
                num=~(~num | prevBit);
                break;
            }
            else{
                i++;
            }
        }
    }
    return num;
}
int getSmaller(int num){
    int i=1;
    int currentBit,prevBit,nextBit;
    while(pow(2,i)<=num){
        currentBit=pow(2,i);
        
        prevBit=currentBit/2;
            
        if((num & currentBit)/currentBit==0){
            i++;
        }
        else{
            if((num & prevBit)/prevBit==0){
                num=num ^ currentBit;
                num=(num ^ prevBit);
                break;
            }
            else{
                i++;
            }
        }
    }
    return num;
}
int main()
{
    int num=7;
    int big=getBigger(num);
    int small=getSmaller(num);
    
    
    printf("%d<%d<%d",small,num,big);
    
    
}

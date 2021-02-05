#include <stdio.h>
#include <math.h>
#include<bits/stdc++.h> 
#define MAXBITS 32
using namespace std;
int main()
{
    double decimal=0.625;
    char bin[MAXBITS+1];
    int i;
    for(i=0;i<=MAXBITS;i++)
    {
        if(decimal==0)
            break;
        decimal*=2;
        if(decimal>=1){
            decimal--;
            bin[i]='1';
        }
        else
            bin[i]='0';
        
    }
    if(i>MAXBITS)
        printf("ERROR");
    else{
        bin[i]='\0';
        printf("0.%s",bin);
    }
        
    
}

#include <stdio.h>
#include <math.h>
#include<bits/stdc++.h> 

using namespace std;
int length(char c[33]){
    int count;
    for(count=0;c[count]!='\0';count++){}
    return count;
}

int binToInt(char c[33]){
    int i,num=0;
    
    int len=length(c);
    for(i=len-1;i>=0;i--)
        if(c[i]=='1')
            num=num+pow(2,(len-i-1));
    return num;
    
}
int main()
{
    char M[33]="10000110000";
    char N[33]="10011";
    int lenM=length(M);
    int m=binToInt(M);
    int n=binToInt(N);
    int i=2,j=6;
    int count;
    //For string input
    // for(count=0;count<=lenM-i-1;count++){
    //     if(count>=lenM-j-1)
    //         M[count]=N[count-lenM+j+1];
    // }
    // printf("%d\n",count);
    // printf("%s\n",M);
    // printf("%d\n",binToInt(M));
    //For int input
    int clearer=0;
    for(count=0;count<=lenM-1;count++){
        if(count<i || count>j)
            clearer=clearer+pow(2,count);
    }
    
    int mFinal=(m&clearer)|(n<<i);
    printf("%d\n",mFinal);
    
    
    
    
}

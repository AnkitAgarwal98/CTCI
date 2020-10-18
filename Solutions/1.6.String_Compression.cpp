
#include <stdio.h>

int main()
{
    char s1[]="aabcccccaaa";
    int n=0;
    int i=0,j=0,k=0;
    while(s1[n]!='\0'){
        n++;
    }
    char s2[2*n+1];
    while(i<n){
        j=i;
        while(s1[j]==s1[j+1])
            j++;
        s2[k]=s1[i];
        s2[k+1]=j-i+1+48;
        k+=2;
        j++;
        i=j;
    }
    s2[k]='\0';
    if(k<n)
        printf("%s",s2);
    else
        printf("%s",s1);
}

#include <stdio.h>

int main()
{
    char s[]="Mr John Smith    ";
    int n=0;
    while(s[n]!='\0'){
        n++;
    }
    int i=n-1, j=n-1;
    while(j>0){
        while(s[i]==' ')
            i--;
        while(s[i]!=' '){
            s[j]=s[i];
            s[i]=' ';
            j--;i--;
        }
        s[j]='0';s[j-1]='2';s[j-2]='%';
        j=j-3;i--;
        if(i==j)
            break;
    }
    
    
    printf("%d\n",n);
    printf("%s",s);
    return 0;
}
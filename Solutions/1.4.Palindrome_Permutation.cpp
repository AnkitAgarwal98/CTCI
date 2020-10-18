
#include <stdio.h>

int main()
{
    char s[]="Tact Coa";
    int n=0,i;
    int ans=0;
    while(s[n]!='\0'){
        n++;
    }
    int arr[26]={0};
    for(i=0;i<n;i++){
        if(s[i]>96 && s[i]<123)
            arr[s[i]-97]++;
        if(s[i]>64 && s[i]<91)
            arr[s[i]-65]++;
    }
    if(ans>1)
        printf("False");
    else
        printf("True");
    return 0;
}

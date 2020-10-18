
#include <stdio.h>

int main()
{
    char s1[]="gal";
    char s2[]="ale";
    int n1=0,n2=0;
    int i,j;
    
    while(s1[n1]!='\0'){
        n1++;
    }
    while(s2[n2]!='\0'){
        n2++;
    }
    int diff=n1-n2;
    if(diff>1 || diff<-1)
        return false;
        
    i=0;j=0;
    bool flag=true;
    while(i<n1 && j<n2){
        if(s1[i]==s2[j])
            i++,j++;
        else
            break;
    }
    if(diff==0){
        if(s1[i+1]==s2[j+1])
            i++,j++;
    }
    if(diff==1){
        if(s1[i+1]==s2[j])
            i++;
    }
    if(diff==-1){
        if(s1[i]==s2[j+1])
            j++;
    }
    while(i!=n1)
    {
        if(s1[i]!=s2[j])
            flag=false;
        i++,j++;
    }
    printf("%s",flag?"True":"False");
}

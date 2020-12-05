#include <stdio.h>
bool push(int arr[], int max, int elem, int stackNo)
{
    int last= arr[stackNo-1]*3 + (stackNo-1);
    if(last>=max)
    {
        printf("Full");
        return false;
    }
    else{
        arr[last+3]=elem;
        arr[stackNo-1]++;
        return true;
    }
    
}
bool pop(int arr[], int max, int stackNo)
{
    if(arr[stackNo-1]<1)
    {
        printf("Empty");
        return false;
    }
    else{    
        int last= arr[stackNo-1]*3 + (stackNo-1);
        arr[last]=0;
        arr[stackNo-1]--;
        return true;
    }
}
void show(int arr[], int max, int stackNo)
{
    if(arr[stackNo-1]<1)
        printf("Empty");
    else{    
        int last= arr[stackNo-1]*3 + (stackNo-1);
        for(int i=stackNo+2;i<=last;i+=3)
            printf("%d ",arr[i]);   
    }
}
int main()
{
    int max=12;
    int arr[max+3]={0};     //3 indexes ie 0,1,2 are used for size of each stack

    push(arr,max,5,1);
    push(arr,max,2,2);
    push(arr,max,9,2);
    push(arr,max,5,3);
    pop(arr,max,1);
    push(arr,max,6,2);
    push(arr,max,1,2);
    push(arr,max,3,2);
    pop(arr,max,1);    
    printf("\nArray is: \t");
    for(int i=0;i<max+3;i++)
        printf("%d ",arr[i]);
    printf("\nStack 1 is:\t"); 
    show(arr,max,1);
    printf("\nStack 2 is:\t"); 
    show(arr,max,2);
    printf("\nStack 3 is:\t"); 
    show(arr,max,3);
    
    




    return 0;
}

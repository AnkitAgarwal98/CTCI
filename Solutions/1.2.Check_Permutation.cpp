#include <string>
#include <iostream>
using namespace std;
bool isPerm(string s1, string s2)
{
    if(s1.length()!=s2.length())
        return false;
    int n=s1.length();
    int arr[256]={0};
    int s,i;
    for(i=0; i<n; i++)
    {
        s=s1[i];
        arr[s]++;
    }
    for(i=0; i<n; i++)
    {
        s=s2[i];
        arr[s]--;
        if(arr[s]<0)
            return false;
    }
    return true;
}
int main()
{
    cout<<isPerm("dcfdsv","dcfdvs");

    return 0;
}

#include <map>
#include <iostream>
#include <string>
using namespace std; 

int isUnique(string s)
{
	map <char,int> characters;
	int len=s.length();
	for(int i=0;i<len;i++)
	{
		if(characters[s[i]]==1)
			return -1;
		else
			characters[s[i]]=1;
	}
	return 0;
}

int main()
{

	cout<<isUnique("myname");
	return 0;
}

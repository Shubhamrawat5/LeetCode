#include<iostream>
using namespace std;

char findTheDifference(string s, string t) {
    int ans=0;
	int i;
	for(i=0;s[i]!='\0';++i)
	ans=ans^s[i];
	
	//cout<<ans<<endl;
	
	for(i=0;t[i]!='\0';++i)
	ans=ans^t[i];
	
	//cout<<ans; 
	return ans;
}

int main()
{
	string s="abcd",t="abcde";
	cout<<findTheDifference(s,t);
	
}
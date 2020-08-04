#include<iostream>
#include<map>
using namespace std;

int fuc(string s)
{
	map<char,int> m;
	int i;
	
	//adding count of each character of string
	for(i=0;s[i];++i) 
	m[s[i]]=m[s[i]]+1;
	
	//for(auto k:m)
	//cout<<k.first<<":"<<k.second<<endl;
	
	//now checking if any value count is 1 and if has then return that index
	for(i=0;s[i];++i)
	{
		if(m[s[i]]==1)
		return i;
	}
	return -1;
	
}

int main()
{
	string s="loveleeto";
	cout<<fuc(s);
}
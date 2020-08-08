#include<iostream>
#include<unordered_set>
using namespace std;

int LOLS(string s)
{
	int c=0,i,prev=0; //slinding window prev to i
	unordered_set<char> set;
	
	for(i=0;i<s.length();++i)
	{
		if(set.count(s[i])==0) //if new element is not present in set then insert and update count
		{
			set.insert(s[i]);
			c=c>set.size()?c:set.size();
		}
		else //new element is present in set
		{
			while(set.count(s[i])!=0) //till element get removed
			{
				set.erase(s[prev]); //removing window leftmost index element by prev variable
				++prev;
			}
			set.insert(s[i]); //now inserting new element
		}
	}
	return c;
}

int main()
{
	string s="abcabcbb";
	cout<<LOLS(s);	
}
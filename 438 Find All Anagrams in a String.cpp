#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;

vector<int> findAnagrams(string s, string p)
{
	vector<int> ans;
	if(s.size()<p.size()) return ans;
	
	//created 2 maps, mps for string s and mpp for string p
	unordered_map<char,int> mps,mpp;
	int i=0;
	for(i=0;i<p.size();++i) //counting both the elements of p & s seperately till size of p
	{
		++mpp[p[i]];
		++mps[s[i]];
	}
	
	
	if(mpp==mps) //if both hash keys values are same then anagram
  	 ans.push_back(0);
	
	for(i=p.size();i<s.size();++i) //now checking for remaining length of s
	{

		if(mps[s[i-p.size()]]>1) //if left most has value greater than 1 then only decreasing value by 1
			--mps[s[i-p.size()]];
			
		else  //otherwise deleteing the key from hash
			mps.erase(s[i-p.size()]);
	
		++mps[s[i]]; //now adding new element
		
		if(mps==mpp)  //if both are same then push
		{
			ans.push_back(i-p.size()+1);
		}
		
	}
	return ans;
}

int main()
{
	string s="abab";
	string p="ab";
	vector<int> ans=findAnagrams(s,p);
	for(auto k:ans)
	cout<<k<<" ";
}
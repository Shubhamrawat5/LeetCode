#include<iostream>
#include<vector>
using namespace std;

void gen(vector<string>& p,string s,int l,int r,int n)
{
	//cout<<s<<endl;
	if(s.length()==2*n) //if there are number of brackets equal to 2 times size n
	{
		p.push_back(s);
		return;
	}
	
	if(l<n) //adding left bracket first
	gen(p,s+"(",l+1,r,n);
	
	if(r<l) //after that filling right brackets
	gen(p,s+")",l,r+1,n);
}

vector<string> gP(int n)
{
	vector<string> p;
	if(!n) return p;
	
	gen(p,"",0,0,n);
	
	return p;
}

int main()
{
	int n=3;
	vector<string> v=gP(n);
	for(auto k:v)
	cout<<k<<" ";
}
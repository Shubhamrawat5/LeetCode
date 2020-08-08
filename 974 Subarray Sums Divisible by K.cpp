#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int sdbk(vector<int> A,int K)
{
	int c=0,i,prefixsum=0,rem=0; //rem is for reminder & prefixsum is for the sum of all previous elements
	unordered_map<int,int> mp;
	mp.insert({0,1}); 
	
	for(i=0;i<A.size();++i)
	{
		prefixsum+=A[i];
		
		//Below 2 lines same as rem=(prefixsum%K+K)%K to make rem positive
		rem=prefixsum%K;
		if(rem<0) rem+=K; //making reminder positive
		
		if(mp.count(rem)==1)
		{
			c+=mp[rem];
		}

		++mp[rem];
	 
	}
	return c;
}

int main()
{
	vector<int> v={-1,2,9};
	int k=2;
	cout<<sdbk(v,k);	
}
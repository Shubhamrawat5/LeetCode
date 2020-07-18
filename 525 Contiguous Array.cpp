#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int findMaxLength(vector<int>& nums) {
	int i;
	if(nums.empty()) return 0;
	
	nums[0]=nums[0]?1:-1;
	
	for(i=1;i<nums.size();++i)
	if(nums[i]==0) nums[i]=nums[i-1]-1;
	else nums[i]=nums[i-1]+1;
	
//	for(auto k:nums) cout<<k<<" ";
	unordered_map<int,int> mp;
	mp[0]=0;
	int m=0;
	for(i=0;i<nums.size();++i)
	{
		if(mp.find(nums[i])==mp.end())
			mp[nums[i]]=i+1;
		else
					m=max(m,i+1-mp[nums[i]]);		
	}
/*	for(auto k:mp) 
	cout<<k.first<<" "<<k.second<<endl;
	cout<<m;*/
	return m;
}

int main()
{
	vector<int> v={0,1,0};
	cout<<findMaxLength(v);
}
#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;

vector<int> twoSum(vector<int>& nums,int target)
{
	vector<int> ans;
	unordered_map<int,int> mp; //creating map
	int i=0;
	
	for(i=0;i<nums.size();++i)
	{
		if(mp.count(target-nums[i])==1) //checking if our (target - current) is present or not in prevoius index
		{
			ans.push_back(mp[target-nums[i]]);
			ans.push_back(i);
			break;
		}
		else //inserting key(value) and value(index)
		{
			mp[nums[i]]=i;
		}
	}
	return ans;
}

int main()
{
	vector<int> v={3,2,3};
	int n=6;
	vector<int> ans=twoSum(v,n);
	for(auto k:ans)
	cout<<k<<" ";
}
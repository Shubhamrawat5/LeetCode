#include<iostream>
#include<vector>
using namespace std;

vector<int> pes(vector<int>& nums)
{
	vector<int> ans(nums.size());
	ans[0]=nums[0];
	int mul=1,i;
	for(i=1;i<nums.size();++i) //making prefix multiply
		ans[i]=ans[i-1]*nums[i];
		
		
	//for i index if we have prefix and suffix multiply array then by prefix[i-1]*suffix[i+1] will be answer but here it is asked for constant space so making prefix in ans array and keeping track of suffix array value in mul variable
	for(i=nums.size()-1;i>0;--i)
	{

		if(i==nums.size()-1)
		{
			ans[i]=ans[i-1]; //for last index
			continue;
		}
		mul=mul*nums[i+1];
		ans[i]=ans[i-1]*mul;
	}
	mul=mul*nums[i+1]; //for first index
	ans[0]=mul;
	
	return ans;
}

int main()
{
	vector<int> v={1,2,3,4};
	vector<int> ans=pes(v);
	for(auto k:ans)
	cout<<k<<" ";
}
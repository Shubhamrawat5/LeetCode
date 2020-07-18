#include<iostream>
#include<vector>
using namespace std;

int findMaxConsecutiveOnes(vector<int>& nums) 
{
    int max,curr;
	max=curr=0;
	for(int i=0;i<nums.size();++i)
	{
		if(nums[i]==1) 
		{
			++curr;
		}
		else
		{
			if(max<curr) max=curr;
			curr=0;
		}
	}
	if(max<curr) max=curr;
	return max;
}

int main()
{
	vector<int> v={1,0,0,1,1,0,0,1,1,1,0,0,0};
	cout<<findMaxConsecutiveOnes(v);
}
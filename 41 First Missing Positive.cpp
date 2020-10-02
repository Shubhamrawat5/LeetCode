#include<iostream>
#include<vector>

using namespace std;

int firstMissingPositive(vector<int> nums)
{
	if(nums.size()==0) return 1;
	int i;
	for(i=0;i<nums.size();++i) //removing negative values
	{
		if(nums[i]<0) nums[i]=0;
	}
	
	//Logic: Using indexes to know if a value is there or not, marking value index as neg if present, lastly positive values index first will be the answer
	for(i=0;i<nums.size();++i)
	{
		int x=abs(nums[i]); //making value positive
		if(x>0 && x<=nums.size())
		{
			if(nums[x-1] > 0) //if value is positive then make its index value negative
				nums[x-1]=-nums[x-1];
			else if(nums[x-1] ==0 ) //if value is zero
				nums[x-1]=INT_MIN;
		}
	}
		
	for(i=0;i<nums.size();++i) //lastly checking first 0 or positive number and returning its index+1
		if(nums[i]>=0) return i+1;
	
	return i+1; //if every number was negative means it was like 1,2,3,4.. so on.. now returning last index+1
}

int main()
{
	vector<int> v={1,1};
	cout<<firstMissingPositive(v);
}
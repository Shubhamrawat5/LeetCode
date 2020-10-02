#include<iostream>
#include<vector>
using namespace std;

void sortColors(vector<int>& nums)
{
	int last=nums.size()-1;
	int start=0,find0; //2 pointers start and last
	while(start<last)
	{
		if(nums[start]==2)  //if 2 comes then throw it to the end
		{
			swap(nums[start],nums[last]);
			--last;
		}
		
		else if(nums[start]==0) //if 0 comes then move to next index
			++start;
			
		else //if 1 comes then find next 0 and swap with it
		{
			find0=start;
			while(find0<last && nums[find0]!=0)
				++find0;
			
			if(nums[find0]==0) //if 0 is found
			swap(nums[start],nums[find0]);
			else ++start; //if there is no zero ahead then move to next index
		}
	}
}


int main()
{
	vector<int> v={};
	sortColors(v);
	
	for(auto k:v)
		cout<<k<<" ";
}
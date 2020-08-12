#include<iostream>
#include<vector>
using namespace std;

int jump(vector<int>& nums)
{
	if(nums.size()<=2) return nums.size()-1;
	
	int i,j;
	int max=0; //to contain the good index value where we need to jump 
	int jumps=0; //to count jumps
	
	for(i=0;i<nums.size();) //iterating through the array
	{
		if(i==nums.size()) break; //if we are at the last index then directly break

		if(nums[i]>=nums.size()-1-i)  //if our current index can jump to the last index then add 1 jump and break
		{
			++jumps;
 			break;
		}
		
		max=i; //to contain the good index
		//Logic: Find a pair index with our current index which sum gives maximum value so that on going to that max index , we can have much higher indexes to see ahead
		for(j=i+1;j<=nums.size()&&j<=nums[i]+i;++j)
		{
			if(nums[j]+j-i > nums[max]+max-i) //here checking current pair with the max pair, j-1 is giving distance from i to j, max-i giving distance from i to max
				max=j;
		}
		
		i=max; //jumping to good index
		
		++jumps;
	}
	return jumps;
}

int main()
{
	vector<int> v={4,3,2,1,1,0};
	cout<<jump(v);
}
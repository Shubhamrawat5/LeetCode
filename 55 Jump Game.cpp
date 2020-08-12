#include<iostream>
#include<vector>
using namespace std;

bool canJump(vector<int>& nums)
{
	int i=0;
	int flag=1;
	while(i<nums.size()-1) //last index need not to be checked thats why -1
	{
		while(i<nums.size()-1 && nums[i]!=0) //find 0
		{
			++i;
		}
		
		if(i==nums.size()-1) break; //if we are at last index then vector is right so breal
		
		flag=0; 
		for(int j=i-1;j>=0;--j) //check previous
		{
			if(nums[j] > (i-j)) //this means we can jump ahead of index i that has 0 value
			{
				flag=1;
				break;
			}
		}
	
		if(flag==0) //means we was unable to jump ahead of index i which has 0 value
		break;
		
		++i;
	}
	
	return flag? true:false;
}

int main()
{
	vector<int> v={2,3,1,0,5,6};
	cout<<canJump(v);
}
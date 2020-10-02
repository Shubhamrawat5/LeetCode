#include<iostream>
#include<vector>
using namespace std;

int search(vector<int> nums,int target)
{
	if(nums.size()==0) return -1;
	int mid,l,r; 
	l=0,r=nums.size()-1;
	//Doing binary search
	//Logic:- when divided array into two parts then one part must come sorted form always
	//now check which is sorted array ,1st part or 2nd
	//then move to sorted part and check if target lies in sorted part then move to sorted part otherwise move to unsorted region
	while(l<=r)
	{
		mid=l+(r-l)/2;
		if(nums[mid]==target) return mid;
			
		if(nums[l]<=nums[mid]) //1st sorted
		{
			if(nums[l]<=target && nums[mid]>=target)
				r=mid-1;
			else 
				l=mid+1;						
		}
		else  //2nd half sorted
   	{
		if(nums[mid]<=target && nums[r]>=target)
				l=mid+1;
			else
				r=mid-1;
		}
	}
	return -1;
}

int main()
{
	vector<int> v={3,1};
	int k=3;
	cout<<search(v,k);
}
#include<iostream>
#include<vector>
using namespace std;

int findDuplicate(vector<int>& nums)
{
    //applying binary search (not with the values in array because it need sorted value but assuming a array of 1 to n-1 size and applying binary search on this, and firstsly checking if mid can be our ans or not, if not then move left or right by condition)
    int mid,left=1,right=nums.size()-1;
	
	while(left<=right) 
	{
		mid=left+(right-left)/2; //taking mid
		int less=0,greater=0; //now calculating total values in the array which are greater and less than in array with our mid 
		
		for(int i=0;i<nums.size();++i)
		{
			if(nums[i]>mid) ++greater;
			else if(nums[i]<mid) ++less;
		}
		
		if(mid-1>=less && nums.size()-1-mid>=greater) //now here if less digits are lesser and also greater digits are lesser than our mid number is repeating more than 1 times
			return mid;
			
		if(mid-1 < less) right=mid-1; //if less digits are higher than move to left side
		else left=mid+1; //otherwise right side
	}
	return -1;
}

int main()
{
	vector<int> v={2,5,3,2,4,1};
	cout<<findDuplicate(v);
}
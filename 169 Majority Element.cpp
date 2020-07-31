#include<iostream>
#include<vector>
using namespace std;

//Question can also be solved using maps

int majorityElement(vector<int>& nums)
{
	//sort the array and majority element would be always in mid
	sort(nums.begin(),nums.end());
	return(nums[nums.size()/2]);
}


int main()
{
	vector<int> v={3,3,2,5,2,3,3};
	cout<<majorityElement(v);
}
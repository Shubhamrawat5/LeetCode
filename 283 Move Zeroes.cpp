#include<iostream>
#include<vector>

using namespace std;

void moveZeroes(vector<int>& nums)
{
      int i,j=0;
      //using 2 pointers 
      //i for interation
      //j for the index of first 0 in the array so if other than 0 comes, swap it with first 0 index
      
      for(i=0;i<nums.size();++i)
      {
      	if(nums[i]!=0)
      	{
      		swap(nums[i],nums[j]);
      		++j;
      	}
      }
      
}


int main()
{
	vector<int> v={0,4,9,0,90};
	moveZeroes(v);
	for(auto k:v)
	cout<<k<<" ";
}
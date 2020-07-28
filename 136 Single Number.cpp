#include<iostream>
#include<vector>

using namespace std;

int singleNumber(vector<int>& nums)
{
      int n=0;
      for(int i=0;i<nums.size();++i)
      {
      	n=n^nums[i]; //using xor property
      }
      
      return n;
 }


int main()
{
	vector<int> v={5,4,7,5,7};
	cout<<singleNumber(v);
}
#include<iostream>
#include<vector>
using namespace std;

int removeDuplicates(vector<int>& nums)
{
        if(nums.size()<2) //if vector size is 0 or 1
        	return nums.size();
        	
        int count=1,j=0; 
        
        //Logic: 2 pointers technique
        //i is for iteration and j is for the index till where there aren't any duplicates
        //whenever found different element swap it with j+1 index
        for(int i=1;i<nums.size();++i)
            {
            if(nums[i]!=nums[j])
                {
                	++j;
         	       swap(nums[i],nums[j]);
	                ++count;
                }
            }
            
       return count;
        
 }


int main()
{
	vector<int> v={1,1,1,2,2,3,3,5,7,8,8};
	int n=removeDuplicates(v);
	cout<<n;
}
#include<iostream>
#include<vector>
#include<map>
using namespace std;

bool containsDuplicates(vector<int>& nums)
{
      if(nums.size()<1) return 0;
      map<int,int> m; //using hash table
      
      for(int i=0;i<nums.size();++i)
      {
         ++m[nums[i]]; //inserting element in hash with its count incrementing
         
         if(m[nums[i]]>1) 
         	return 1; //if count become greater than 1 that means there are duplicates
         
       /*for(auto k:m)
        cout<<k.first<<":"<<k.second<<" ";
        cout<<"\n";*/
      }
      return 0;
 }


int main()
{
	vector<int> v={0};
	cout<<containsDuplicates(v);
}
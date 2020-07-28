#include<iostream>
#include<vector>
#include<map>

using namespace std;

vector<int> intersect(vector<int>& nums1, vector<int> nums2)
{
      map<int,int> m; //using hash
      vector<int> inter; //interdection vector
      int i;
      
      //storing each element of nums1 in hash
      for(i=0;i<nums1.size();++i)
      	++m[nums1[i]];
      
      //checking each element of nums2 in hash, if available then add to vector and delete the element from hash.. hash checking is O(1)
      for(i=0;i<nums2.size();++i)
      	if(m.find(nums2[i])!=m.end())
      	{
      		inter.push_back(nums2[i]);
      		m.erase(nums2[i]);
      	}
      	
      return inter;
 }


int main()
{
	vector<int> v={9,9,2,7,5};
	vector<int> u={2,9,9,5};
	vector<int> inter=intersect(v,u);
	for(auto k:inter)
	cout<<k<<" ";
}
#include<iostream>
#include<vector>
using namespace std;

//using bayer moore candidate method
vector<int> majorityElement(vector<int>& nums)
{
	vector<int> ans;
	int can1,can2,count1,count2;
	//there will be atmost 2 majority element (maximum) so only 2 candidates can be there
	
	can1=can2=count1=count2=0;
	for(auto x:nums)
	{
		if(x==can1) ++count1; 
		else if(x==can2) ++count2;
		else if(count1==0) //there is no candidate 1 as count1 is 0
		{
			can1=x;
			++count1;
		}
		else if(count2==0) //there is no candidate 2 as count2 is 0
		{
			can2=x;
			++count2;
		}
		else //other than candidate a value come
		{
			--count1;
			--count2;
		}
		
	}
	
	//now we have two candidates so counting the occurence of these 2 candidates
	count1=count2=0;
	for(auto x:nums)
	{
		if(x==can1) ++count1;
		else if(x==can2) ++count2;
	}
	
	//now checking if occurrence greater than size/3 or not
	if(count1>nums.size()/3) 
		ans.push_back(can1);
		
	if(count2>nums.size()/3) 
		ans.push_back(can2);
	
	return ans;
}

int main()
{
	vector<int> nums={1,1,1,3,3,2,2,2};
	vector<int> ans=majorityElement(nums);
	for(auto k:ans)
	cout<<k<<" ";
}
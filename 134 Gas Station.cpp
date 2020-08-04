#include<iostream>
#include<vector>
using namespace std;

int cCC(vector<int>& gas,vector<int>& cost)
{
	
	int i;
	int behind=0; //to have previously all data
	int curr=0,ans=0; //curr for current data and ans is the index which can be a valid answer
	
	for(i=0;i<gas.size();++i)
	{
		curr+=(gas[i]-cost[i]); 
		if(curr<0) //if data gets negative then update behind and ans index
		{
			ans=i+1;
			behind+=curr;
			curr=0;
		}
		
	}
	if(curr+behind>=0) return ans; //lastly checking if behind + curr is greater than 0 or not if greater then ans index is valid answer
	return -1;
	
}

int main()
{
	vector<int> gas={2,3,10,4};
	vector<int> cost={3,4,4,3};
	cout<<cCC(gas,cost);
}
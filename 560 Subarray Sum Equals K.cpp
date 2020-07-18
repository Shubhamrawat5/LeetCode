#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

using namespace std;

int subarraySum(vector<int>& nums, int k) {
        int count=0,sum=0;
        unordered_map<int,int> un;
        un[0]=1;
        for(int i=0;i<nums.size();++i)
            {
              sum+=nums[i];
              if(un.find(sum-k)!=un.end())
                  {
                  count+=un[sum-k];
                  }
               un[sum]+=1;
            
            }
      return count;
 }


int main()
{
	vector<int> nums={1,1,1};
	int k=2;
	cout<<subarraySum(nums,k);
}
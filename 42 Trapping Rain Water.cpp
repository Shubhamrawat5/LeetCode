#include<iostream>
#include<vector>
using namespace std;


int trap(vector<int>&height)
{
      
          int n=height.size();
          if(n<=2) return 0;
          int lmax[n];
          int rmax[n];
          int ans=0;
          int i;
          
          //using prefix sum technique
          //creating 2 array left max and right max
          //then taking min value btw them
          lmax[0]=height[0];
          for(i=1;i<n;++i)
         lmax[i]=max(lmax[i-1],height[i]);
          
          rmax[n-1]=height[n-1];
          for(i=n-2;i>=0;--i)
         rmax[i]=max(rmax[i+1],height[i]);
          
          for(i=0;i<n;++i)
         ans+=min(lmax[i],rmax[i])-height[i];
	
return ans;
}  


int main()
{
	vector<int> v={0,1,0,2,1,0,1,3,2,1,2,1};
	cout<<trap(v);
}
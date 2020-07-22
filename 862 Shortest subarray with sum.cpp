#include<iostream>
#include<vector>
#include<deque>
using namespace std;

int shortt(vector<int> A,int K)
{
int n=A.size();
        int i;
        vector<int> dp(n+1,0);
        for(i=1;i<=n;i++) //calculate prefix sum to get sum btw consecutive elements in O(1)
        {
            dp[i]=dp[i-1]+A[i-1];
        }
        
        deque<int> q; //double ended queue
        int min_len=n+1;
        
        //logic: inserting index of prefix sum array in deque
        //only those index would be there in deque that can make a positive sum
        for(i=0;i<=n;i++)
        {
            /*for(auto k:q)
            cout<<k<<" ";
            cout<<endl;*/
            while(!q.empty()&&dp[i]-dp[q.front()]>=K) //if sum gets bigger than remove front
            {
                min_len=min(min_len,i-q.front());
                q.pop_front();
            }
            
            while(!q.empty()&&dp[i]-dp[q.back()]<=0) //if adding current element is making negative values with the last index of deque then remove it
            {
                q.pop_back();
            }
            q.push_back(i);
        }
        return (min_len==n+1)?-1:min_len;
}

int main()
{
	int k=167;
	vector<int> v={80,5,-37,32,40,95,-100};
	//{-34,37,51,3,-12,-50,51,100,-47,99,34,14,-13,89,31,-14,-44,23,-38,6};
	cout<<shortt(v,k);
}
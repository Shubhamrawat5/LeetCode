#include<iostream>
#include<vector>
using namespace std;

int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if(n<2) return 0; //need atleast 2 values
        
        int m=0,b=0,s=1,i; //b:buy s:sell
        for(i=1;i<n;++i) {
            
            if(prices[s]>prices[b])
                {
                m=max(m,prices[s]-prices[b]);
        
                }
             else b=s;
        s=i+1;
        }
        return m;
 }

int main(int argc, char *argv[])
{
	vector<int> v={7,1,5,3,2,6};
	cout<<maxProfit(v);
}
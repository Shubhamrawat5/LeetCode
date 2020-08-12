#include<iostream>
#include<vector>
using namespace std;

vector <int> countBits(int num)
{
	vector <int> ans;
	if(num<0) return ans;
	
	ans.push_back(0);
	int two; //for power of 2s
	int i; 
	
	/*Logic:- using dynamic programming
	generating a table from 0 to n and for every index i , use previous values available in table.
	find the 2s values like 1,2,4,8,16,32 as it has always 1 bits, now for number like 10 is 8+2 so number 8 has bits number 2 has 1 bits which we already found in table
	*/
	for(i=1;i<=num;++i)
	{
		if((i & (i-1)) ==0) two=i; //to find and update power of 2s
	
		ans.push_back(ans[i-two]+1); //now use last power of 2s no. of bit + remaining subtracted no. of bits by table
	}
	return ans;
}

int main()
{
	int n=10;
	vector<int> v=countBits(n);
	
	vector<int>::iterator it;
	for(it=v.begin();it!=v.end();++it)
		cout<<(*it)<<" ";
}
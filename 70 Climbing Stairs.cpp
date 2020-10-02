#include<iostream>
using namespace std;

int cal(int n,int dp[])
{
	if(n==1) return 1; 
	if(n==2) 
		return 2;
		
	if(dp[n]!=0) return dp[n];
	
	dp[n]=cal(n-1,dp)+cal(n-2,dp);
	return dp[n];
}

int climbStairs(int n)
{
	int dp[46]={0};
	return cal(n,dp);
}

int main()
{
	int n=5;
	cout<<climbStairs(n);
}
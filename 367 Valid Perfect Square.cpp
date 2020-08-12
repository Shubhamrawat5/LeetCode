#include<iostream>
using namespace std;

bool isPerfectSquare(int n)
{
	if(n<1) return false;
	if(n==1) return true;
	long long find;
	int l=1,r=n/2;
	while(l<=r) //binary search
	{
		find=l+(r-l)/2;
		if(find*find==n) return true;
		
		if(find*find<n)
			l=find+1;
			
		else
			r=find-1;
	}
	return false;
}

int main()
{
	int n=2000105819;
	cout<<isPerfectSquare(n);
}
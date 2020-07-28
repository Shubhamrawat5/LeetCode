#include<iostream>
using namespace std;

//Logic: A pattern is formed. ans is always going 1 to 9 then again 1 to 9 then again 1 to 9 and so on..

int addDigits(int num)
{
	if(num<10) return num;
	
	int ans=num%9;
	if(ans==0) return 9;
	return ans;
	
}

int main()
{
	int a=38;
	cout<<addDigits(a);
}
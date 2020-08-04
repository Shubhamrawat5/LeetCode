#include<iostream>
#include<vector>

using namespace std;

//using Sieve of eratosthenes method
int countPrimes(int n)
{
	if(n<3) return 0;
	
	vector<bool> v(n,true); //creating vector of n size with true value as everyone is prime
	int c=0,i;
	
	for(i=2;i<=n/2;++i)  //only checking for half the values
	{
		if(v[i]==true) //if current value is a prime
		{
			for(int j=i*2;j<n;j=i+j) //now eliminating values which are multiple of i as false
			{
				v[j]=false;
			}
		}
		
	}
	
	//now counting true values
	for(auto k:v)
	if(k==true) ++c;
	
	return c-2; //minus 2 because 0 & 1 are not prime
}

int main()
{
	int n=99790;
	cout<<countPrimes(n);
}
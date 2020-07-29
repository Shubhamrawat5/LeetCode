#include<iostream>
using namespace std;

uint32_t reversedBits(uint32_t n)
{
	if(n==0) return 0;
	
	unsigned int rev=0;
	int count=32; //to get 32 bit number
	while(n!=0)
	{
		--count;
		//cout<<n<<" ";
		if(n&1==1) //checking last bit of current n
		{
			rev=rev<<1; //if last bit was 1 then do left shift of 1 to rev and make last bit as 1 by ++rev
			++rev;
		}
		else rev=rev<<1; //if last bit was 0 then only do left shift of 1 to rev
		n=n>>1; //now do right shift to n by 1 and remove last bit
	}
	
	rev=rev<<count; //now adding remaining bits from 32
	return rev;
}


int main()
{
	unsigned int n=4294967293;
	cout<<reversedBits(n);
}
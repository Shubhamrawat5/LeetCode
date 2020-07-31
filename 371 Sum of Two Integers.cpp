#include<iostream>
using namespace std;

//using bitwise XOR for adding bits
//and bitwise AND & for calculating carry
//left shift << to move left
int getSum(int a, int b)
{
	int sum=a^b;
	int carry=a&b;
	
	carry=(unsigned)carry<<1; //unsigned type cast because shifting negative numbers is undesired behviour 
	
	while(carry)
	{
		a=sum;
		b=carry;
		sum=a^b;
		carry=a&b;
		carry=(unsigned)carry<<1;
	}
	return sum;
}

int main()
{
	int i=1;
	cout<<getSum(5,7);
}
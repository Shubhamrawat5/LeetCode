#include<iostream>
using namespace std;

bool isPowerOfFour(int num) {
       if(num<0) return 0;
       if((num&(num-1))!=0) 
    	{ return 0;  } //if in power of 2
   
   	int i=1;
   	while(num>0)
   	{
  	 	//cout<<((1<<i)&num);
			if((long)1<<i > num) break;
			num=num-(num&(1<<i));
			i=i+2;
	       //cout<<num&(1<<i)<<endl;
  	}
	
	if(num) return 1;
	return 0;
}


int main()
{
	int n=4;
	cout<<isPowerOfFour(n);
	
}
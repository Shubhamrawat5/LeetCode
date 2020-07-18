#include<iostream>
using namespace std;

int hammingDistance(int x, int y) {
    int ans=0;
	int i=0;
	while(x>0 || y>0)
	{
   	//cout<<x<<" "<<y<<endl;
		if((x&(1<<i)) != (y&(1<<i)))
		++ans;
		
		x-=x&(1<<i);
		y-=y&(1<<i);
		++i;
    }
    return ans;
}

int main()
{
	int x=1,y=4;
	cout<<hammingDistance(x,y);
}
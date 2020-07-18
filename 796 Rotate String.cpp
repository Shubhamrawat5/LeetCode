#include<iostream>
using namespace std;

bool rotateString(string A, string B) {
     if(A.length()!=B.length()) return 0;
	
	A=A.append(A);
   //cout<<A.find(B)<<endl;
   
    int found=A.find(B);
   //cout<<found;
	if(found!=-1)
	return 1;
	return 0;
}


int main()
{
	string A="abcd",B="cdab";
	cout<<rotateString(A,B);
}
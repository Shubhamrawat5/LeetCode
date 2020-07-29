#include<iostream>
#include<vector>

using namespace std;

vector<int> plusOne(vector<int>& digits)
{
      if(digits.size()<1) return digits;
      
      //if last element is smaller than 9 then just increment it and return vector
      if(digits[digits.size()-1]<9)
      {
      	++digits[digits.size()-1];
      	return digits;
      }
      
      int i;
      for(i=digits.size()-1;i>=0;--i) //scan from end
      {
      	if(digits[i]<9) //if smaller than 9 then increment and return directly
      	{
      		++digits[i];
      		return digits;
      	}
      	digits[i]=0; //otherwise make it 0
      }
     
     //if there was all 9s then add 1 in begin
     digits.insert(digits.begin(),1); 
      return digits;
 }


int main()
{
	vector<int> v={9,9,9};
	vector<int> ans=plusOne(v);
	for(auto k:ans)
	cout<<k;
}
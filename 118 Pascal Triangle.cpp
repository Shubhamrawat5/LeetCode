#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> generate(int rows)
{
      vector<vector<int>> pt; //2d array
      vector<int> ex; //for inner array
      
      int i,j=0;
      for(i=0;i<rows;++i)
      {
      	ex.clear(); //making array empty
      	ex.push_back(1); //filling 1 as 1 is in every row first value
      	
      	for(j=1;j<i;++j)
      	{
      		int x=pt[i-1][j]+pt[i-1][j-1]; //adding top 2 values
      		ex.push_back(x);
      	}
      	
      	if(i!=0) //except 1st row, all other rows has a ending 1
      		ex.push_back(1);
      		
      	pt.push_back(ex); //pushing our inner array to 2D array
      }
      return pt;
}


int main()
{
	int n=5;
	vector<vector<int>> v=generate(n);
	for(auto k:v)
	{
	for(auto j:k)
	cout<<j<<" ";
	cout<<endl;
	}
}
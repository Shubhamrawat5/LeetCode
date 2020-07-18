#include<iostream>
#include<vector>
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
        	vector<int> res={};
	int i=0,j=0;
	int r=matrix.size(); //row
	if(r==0) return res;
	int c=matrix[0].size(); //column
	int l=1;
	int fr,fd,fl,fu; //flag right,down,left,up
	fr=fl=fd=fu=1;
	res.push_back(matrix[0][0]);
	int ip=0;
	
	//Logic :-
	//the side where flag is 1 , it would go only that side
	//when flag right is 1 then flag left would be 0 such that only right it would go
	//after moving to right, next side would be down(spiral way) so making down flag as 1 and so on..
	while(++ip<r*c)
	{
		if(j<c-l && fr==1)
		{
			fd=1;
			fl=0;
			++j;
			res.push_back(matrix[i][j]);
		}
		else if(i<r-l && fd==1)
		{
			fl=1;
			fu=0;
			++i;
				res.push_back(matrix[i][j]);
		}
		else if(j>-1+l && fl==1)
		{
			fu=1;
			fr=0;
			--j;
			
            res.push_back(matrix[i][j]);
		}
		else if(i>-1+l && fu==1)
		{
			fd=0;
			--i;
			res.push_back(matrix[i][j]);
				if(i==l) 
			{
				++l;
				fr=1;
			}
		}
		
	}
	return res;
}

int main()
{
	vector<vector<int>> v={{1,2,3,4},{5,6,7,8},{9,10,11,12}};
	vector<int> ans=spiralOrder(v);
	for(auto k:ans)
	cout<<k<<" ";
}
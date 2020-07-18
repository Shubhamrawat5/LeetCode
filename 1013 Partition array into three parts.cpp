#include<iostream>
#include<vector>
using namespace std;

bool canThreePartsEqualSum(vector<int>& A) {
        if(A.size()<3) return 0;
          
        int j,count=0;
        for(j=1;j<A.size();++j)
            A[j]+=A[j-1];
        
        if(A[A.size()-1]%3!=0) return 0;
        
         int last=A[A.size()-1];
        int sum=last/3;
        for(j=0;j<A.size();++j)
            {
        //    	cout<<sum<<endl;
           if(A[j]==sum)
               { 
               count+=1;
            sum+=last/3; }
           }
        //   cout<<sum;
        if(sum-last/3==last && count>=3)
            return 1;
       else return 0;
 }

int main()
{
	vector<int> v={0,2,1,-6,6,-7,9,1,2,0,1};
	cout<<canThreePartsEqualSum(v);
}
#include<iostream>
#include<vector>
using namespace std;

int merge(vector<vector<int>>& v)
 {
        // cout<<intervals[0][0];
        int ans=0;
        sort(v.begin(),v.end());
        int i=0;
        for(i=0;i<v.size()-1;++i)
        {
        	if(v[i+1][0] < v[ans][1])
        	{
        		v[ans][1]=v[i+1][1];
        	}
        	else 
        	{
        		++ans;
        		v[ans]=v[i+1];
        	}
        }
        v.resize(ans+1);
       /* for(auto i:v)
        {
        for(auto k:i) cout<<k<<" ";
        cout<<endl;
        }*/
        return v;
 }

int main(int argc, char *argv[])
{
	vector<vector<int>> v={{8,10},{1,3},{15,18},{2,6}};
	merge(v);
}
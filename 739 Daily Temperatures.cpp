#include<iostream>
#include<vector>
#include<stack>
#include<unordered_map>

using namespace std;

vector<int> dailyTemperatures(vector<int>& T)
{
	vector<int> ans(T.size(),0);
	stack<int> s;
	int i;
	
	/*Logic: 1)push index of each elements in stack but before pushing index, 
2)check if top of stack index value is greater than our current index value or not, 
3)if our current index value is greater than this means one of the previous index ans is related to our current index value, 
4)so subtract cuurent-top and store in index of top and pop top then again check 3 as our current can be related(is answer) of many previous indexes value
5)if current is less then we have to push in stack and move to next index
*/
	for(i=0;i<T.size();++i)
	{
		while(s.size() && T[i]>T[s.top()])
		{
			ans[s.top()]=i-s.top();
			s.pop();
		}
		s.push(i);		
	}

	return ans;
}


int main()
{
	vector<int> v={73,74,75,71,69,72,76,73};
	vector<int> ans=dailyTemperatures(v);
	vector<int>::iterator it;
	for(it=ans.begin();it!=ans.end();++it)
	cout<<*it<<" ";
}
#include<iostream>
#include<stack>
using namespace std;

long cal(string s)
{
	string post; //for postfix
	stack<char> st;
	int i=0;
	for(i=0;s[i];++i) //to convert into postfix, i've added commas to seperate 2 digit numbers like 11+2+77 postfix=11,2,+77,+'
	{
		if(s[i]==' ') continue;
//		cout<<post<<endl;
		if(s[i]=='+' || s[i]=='-' || s[i]=='(') //for sign and opening bracket
		{
			if( st.size()==0 || st.top()=='(' || s[i]=='(')
				st.push(s[i]);
			
			else
			{
				post+=st.top();
				st.pop();
				st.push(s[i]);
			}
		}
		
		else if(s[i]==')') //for closing bracket
		{
			while(st.top()!='(')
			{
				post+=st.top();
				st.pop();
			}
			st.pop();
		}
		
		else //for numbers
		{
			post+=s[i];
			while(s[i+1] && s[i+1]>47 && s[i+1]<58)
			{
				++i;
				post+=s[i];
			}
			post+=',';
		}
	}
	while(st.size()) //remaining signs in stack
	{
		post+=st.top();
		st.pop();
	}
	
	stack<long> stk; //long stack for postfix evaluation
//	cout<<post<<endl;
	long val;
	
	int x,y;
	for(i=0;post[i];++i)
	{
		if(post[i]==',') continue; //ignore comma
		if(post[i]=='+' || post[i]=='-') //sign then perform on top 2 element in stack
		{
			x=stk.top();
			stk.pop();
			y=stk.top();
			stk.pop();
			stk.push(post[i]=='+'?x+y:y-x);
		}
		else {//if number then till comma, push to stack
			val=0;
			while(post[i]!=',')
			{
				val=val*10+(post[i]-'0');
				++i;
			}
			stk.push(val);
	}
	}

	return stk.top();
}

int main()
{
	string s="274+ 486 -(90+7-9)";
	cout<<cal(s);
}
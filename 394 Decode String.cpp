#include<iostream>
#include<stack>
using namespace std;

string decodeString(string s)
{
	if(s.length()<4) return s;
	string main,sub;
	stack<char> st;
	
	for(int i=0;s[i];++i)
	{
		if(st.empty()&&s[i]-'0'>10) //if stack is empty and a character come then add directly to main string
		{
			main+=s[i];
			continue;
		}
		
		if(s[i]!=']') //if other than closed bracket come then push to stack
		{
			st.push(s[i]);
			continue;
		}
		else //means closed bracket come
		{
			while(st.top()!='[') //till open bracket come add top of stack char to sub string
			{
				sub=st.top()+sub;
				st.pop();
			}
			st.pop(); //remove the open bracket
			
			string numb="";  //this is to generate the number in string first as number can be more than 1 digit
			while(st.size() && st.top()-'0'<10 && st.top()-'0'>=0) //if number is of more than 1 digit
				{
				numb=st.top()+numb;
				st.pop();
			}
		
			int n=stoi(numb); //number created from string numb
			
			string str=""; //this is to process tha multiplication in the sub string
			for(int j=0;j<n-1;++j)
				str+=sub;
			
			sub+=str;
	
			if(st.size()) //if there is still space in stack means there is still a open bracket is there and its closed bracket will come ahead so pushing char by char of sub string to stack
			{
				for(int k=0;sub[k];++k)
					st.push(sub[k]);
			}
			else   main+=sub; //if stack become empty means there is not open bracket left so add to main string

			sub=""; //making sub string empty so tbat next sub string can be processed seperately
		}
	}
	return main;
}


int main()
{
    string s="100[x]";
	//string s="3[a]2[b4[F]c]";
	cout<<decodeString(s);
}
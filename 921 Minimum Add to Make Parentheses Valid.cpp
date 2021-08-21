class Solution
{
public:
    int minAddToMakeValid(string s)
    {
        stack<char> st;
        //using stack stl to check

        for (int i = 0; i < s.length(); ++i)
        {
            if (st.size() == 0 || s[i] == '(')
                st.push(s[i]);
            else if (st.top() == '(')
                st.pop();
            else
                st.push(s[i]);
        }
        return st.size();
    }
};
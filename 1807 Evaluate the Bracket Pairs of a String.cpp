class Solution
{
public:
    string evaluate(string s, vector<vector<string>> &knowledge)
    {
        unordered_map<string, string> um;
        for (int i = 0; i < knowledge.size(); ++i)
            um[knowledge[i][0]] = knowledge[i][1];

        string ans = "";
        int i = 0;
        while (i < s.length())
        {
            cout << i << endl;
            while (i < s.length() && s[i] != '(')
            { //find start bracket
                ans += s[i];
                i++;
            }

            i++;
            string temp = "";
            while (i < s.length() && s[i] != ')')
            { //find close bracket and save inner text in temp
                temp += s[i];
                i++;
            }
            i++;

            if (temp != "" && !um.count(temp))
                ans += "?"; //not found in map
            else
                ans += um[temp];
        }
        return ans;
    }
};
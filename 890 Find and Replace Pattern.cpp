class Solution
{
public:
    vector<string> findAndReplacePattern(vector<string> &words, string pattern)
    {
        //storing which character point to which new character
        //a->c then mp1['a']='c' and mp2['c']='a' , storing both side!
        unordered_map<char, char> um1, um2;
        vector<string> ans;

        int n = words.size();

        for (int i = 0; i < n; ++i)
        {
            um1.clear();
            um2.clear();
            int flag = 0;

            //length is different
            if (pattern.length() != words[i].length())
                continue;

            // traverse word
            for (int j = 0; j <= pattern.size(); ++j)
            {
                int wch = words[i][j]; //word character
                int pch = pattern[j];  //pattern character

                //character already in map, then if it is matched with correct char or not, check both side
                if ((um1.count(pch) && um1[pch] != wch) || (um2.count(wch) && um2[wch] != pch))
                {
                    flag = 1;
                    break;
                }
                else
                {
                    //store both side
                    um1[pch] = wch;
                    um2[wch] = pch;
                }
            }

            if (flag == 0)
                ans.push_back(words[i]);
        }
        return ans;
    }
};
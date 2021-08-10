class Solution
{
public:
    bool arrayStringsAreEqual(vector<string> &word1, vector<string> &word2)
    {
        string a, b;
        a = b = "";

        for (int i = 0; i < word1.size(); ++i)
            a += word1[i];

        for (int i = 0; i < word2.size(); ++i)
            b += word2[i];

        int i;
        //compare every character
        for (i = 0; i < a.length(); ++i)
        {
            if (i >= b.length() || a[i] != b[i])
                return false;
        }

        if (i < b.length())
            return false; //if b is greater than a
        return true;
    }
};
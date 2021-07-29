class Solution
{
public:
    int canBeTypedWords(string text, string brokenLetters)
    {
        unordered_set<char> us;
        int count = 0;
        bool flag = 0; //using flag for last word as it won't have space after it.
        // insert all broken chars in set
        for (int i = 0; i < brokenLetters.length(); ++i)
            us.insert(brokenLetters[i]);

        for (int i = 0; i < text.length(); ++i)
        {
            flag = 0;
            if (text[i] == ' ')
                ++count; //word complete
            if (us.count(text[i]))
            { //letter broken
                while (i < text.length() && text[i] != ' ')
                    ++i;
                flag = 1;
            }
        }
        if (!flag)
            ++count; //last word came out fine
        return count;
    }
};
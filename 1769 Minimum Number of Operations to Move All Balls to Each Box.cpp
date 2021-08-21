class Solution
{
public:
    vector<int> minOperations(string boxes)
    {
        int n = boxes.size();
        vector<int> ans(n, 0);
        //simple by 2 for loops, checking every combo!

        int i;
        for (i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (i == j)
                    continue;
                if (boxes[j] == '1')
                    ans[i] += abs(j - i);
            }
        }
        return ans;
    }
};
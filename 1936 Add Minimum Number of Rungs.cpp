class Solution
{
public:
    int addRungs(vector<int> &rungs, int dist)
    {
        int count = 0;
        int cur = 0;
        for (int i = 0; i < rungs.size(); ++i)
        {
            if (cur >= rungs[i])
                continue;
            int gap = (rungs[i] - cur);
            if (gap > dist)
            { //rungs need to add
                count += ((gap - 1) / dist);
            }
            cur = rungs[i];
        }
        return count;
    }
};
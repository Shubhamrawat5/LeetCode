class Solution
{
public:
    int maxIceCream(vector<int> &costs, int coins)
    {
        //sort and start adding money from lower to higher
        sort(costs.begin(), costs.end());

        int cur, count, i;
        cur = count = i = 0;

        while (i < costs.size() && cur < coins)
        {
            cur += costs[i];
            if (cur <= coins)
                ++count;
            ++i;
        }
        return count;
    }
};
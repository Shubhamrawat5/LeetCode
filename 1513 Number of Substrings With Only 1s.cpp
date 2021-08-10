class Solution
{
public:
    int numSub(string s)
    {
        long long ans = 0;
        long long mod = 1000000007;

        //if we try to write values from consecutive ones then a pattern will form and it would be same as sum of n numbers: n(n+1)/2

        for (int i = 0; i < s.length(); ++i)
        {
            long long cur = 0;
            while (s[i] == '1')
            { //counting consecutive ones
                ++cur;
                ++i;
            }
            ans = (ans + (cur * (cur + 1) / 2) % mod) % mod;
        }
        return ans;
    }
};
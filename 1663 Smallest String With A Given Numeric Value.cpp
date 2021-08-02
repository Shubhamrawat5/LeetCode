class Solution
{
public:
    string getSmallestString(int n, int k)
    {
        //create an array with 'a' as 1 in every cell, start adding highest value from end to front
        vector<int> ch(n, 1);

        int sum = n;     //1-1-1- inserted so sum is n
        int pos = n - 1; //index from end
        while (sum != k)
        {
            if (k > (sum + 26 - 1))
            { //have to 'z' as adding z(26) in pos will still have less sum
                ch[pos] = 26;
                sum += 25; //change 'a' to 'z' (26-1=25)
                --pos;
            }
            else
            {                          //lesser or equal to 'z' and this will make sum == k
                int rem = k - sum + 1; //remaining value
                ch[pos] = rem;
                sum += rem - 1;
                --pos;
            }
        }

        string ans = "";
        for (auto i : ch)
        {
            ans += char(i + 'a' - 1);
        }
        return ans;
    }
};
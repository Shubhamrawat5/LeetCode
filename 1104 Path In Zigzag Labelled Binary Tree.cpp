class Solution
{
public:
    vector<int> pathInZigZagTree(int label)
    {
        if (label == 1)
            return {1};
        vector<int> ans;
        //logic: there is a pattern, even index values are "half of half" from right to left, same with odd index values
        //so we need 2 values, one righest odd index value, one rightest even index value
        //one we already have i.e label
        //other we find.

        //find alt
        int alt;

        //(int)log2(n) gives the lower closest power of 2, like 15 is 8, 8 is 8, 7 is 4, 6 is 4, 3 is 2
        int lb = 1 << ((int)log2(label) - 1); //lower bound
        int ub = (1 << (int)log2(label)) - 1; //upper bound
        alt = (ub - label / 2) + lb;

        // cout<<"alt:"<<alt<<endl;
        ans.push_back(label);
        ans.push_back(alt);
        label = label / 4;
        alt = alt / 2;

        int x = 1; //for alternate values +1,-1,+1,-1 ans so on..
        while (label >= 1 && alt >= 1)
        {
            if (x == 1)
                ans.push_back(label);
            else
                ans.push_back(alt);

            x = x * -1;
            label = label / 2;
            alt = alt / 2;
        }

        //reverse the vector
        for (int i = 0; i <= ans.size() / 2 - 1; ++i)
            swap(ans[i], ans[ans.size() - 1 - i]);
        return ans;
    }
};
class Solution {
public:
    vector<vector<int>> ans;
    //using same logic like subsets. but here we are using & calling for all the numbers in vector (from 0 to nums.size())  and to not to get repeated number in same sequence, using a bool vector.. before calling recursively we are marking it as used(1) so that in next recursion function it wont be used again..
    void dfs(vector<bool> used,vector<int>& nums,vector<int> curr)
    {
        if(curr.size()==nums.size())
        {
            ans.push_back(curr);
            return;
        }
        
        for(int i=0;i<nums.size();++i)
        {
            if(used[i]) continue;
            used[i]=1;
            curr.push_back(nums[i]);
            dfs(used,nums,curr);
            used[i]=0;
            curr.pop_back();
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> used(nums.size(),0); //filling vector with false value (0)
        vector<int> curr; //for current length
        dfs(used,nums,curr);
        return ans;
    }
};
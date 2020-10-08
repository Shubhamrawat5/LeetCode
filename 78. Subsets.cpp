class Solution {
public:
    vector<vector<int>> ans;
    //curlen=current length, totlen=total length
    void ss(vector<int>& nums,vector<int> curr,int curlen,int totlen)
    {
        if(curlen==totlen)
        {
            ans.push_back(curr);
            return;
        }
        
        ss(nums,curr,curlen+1,totlen);
        curr.push_back(nums[curlen]);
        ss(nums,curr,curlen+1,totlen);
    }
     
    /* For example 1,2 (calling recursively 2 times, one with no changes and another with adding next element)
    tree structure will form something like this
              empty   
            /      \
       empty         1
       /  \        /   \
    empty   2     1     1,2
    
    */
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> v;
        ss(nums,v,0,nums.size());
        return ans;
    }
};
class Solution {
public:
    //SAME AS QUESTION 78 SUBSETS but change in the recursion calls only, also sorted the nums first
    vector<vector<int>> ans;
    //curlen=current length, totlen=total length
    void ss(vector<int>& nums,vector<int> curr,int curlen,int totlen)
    {
        if(curlen==totlen)
        {
            ans.push_back(curr);
            return;
        }
        
        //so if same element comes as previous index element then this if will take care of it, otherwise run same as subset Q72 problem
        if(curlen && nums[curlen]==nums[curlen-1])
        {
            if(curr.size() && (curr.back()==nums[curlen])) //now for the current vector having previous elements stored, if it is having same element which is repeating then we have to only call recursively one time for right sub tree only.. otherwise execute as normal
            {
                curr.push_back(nums[curlen]);
                ss(nums,curr,curlen+1,totlen);
                return;
            }
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
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> v;
        sort(nums.begin(),nums.end());
        ss(nums,v,0,nums.size());
        return ans;
    }                                                                                                                                              
};
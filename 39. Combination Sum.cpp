class Solution {
public:
    vector<vector<int>> ans;
    //using backtracking and calling recursively for each combination
    void cs(vector<int>& candidates,vector<int> current,int target)
    {
        if(target<0) return;
        if(target==0) //found a combination sum 
        {
            ans.push_back(current);
            return;
        }
        
        for(int i=0;i<candidates.size();++i) //to recursively call for each combinatioin
        {
            if(current.size() && current[current.size()-1]<candidates[i]) continue; //to avoid getting same vector like for target 7= 2,2,3 and 2,3,2 and 3,2,2 will come but these having same frequency of numbers so to not to get these types of same frequency numbers , calling only for those whose whose previous number was smaller.. so here we will only get 2,2,3 as every left element is smaller
            current.push_back(candidates[i]); 
            cs(candidates,current,target-candidates[i]);
            current.pop_back();
        }

    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<int> v;
        cs(candidates,v,target);
        
        return ans;
    }
};
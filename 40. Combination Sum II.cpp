
class Solution {
public:
    vector<vector<int>> ans;
    //sorted the candidates before..
    //using backtracking and calling recursively for each combination
    void cs(vector<int> candidates,vector<int> current,int target)
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
            if(candidates[i]==0) continue;
            if(i && candidates[i]==candidates[i-1]) continue; //as we have sorted the candidates before so to get rid of duplicates, so we call do recursion and check for only unique elements.. like in case 4=1a,1b,2 and 1b,1a,2 are possible but we need only one 1,1,2 so we would skip the 2nd 1 as it is causing duplication
            
            current.push_back(candidates[i]); 
            
            //taking current candidate and marking it as 0 so that in next recursion function this candidate will have 0 value so it wouldnt be used more than once and after recursion giving its value back
            int cand=candidates[i];
            candidates[i]=0;
            
            cs(candidates,current,target-cand);
            
            candidates[i]=cand;
            current.pop_back();
        }

    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        vector<int> v;
        sort(candidates.begin(),candidates.end());
        cs(candidates,v,target);
        
        return ans;
    }
};
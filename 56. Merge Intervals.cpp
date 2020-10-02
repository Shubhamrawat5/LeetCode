class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size()<2) return intervals;
        
        vector<vector<int>> ans;
        int i=0;
        int r;
        sort(intervals.begin(),intervals.end());
        while(i<intervals.size())
        {
            vector<int> temp(2); //temp vector to store a single interval
            temp[0]=intervals[i][0];
            r=intervals[i][1];
               
            while(i<intervals.size()-1 && intervals[i+1][0]<=r) //checking if current range cover next range or not
            {
                r=max(r,intervals[++i][1]);
            }
            temp[1]=r;
            ans.push_back(temp);
            ++i;
        }
        return ans;
    }
};
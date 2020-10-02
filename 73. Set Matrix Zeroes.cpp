class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_set<int> r,c; //making set for row and column such that firstly get that row and column position
        //and store it to set so that knowing if there is any 0 in same row or column or not in O(n) time
        int i,j;
        for(i=0;i<matrix.size();++i)
        {
            for(j=0;j<matrix[0].size();++j)
            {
                if(matrix[i][j]==0)
                {
                    r.insert(i);
                    c.insert(j);
                }
            }
        }
        
        for(i=0;i<matrix.size();++i)
        {
            for(j=0;j<matrix[0].size();++j)
            {
                if(r.count(i) || c.count(j))
                    matrix[i][j]=0;
            }
        }
    }
};
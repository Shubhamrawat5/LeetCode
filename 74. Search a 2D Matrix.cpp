class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(!matrix.size()) return 0;
        int row,col;
        
        //assigning index of first row and last column
        row=0; 
        col=matrix[0].size()-1; 
        
        //since matrix is sorted so we can take advantage if target is bigger then it wont be present
        //in that row for sure so move down.. if target is smaller then move left as down side all elements will be bigger
        while(row<matrix.size() && col>=0)
        {
            if(matrix[row][col]==target) return true;
            else if(matrix[row][col]<target) row++;
            else col--;        
        }
        return false;        
    }
};
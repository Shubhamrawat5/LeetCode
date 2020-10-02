class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int i,j;
        //Transpose of matrix
        for(i=0;i<matrix.size();++i)
            for(j=i;j<matrix.size();++j)
                swap(matrix[i][j],matrix[j][i]);
        
        //180 degree left to right reverse
        for(i=0;i<matrix.size();++i)
        {
            for(j=0;j<matrix.size()/2;++j)
            {
                swap(matrix[i][j],matrix[i][matrix.size()-j-1]);
            }
              
        }
    }
};
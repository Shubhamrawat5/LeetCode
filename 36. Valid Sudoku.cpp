class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<int> unCol,unRow,unBlock;
        int i,j;
        
        //using 3 sets and checking all 3 (row,column,block) in a single loop
        for(i=0;i<board.size();++i)
        {
            unCol.clear();
            unRow.clear();
            unBlock.clear();
            
            int row=(i/3)*3; //for row, 0,0,0,3,3,3,6,6,6 will form as if we take every sub-box then starting index of the block will be this sequence
            int col=(i%3)*3; //for column, 0,3,6,0,3,6,0,3,6 will form
    
            for(j=0;j<board.size();++j)
            {
                if(board[i][j]!='.' && unRow.count(board[i][j])) //for column
                    return false;
                unRow.insert(board[i][j]);

                if(board[j][i]!='.' && unCol.count(board[j][i])) //for row
                    return false;
                unCol.insert(board[j][i]);
                
            //current row will be get by row+(j/3) and column by col+(j%3)
              if(board[row+(j/3)][col+(j%3)]!='.' && unBlock.count(board[row+(j/3)][col+(j%3)]))     
              {
                  
                  return false;
              }
              unBlock.insert(board[row+(j/3)][col+(j%3)]);
            }
        }
        return true;
    }
};
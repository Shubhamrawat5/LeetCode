class Solution {
public:
    //using dfs to find the solution
    //using x,y as corrdinates of current box. Check if it has a number or dot, if dot then try to fill it with 1-9 numbers that are valid, if its a number already present then call for its right neighbour
    bool dfs(vector<vector<char>>& board,vector<int>& row,vector<int>& col,vector<int>& square,int x,int y)
    {
        if(y==9) //since we are calling everytime for right box so when it would reach to the end of column then next row first column will be new box
        {
            ++x;
            y=0;
        } //checked all the boxes and there is a solution available now
        if(x==9) 
        {
            return true;
        }
        
        int k=0; //for 1 to 9 numbers
        if(board[x][y]=='.') 
        for(k=0;k<9;++k)
        {
            if(!((row[x]>>k)&1) && !((col[y]>>k)&1) && !((square[3*(x/3)+(y/3)]>>k)&1)) //element can be put
                {
                   board[x][y]=k+1+'0'; //filling it and marking it 1 in all 3 vectors
                   row[x]=row[x] | (1<<k);
                   col[y]=col[y] | (1<<k);
                   square[3*(x/3)+(y/3)] |= (1<<k);
                           
                   if(dfs(board,row,col,square,x,y+1)) //if(1) when solution get obtained
                        return true;
                   
                   board[x][y]='.'; //if no solution found so making it as before
                   row[x]=row[x] & ~(1<<k);
                   col[y]=col[y] & ~(1<<k);
                   square[3*(x/3)+(y/3)] &= ~(1<<k);
               }
         }
         if(k==0) //when there was a number in current box so above for loop doesnt execute, now calling for right neighbour
             if(dfs(board,row,col,square,x,y+1)) //return value from this will be.. found a soluion = 1
                    return true;
        
         return false;
}     
    
    
    void solveSudoku(vector<vector<char>>& board) {
        int n=board.size();
        vector<int> row(n),col(n),square(n); //using 3 differnt vectors for row, column, square. storing all the 1st row column info in row[0] (using bit manipulation here. set bit 1 for the numbers available in 1st row) and like this for all.. 
        //By this we can store 9 rows column in 9 integers only..
        for(int x=0;x<board.size();++x)
        {
            for(int y=0;y<board.size();++y)
            {
                n=board[x][y]-'1';
                if(board[x][y]!='.')
                {
                    row[x]=row[x] | (1<<n); //marking bit as 1 of the value present for row
                    col[y]=col[y] | (1<<n); 
                    square[3*(x/3)+(y/3)] |= (1<<n); 
                }
            }
        }
        
        dfs(board,row,col,square,0,0);
    }
};

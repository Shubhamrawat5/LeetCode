class Solution {
public:
    /*      
            rdia=right diagonal = /
            ldia = \ 
    
    */
    void dfs(vector<vector<string>>& ans,vector<string>& current,vector<int>& col,vector<int>& rdia,vector<int>& ldia,int r,int n) //r=current row
    {
        if(r==n) //have placed in all the rows and we have a answer now
        {
            ans.push_back(current);
            return;
        }
        
        for(int c=0;c<n;++c) //for every column from 0 to n-1 checking where we can place queen
        {
            if(col[c]==0 && rdia[r+c]==0 && ldia[(r-c)+n-1]==0) //checking if column is already filled with a queen or not, if right and left diagonal are filled or not
            { 
                //found a spot so placing queen and marking it position
                col[c]=1;
                rdia[r+c]=1;
                ldia[(r-c)+n-1]=1;
                current[r][c]='Q';
                
                dfs(ans,current,col,rdia,ldia,r+1,n); //calling for next row
                
                //removing last placed queen for trying another spot
                col[c]=0;
                rdia[r+c]=0;
                ldia[(r-c)+n-1]=0;
                current[r][c]='.'; 
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<string> current;
        vector<vector<string>> ans;
        if(n<=3 && n!=1) return ans; //for n=0,2,3 not possible
        
        //making vector of string .....
        string str="";
        for(int i=0;i<n;++i)
            str+=".";
        
        for(int i=0;i<n;++i)
            current.push_back(str);
    
        //not using for row as after placing a queen, we are gonna go on next row always as 2 queens cant be put in single row
        vector<int> col(n),rdia(2*n-1),ldia(2*n-1); //1 means filled, 0 means unfilled [vector has value 0 by default]
        dfs(ans,current,col,rdia,ldia,0,n);
        return ans;
    }
};


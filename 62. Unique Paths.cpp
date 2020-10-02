class Solution {
public:
    int dp[100][100]; //using dynamic programming array
    int calPaths(int m,int n,int r,int c)
    {
        if(dp[r][c]) return dp[r][c]; //if this path is already covered before so return previous stored value
        
        if(r==m-1 || c==n-1) return 1; //we've reached to end of row or column so now there is only 1 straight path available
        
        dp[r][c]=calPaths(m,n,r+1,c)+calPaths(m,n,r,c+1); //calling recursively for right and below path and calculating the number of paths
        return dp[r][c];
    }
    
    int uniquePaths(int m, int n) {
        return calPaths(m,n,0,0);
    }
};
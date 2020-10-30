class Solution {
public:
    //doing dfs on matrix and using a visited matrix to mark visited points. calling for all 4 directions and if we found a visited point or a point with 0 value then return. by this we will cover all the 1 which are in our reach. then number of time this dfs is called from numIslands function is the number of island there
    void dfs(vector<vector<char>>& grid,vector<vector<bool>>& visited,int r,int c)
    {
        if(r==grid.size() || c==grid[0].size() || r == -1 || c == -1) return; //point is out of matrix
        
        if(visited[r][c]==true) return; //already visited
        
        visited[r][c]=true; //mark as visited
        if(grid[r][c]=='0') return; //has 0 so return
    
        //calling in all 4 direction only if the point is not visited
        if(c+1 != grid[0].size() && visited[r][c+1]==false)
            dfs(grid,visited,r,c+1);
        if(r+1 != grid.size() && visited[r+1][c]==false)
            dfs(grid,visited,r+1,c);
        if(c-1 != -1 && visited[r][c-1]==false)
            dfs(grid,visited,r,c-1);
        if(r-1 != -1 && visited[r-1][c]==false)
            dfs(grid,visited,r-1,c);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size()==0) return 0;
        
        vector<vector<bool>> visited(grid.size(),vector<bool>(grid[0].size())); //creating a bool matrix to mark visited points

        for(int i=0;i<grid.size();++i)
            for(int j=0;j<grid[i].size();++j)
                visited[i][j]=false;
        
        int count=0;
        for(int i=0;i<grid.size();++i)
            for(int j=0;j<grid[i].size();++j)
                if(visited[i][j]==false && grid[i][j]=='1') //if point is not visited and it contain a 1 
                {
                    dfs(grid,visited,i,j);
                    ++count;
                }
        return count;
    }
};
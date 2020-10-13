class Solution {
public:
    //using a queue and doing bfs
    //pushing rotten oranges in queue and pushing its left right top bottom if any fresh and poping front as its all 4 sides are checked so again checking its 4 sides makes no sense
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int fresh=0; //count of fresh
        for(int i=0;i<grid.size();++i)
            for(int j=0;j<grid[0].size();++j)
            {
                if(grid[i][j]==2) q.push({i,j}); //pushing rotten in queue
                if(grid[i][j]==1) ++fresh;
            }
        
        q.push({-1,-1}); //pushing this so that when this comes in front means 1 time has passed
        int time=0;
        while(q.size()>1) //till there are no rotten oranges in queue
        {
            int r=q.front().first;
            int c=q.front().second;
            if(r==-1 && c==-1) //1 time passed
            {
                q.push({-1,-1});
                ++time;
            }
            
            else
            {
                
                //for left
                if(c>0 && grid[r][c-1]==1) 
                {
                    --fresh;
                    grid[r][c-1]=2;
                    q.push({r,c-1});
                }
                //for top
                if(r>0 && grid[r-1][c]==1)
                { 
                    --fresh;
                    grid[r-1][c]=2;
                    q.push({r-1,c});
                }
                //for right
                 if(c<grid[0].size()-1 && grid[r][c+1]==1)
                {
                     --fresh;
                    grid[r][c+1]=2;
                    q.push({r,c+1});
                }
                //for bottom
                 if(r<grid.size()-1 && grid[r+1][c]==1)
                {
                     --fresh;
                    grid[r+1][c]=2;
                    q.push({r+1,c});
                }
            }
            q.pop(); //removing the rotten orange which all 4 sides are checked
        }
        return fresh?-1:time; //if any fresh orange is remaining so -1 otherwise time taken
    }
};
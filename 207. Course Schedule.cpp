class Solution {
public:
    bool canFinish(int num, vector<vector<int>>& pre) {
        //using modified topological sort - kahn's algo to detect loop in directed graph
        vector<int> indegree(num); //to calculate indegree of each vertex
        vector<int> adjList[num]; //to create adjacency list of the vertex
        for(int i=0;i<num;++i) indegree[i]=0;
        
        for(int i=0;i<pre.size();++i) //making adj list and calculating indegree
        {
            adjList[pre[i][0]].push_back(pre[i][1]);
            ++indegree[pre[i][1]];
        }
            
        
        queue<int> q;
        for(int i=0;i<num;++i) //pushing vertex with indegree 0
            if(indegree[i]==0) q.push(i);
        
        int count=0;
        while(q.size())
        {
            int vertex=q.front();
            q.pop();
            for(int u:adjList[vertex]) //current vertex is removed so reducing its dependent vertex indegree by 1
            {
                --indegree[u];
                if(indegree[u]==0) q.push(u); //now if any vertex indegree become 0 then push it into queue
            }
            
            ++count;
        }
        
        //if every vertex indegree get 0 one time then there is not loop
        if(count==num) return true;
        else return false;
    }
};
class Solution {
public:
    //Logic: For a graph to be a bipartite, each continous vertex should be in alternate groups then only the edge btw them will be in both the group, so using -1 and +1 value to show this alternate value
    //so performing dfs and marking each vertex alternatively with -1 and +1 values and if we encounter a already visited node then checking is that previously marked alternate value is same or not, if not same then graph cant be bipartite
    bool dfs(vector<vector<int>>& graph,bool visited[],int alternate[],int source,int alterValue)
    {
        visited[source]=true; //marking visited
        alternate[source]=alterValue; //storing alternate value
        
        for(int v:graph[source]) //for every adjacency vertex of source vertex
        {
            if(visited[v]==true) //if that adjacency vertex is already visited
            {
                if(alterValue*-1 != alternate[v]) return false; //checking if that alternate value is same or not, if not then return false as graph cant be bipartite now
            }
            else if(dfs(graph,visited,alternate,v,alterValue*-1)==false) //else perform dfs 
                    return false;
        }
        return true;
    }
    
    
    bool isBipartite(vector<vector<int>>& graph) {
        int V=graph.size(); //number of vertex
        int alternate[V]; //for marking alternate values of vertex
        bool visited[V]; 
        memset(visited,0,sizeof(visited));
        
        for(int i=0;i<V;++i) //graph when is disconnected then calling for each unvisited vertex
            if(visited[i]==false)
                if(dfs(graph,visited,alternate,i,-1)==false) return false;
    
        return true;
    }
};
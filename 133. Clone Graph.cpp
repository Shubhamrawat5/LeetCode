/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    //performing dfs on given graph. calling recursively for each adjacant node and if the node is already visited before then directly return it. and in calling statement directly pushing in into neighbors vector
    Node* dfs(Node* node,unordered_map<int,Node*>& visited)
    {
        if(visited.count(node->val)==1) //already visited and created before
            return visited[node->val]; //return previously created node of clone
        
        Node* clone=new Node(node->val); //if node was not created before so create it and push it into map
        visited[node->val]=clone;
        
        //calling for each adjacent node
        for(int i=0;i<node->neighbors.size();++i)
        {
            clone->neighbors.push_back(dfs(node->neighbors[i],visited));
        }
        
        return clone;
    }
    
    Node* cloneGraph(Node* node) {
        if(node==NULL) return NULL;
        
        unordered_map<int,Node*> visited; //using map (key=node value , value=node)
        
        return dfs(node,visited);
    }
};
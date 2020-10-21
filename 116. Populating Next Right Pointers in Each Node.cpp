/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL) return NULL;
        root->next=NULL;
        
        queue<Node*> q;
        q.push(root);
        
        int NextLevelNode=2; //as nodes get double in every level so using this variable to know how many nodes are there in next level
        int count=0; //this will know when is the last node of a level
        while(q.front()->left)
        {
            Node* p=q.front();
            q.pop();
            p->left->next=p->right;
            if(q.size()==count) //using count variable to get the last node of current level info.. as we are poping above so parent node will get popped out already and remaining nodes in the queue will be the (total nodes in next level - current node 2 children) which will always be in [(power of 2) - 2]
            {
                p->right->next=NULL;
                NextLevelNode*=2;
                count=NextLevelNode-2;
            }
            else
            {
                Node* neighbour=q.front();
                p->right->next=neighbour->left;
            }    
                
            if(p->left)     q.push(p->left);
            if(p->right)    q.push(p->right);
        }
        return root;
    }
};
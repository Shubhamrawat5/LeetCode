/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q; //for bfs for level order traversal
        vector<vector<int>> ans;
        
        if(root==NULL) return ans;
        
        //push level by level nodes in queue then from the size of queue, we will get number of all the nodes in a level, so we can do push all the child of this level by a loop and can differentiate between levels
        q.push(root);
        while(q.size())
        {
            int len=q.size(); 
            vector<int> temp;
            for(int i=0;i<len;++i)
            {
                root=q.front();
                if(root->left) q.push(root->left); //only pushing valid child
                if(root->right) q.push(root->right);
                temp.push_back(root->val);
                q.pop();
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
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
    /* recursive approach
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> in;
        
        inTraverse(root,in);
        return in;
    }
    
    void inTraverse(TreeNode* root,vector<int>& in)
    {
        if(!root) return;
        inTraverse(root->left,in);
        in.push_back(root->val);
        inTraverse(root->right,in);
    }*/
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> in;
        if(root==NULL) return in;
        stack<TreeNode*> st; //using dfs with stack
    
        while(root!=NULL || st.size())
        {
            while(root != NULL) //same like base condition in recursion, if root exist then add to stack and call for left
            {
                st.push(root);
                root=root->left;
            }
            
            root=st.top(); //when root becomes NULL so taking current node and pushing to vector ans
            in.push_back(root->val); 
            st.pop();
            
            root=root->right; //calling for right 
        }
        
        return in;
    }
    
};
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
    
    //using level variable to denote the level at which the node is. and calling recursively for left then right side so first left child subtree elements will get filled in vector and when same level node comes, it will overwrite the value in that level value in vector
    void helper(TreeNode* root,vector<int>& v,int& level)
    {
        if(root==NULL) return;
        
        if(v.size()>level) v[level]=root->val;
        else v.push_back(root->val);
        
        ++level;
        helper(root->left,v,level);
        helper(root->right,v,level);
        --level;
    }
    
    vector<int> rightSideView(TreeNode* root) {
        vector<int> v;
        int level=0;
        helper(root,v,level);
        return v;
    }
};
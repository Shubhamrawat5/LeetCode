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
    void helper(TreeNode* root,int& minheight,int curheight)
    {
        if(root==NULL) return;
        if(!root->left && !root->right) //if both child do not exist then check for height
        {
            minheight=min(minheight,curheight);
            return;
        }
        helper(root->left,minheight,curheight+1);
        helper(root->right,minheight,curheight+1);
    }
    
    int minDepth(TreeNode* root) {
        if(root==NULL) return 0;
        int minheight=INT_MAX;
        helper(root,minheight,1); //passing 1 to current height as first root node is on height 1
        return minheight;
    }
};
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
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root==NULL) return NULL;
        
        //using BST property, left child is smaller value and right side is bigger
        while(root)
        {
            if(root->val==val) return root;
            if(root->val<val) root=root->right; //value is bigger so it might be in right subtree
            else root=root->left;
        }
        return root;
    }
};
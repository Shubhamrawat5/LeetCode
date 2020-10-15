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
    int rightheight(TreeNode* root)
    {
        if(root==NULL) return 0;
        return rightheight(root->right)+1;
    }
    
    int leftheight(TreeNode* root)
    {
        if(root==NULL) return 0;
        return leftheight(root->left)+1;
    }
    
    int countNodes(TreeNode* root) {
        if(root==NULL) return 0;
        
        int lh=0,rh=0;
        //int lh=leftheight(root);
        //int rh=rightheight(root);
        
        //calculating leftest node height and righest node height if both are equal then it is a perfect balanced binary tree so there is 2^h-1 formula to get total nodes directly
        for(TreeNode* i=root; i; i=i->left) lh++;
        for(TreeNode* i=root; i; i=i->right) rh++;

        if(lh==rh) //both height same
            return pow(2,lh)-1;
        else //if height is not same means not a perfect balanced binary tree so breaking it into left subtree and right subtree
            return countNodes(root->left)+countNodes(root->right)+1;
    }
};
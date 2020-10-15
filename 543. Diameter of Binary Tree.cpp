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
    //dfs ! computing depth of each leaf node and then checking each leaf distance from a ancestor node max lenght
    int helper(TreeNode* root,int depth,int& dia)
    {
        if(root==NULL) return 0;
        
        //for calculating left depth and right depth of a node
        int leftDepth=helper(root->left,depth+1,dia);
        int rightDepth=helper(root->right,depth+1,dia);
        
        //sum of both depth is stored in diameter ans
        dia=max(dia,leftDepth+rightDepth);
        
        //returning max depth to upper node
        return max(leftDepth,rightDepth)+1;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        int dia=0;
        helper(root,0,dia);
        return dia;
    }
};
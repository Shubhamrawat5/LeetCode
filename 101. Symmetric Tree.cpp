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
    //using two pointers and moving them in mirror fashion. means both going towards each other, and both going away from each other and then checking coditions if both are same or not
    bool helper(TreeNode* p,TreeNode* q)
    {
        if(!p && !q) return true; //both null - same
        if(!p || !q) return false; //only 1 null - not same
        if(p->val != q->val) return false; //not same
        
        return (helper(p->left,q->right) && helper(p->right,q->left));
    }
    
    bool isSymmetric(TreeNode* root) {
        if(root==NULL) return true;
        return helper(root->left,root->right);
    }
};
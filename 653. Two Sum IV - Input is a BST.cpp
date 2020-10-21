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
    bool helper(TreeNode* root,int k,unordered_set<int>& un)
    {
        if(root==NULL) //reached NULL means pair not found
            return false; 
        
        if(un.count(k - root->val)) //found a pair 
            return true; 
        
        un.insert(root->val); 
        
        return helper(root->left,k,un) || helper(root->right,k,un); //at the moment a pair is found it will directly return to all the previous recursion call ( using OR so it is a short circuit evaluation operator, if first value get true then second value is not checked!)
    }
    
    bool findTarget(TreeNode* root, int k) {
        if(root==NULL) return false;
        unordered_set<int> un; //using unordered_set for faster look ups
        return helper(root,k,un);
    }
};
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
    //using min and max as root->val should always be between min & max
    //firstly all values will be inside INT_MIN and INT_MAX so if we go to left subtree so now that subtree should have INT_MIN to root->val-1 values , same with right subtree,
    //so we maintain these min and max and check if BT is a correct BST or not
    bool helper(TreeNode* root,long long min,long long max)
    {
        if(root==NULL) return true;
            
        //current value is if not between the range then it is not a BST
        if(root->val < min || root->val > max) return false;
        
        //using (long long) typecasting to handle case when value in node is INT_MAX or INT_MAX then int buffer overflow can occur due to +1 or -1
        return helper(root->left,min,(long long)root->val-1) && helper(root->right,(long long)root->val+1,max);
    }
    
    bool isValidBST(TreeNode* root) {
        if(root==NULL) return true;
        
        return helper(root,INT_MIN,INT_MAX);
    }
}; 
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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==NULL) return new TreeNode(val); //tree is empty
        
        TreeNode* curr=root;
        //node in BST are always inserted in leaf node (in the bottom)
        while(curr)
        {
            if(curr->val==val) return root; //already exist in tree
            else if(curr->val > val) //search val is smaller so in left child
            {
                if(curr->left==NULL) curr->left=new TreeNode(val); //if left child dont exist then put the new node there
                curr=curr->left;
            }
            else
            {
                if(curr->right==NULL) curr->right=new TreeNode(val);
                curr=curr->right;
            }
            
        }
        return root;
    }
};
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
    TreeNode *getPredecessor(TreeNode* curr) //left child and its diagonal rightest
    {
        curr=curr->left;
        while(curr && curr->right) curr=curr->right; 
            
        return curr;
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL) return root;
        
        if(root->val < key) root->right=deleteNode(root->right,key);
        else if(root->val > key) root->left=deleteNode(root->left,key);
        else //found.. 3 possibilities.. left child doesnt exist. right child doesnt exist, both exist
        {
            if(root->left==NULL) //left doesnt exist (also if both dont exist)
            {
                TreeNode* temp=root->right;
                delete(root);
                return temp;
            }
            else if(root->right==NULL) //right child doesnt exist
            {
                TreeNode* temp=root->left;
                delete(root);
                return temp;
            }
            else //both child exist 
            {
                TreeNode* pre=getPredecessor(root); //find the predecessor of current element as if we swap with it then whole BST will remain a BST but just that last leaf node we have to delete now
                swap(root->val,pre->val);
                root->left=deleteNode(root->left,key);
            }
        }
        return root;
    }
};
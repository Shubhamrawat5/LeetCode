/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    //doing dfs and calling for left child right child if any of them found a given node then it will firstly check if it is a ancestor of both node or not. if yes then it will set value in lca pointer, if not then it will inform its parent that i found a node and now you check if you are ancestor of both given nodes or not
    bool helper(TreeNode* root, TreeNode* &p, TreeNode* &q,TreeNode* &lca)
    {
        if(root==NULL) return false;
        
        bool found=false; //if we found a given node then also we need to search below nodes as (a node ca be a descendant of itself is given) so using this boolean value to marked it and not return directly
        if(root==p || root==q) found=true;
        
        bool leftsearch=helper(root->left,p,q,lca); //searching in left subtree recursively
        bool rightsearch=helper(root->right,p,q,lca); //searching in right subtree recursively
        
        //if in leftsubtree given node is found and also in right subtree then set lca
        //also if current node is a given node and either in left or right subtree node found then set lca pointer 
        if((leftsearch&&rightsearch) || (leftsearch&&found) ||(rightsearch&&found))
               lca=root;
           
        //if current node is given node or node found in left or right then inform to the parent node
        if(leftsearch||rightsearch||found) return true;
        else return false;
    }
        
        
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* lca;
        helper(root,p,q,lca);
        return lca;
    }
};
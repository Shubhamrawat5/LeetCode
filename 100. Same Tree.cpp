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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        //if both are null means same
        if(p==NULL && q==NULL) return true;
        
        //if one of them is NULL so not same
        if((p==NULL && q!=NULL) || (p!=NULL && q==NULL)) return false;
        
        //if values are different in both so not same
        if(p->val != q->val) return false;
        
        //calling for left subtree and right subtree and checking if both are giving true or false. if any of the recursive function return false then with AND operation everytime it will get false
        return(isSameTree(p->left,q->left) && isSameTree(p->right,q->right));
    }
};
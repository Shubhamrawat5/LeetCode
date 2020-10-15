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
    int helper(TreeNode* root,int height,bool& ib)
    {
        if(root==NULL) return height-1;
        
        //finding left height and right height
        int leftHeight=helper(root->left,height+1,ib);
        int rightHeight=helper(root->right,height+1,ib);
        
        //getting bigger height among both as function when return to its parent node, then height considered will be the bigger one
        int biggerHeight=max(leftHeight,rightHeight);
        
        //height differ by more then 1 and passing ib by reference so that if this ib value gets false one time then it would remain false till the end
        if(abs(leftHeight-rightHeight)>1) ib=false; 
        
        return biggerHeight;
    }
    
    bool isBalanced(TreeNode* root) {
        bool ib=true;
        helper(root,1,ib);
        return ib;
        
    }
};
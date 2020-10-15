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
    int helper(TreeNode* root,int& ans)
    {
        if(root==NULL) return 0;
        
        int leftSum=helper(root->left,ans);
        int rightSum=helper(root->right,ans);
        
        /*For every node, 4 possibilities: 
        1) left sum + rootvalue 
        2) right sum + rootvalue 
        3) only rootvalue
        4) left + right + rootvalue
        */
        
        //L=Left,R=Right,P=Parent
        int maxLR=max(leftSum+root->val,rightSum+root->val); //max from 1st and 2nd possibility
        int maxLRP=max(maxLR,root->val); //max from above and 3rd possibility
        int maxfromfour=max(maxLRP,leftSum+rightSum+root->val); //max from above and 4th possibility
            
        ans=max(ans,maxfromfour); //adding bigger sum to ans
        
        return maxLRP<0?0:maxLRP; //if of first 3 possibilities, max sum is less than 0 means all 3 are negative values so no point in taking it so return 0, otherwise positive sum from first 3 possibilities 
    }
    
    int maxPathSum(TreeNode* root) {
        if(root==NULL) return 0;
        int maxSum=INT_MIN;
        helper(root,maxSum);
        return maxSum;
        }
};
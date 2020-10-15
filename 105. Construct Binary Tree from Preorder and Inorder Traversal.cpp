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
    //using same technique as we use to make binary tree in our copy
    //as preorder prints root first so first element in preorder vector would be first root, 2nd element is 2nd root node, 3rd element is 3rd root and so on..
    //using preorder-Index variable to increment whenever we use a root from preorder vector
    //using leftindex and rightindex variable for inorder vector to denote what range is there on left side and right side
    
    //Logic: creating root node from preorder vector then searching value in inorder vector then divding into a range like these elements are on left side and these range elements are on right side then doing recursion
    int preIndex=0;
    TreeNode* helper(vector<int>& preorder,vector<int>& inorder,int leftindex,int rightindex)
    {
        if(leftindex>rightindex) return NULL;
        
        TreeNode* root=new TreeNode(preorder[preIndex++]); //creating root node one by one from preorder array
        
        if(leftindex == rightindex) return root;  //in inorder array, only 1 element is there,so directly return it
        
        int i; //finding root value in inorder array
        for(i=leftindex;i<=rightindex;++i)
        {
            if(inorder[i]==preorder[preIndex-1]) break;
        }
        
        //calling with left range and right range 
        root->left=helper(preorder,inorder,leftindex,i-1);
        root->right=helper(preorder,inorder,i+1,rightindex);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode *root=NULL;
        if(preorder.size()==0) return root;
        
        root=helper(preorder,inorder,0,preorder.size()-1);
        return root;
    }
};
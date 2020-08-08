#include<iostream>
using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };


class Solution {
public:

	void cal(TreeNode* root,int& depth,int curr) //curr is current depth 
	{
		if(root==NULL) return;
		//if there are no children, means we are in the leaf node
		if(root->left==NULL && root->right==NULL)
			{
				depth=max(depth,curr);
			} 
			
		if(root->left) //only going to left child if exist
			cal(root->left,depth,curr+1);
			
		if(root->right) //only goinf to right child if exist
			cal(root->right,depth,curr+1);
	}
	

    int maxDepth(TreeNode* root) {
        int depth=0;
        cal(root,depth,1);
        return depth;
    }
};

/* easy way :-
int maxDepth(TreeNode* root) {

    if(root == NULL)
        return 0;
    
    return 1+ max(maxDepth(root->left),maxDepth(root->right));
    
} */

int main()
{
	TreeNode * root=new TreeNode(0);
	root->left=new TreeNode(1);
	root->right=new TreeNode(0);
	root->left->left=new TreeNode(0);
	root->right->left=new TreeNode(0);
	root->right->right=new TreeNode(0);
	root->right->left->right=new TreeNode(1);
	root->right->left->right->right=new TreeNode(1);

	Solution s;
	cout<<s.maxDepth(root);
}

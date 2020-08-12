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

	TreeNode* invertTree(TreeNode* root)
	{
		if(root) return root;
		
		//changing left child to right child and right child to left child (swapping)
		TreeNode* temp;
		temp=root->left;
		root->left=root->right;
		root->right=temp;
		
		if(root->left) invertTree(root->left); //if left child exist
		if(root->right) invertTree(root->right); //if right child exist
		
		return root;
	}
	
	void inorder(TreeNode *root) //to display
{
	if(root)
	{
		inorder(root->left);
		cout<<root->val<<" ";
		inorder(root->right);
	}
}
};

int main()
{
	TreeNode * root=new TreeNode(4);
	root->left=new TreeNode(2);
	root->right=new TreeNode(7);
	root->left->left=new TreeNode(1);
	root->left->right=new TreeNode(3);
	root->right->left=new TreeNode(6);
	root->right->right=new TreeNode(9);
	
	Solution s;
	root=s.invertTree(root);
	s.inorder(root);
}
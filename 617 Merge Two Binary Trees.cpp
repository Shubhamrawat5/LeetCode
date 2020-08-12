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

	TreeNode* mergeTrees(TreeNode* t1,TreeNode* t2)
	{
		if(t1==NULL) return t2; //if t1 subtree doesnt exist then whole t2 subtree will be added to merge tree
		if(t2==NULL) return t1; //if t2 subtree doesnt exist then whole t1 subtree will be added to merge tree, no need to check further down subtree
		
		//making merge tree in t1 tree
		t1->left=mergeTrees(t1->left,t2->left);
		t1->right=mergeTrees(t1->right,t2->right);
		
		t1->val=t1->val + t2->val; //adding values
		return t1;
	}
};

int main()
{
	TreeNode * root=new TreeNode(1);
	root->left=new TreeNode(3);
	root->right=new TreeNode(2);
	root->left->left=new TreeNode(5);
	
	TreeNode * root2=new TreeNode(2);
	root2->left=new TreeNode(1);
	root2->right=new TreeNode(3);
	root2->left->right=new TreeNode(4);
	root2->right->right=new TreeNode(7);

	Solution s;
	TreeNode* root3=s.mergeTrees(root,root2);
}
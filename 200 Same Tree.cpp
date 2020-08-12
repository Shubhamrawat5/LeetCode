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
	bool isSame(TreeNode* p,TreeNode* q)
	{
		//3 base cases
		//1) if both reached null as leaf node children
		//2) if one of them becomes null means there are different trees
		//3) if values are different in both trees
		if(p==NULL && q==NULL)
			return true;
		if(p==NULL || q==NULL)
			return false;
		if(p->val != q->val)
			return false;
			
		//recursively checking fir left subtree and right subtree, both need to be true to have same tree
		return isSame(p->left,q->left) && isSame(p->right,q->right);
		
	}

};

int main()
{
	TreeNode * root1=new TreeNode(0);
	root1->left=new TreeNode(1);
	root1->right=new TreeNode(0);
	root1->left->left=new TreeNode(0);
	
	TreeNode* root2=new TreeNode(0);
	root2->left=new TreeNode(1);
	root2->right=new TreeNode(0);
//	root2->left->left=new TreeNode(0);

	Solution s;
	cout<<s.isSame(root1,root2);
}
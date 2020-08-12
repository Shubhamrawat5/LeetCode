#include<iostream>
#include<queue>
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

	bool isUnivalTree(TreeNode* root)
	{
		int val=root->val;
		
		//using breadth first traversal
		queue<TreeNode *> q;
		q.push(root);
		while(q.size())
		{
			root=q.front();
			q.pop();
			
			if((root->val) != val) return false; 
			
			if(root->left) q.push(root->left); //if left child exist
			if(root->right) q.push(root->right); //if right child exist
			
		}
		return true;
	}
};

int main()
{
	TreeNode * root=new TreeNode(3);
	root->left=new TreeNode(3);
	root->right=new TreeNode(33);
	root->left->left=new TreeNode(3);
	root->left->right=new TreeNode(3);
	root->right->right=new TreeNode(3);
	
	Solution s;
	cout<<s.isUnivalTree(root);
}
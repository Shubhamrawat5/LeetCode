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

	void flatten(TreeNode* root)
	{
		if(root ==NULL) return;
		 
		TreeNode* temp=root->right; //using temp to hold the right child so that right child won't get lost
		root->right=root->left;
		root->left=NULL;
		
		TreeNode* curr=root->right; //curr to find the top rightmost node of root
		
		if(curr) //if curr not null then form a link to curr to temp
		{
			while(curr->right)  curr=curr->right;	
			curr->right=temp;
		}
		else //if curr is null then means there was no left child of root so simply re made the link
		{
			root->right=temp;
		}
		flatten(root->right); //calling recursively for next right child now
	}
};

int main()
{
	TreeNode * root=new TreeNode(1);
	root->left=new TreeNode(2);
	root->right=new TreeNode(3);
	root->left->left=new TreeNode(4);
	root->left->right=new TreeNode(5);
	root->right->right=new TreeNode(6);
	//root->right->left->right=new TreeNode(1);
	//root->right->left->right->right=new TreeNode(1);

	Solution s;
	s.flatten(root);
}

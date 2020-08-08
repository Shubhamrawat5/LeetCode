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

//Logic: recursively going to each sub tree and calculating int form in curr variable and when reaching end , adding this cure to sum(ans)
//and passing sum as reference 
	void cal(TreeNode* root,int& sum,int curr)
	{
		if(root->val & 1) //checking bit is 1 or 0
			curr=(curr<<1)+1;
		else
			curr=curr<<1;
			
		//if there are no children, means we are in the leaf node so adding current curr to the sum
		if(root->left==NULL && root->right==NULL)
			{
				cout<<sum<<" "<<curr<<endl;
				sum+=curr;
			} 
			
		if(root->left) //only going to left child if exist
			cal(root->left,sum,curr);
			
		if(root->right) //only goinf to right child if exist
			cal(root->right,sum,curr);
	}
	

    int sumRootToLeaf(TreeNode* root) {
        int sum=0;
        cal(root,sum,0);
        return sum;
    }
};


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
	cout<<s.sumRootToLeaf(root);
}

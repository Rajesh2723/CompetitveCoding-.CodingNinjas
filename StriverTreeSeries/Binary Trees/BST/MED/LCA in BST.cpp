/*
Given the root node of a binary search tree (BST) and two node values p,q.



Return the lowest common ancestors(LCA) of the two nodes in BST.


Examples:
Input : root = [5, 3, 6, 2, 4, null, 7] , p = 2, q = 4

Output : [3]
  */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *      TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
 * };
 **/

class Solution{	
	public:
		TreeNode* lca(TreeNode* root, int p, int q){
	        if(root==nullptr||root->data==p||root->data==q){
                return root;
            }

            TreeNode*left=lca(root->left,p,q);
            TreeNode*right=lca(root->right,p,q);
            if(left!=nullptr and right!=nullptr){
                return root;
            }
            return left!=nullptr?left:right;
		}
};

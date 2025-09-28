/*
Given the root node of a binary tree. Return true if the given binary tree is a binary search tree(BST) else false.



A valid BST is defined as follows:



The left subtree of a node contains only nodes with key strictly less than the node's key.


The right subtree of a node contains only nodes with key strictly greater than the node's key.


Both the left and right subtrees must also be binary search trees.

Examples:
Input : root = [5, 3, 6, 2, 4, null, 7]

Output : true
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

        bool inorder(TreeNode*node,TreeNode*&prev){
            if(!node)return true;
            
            if(!inorder(node->left,prev))return false;//need to check this case
            if(prev!=nullptr and node->data<=prev->data)return false;
            prev=node;
            return inorder(node->right,prev);
        }

		bool isBST(TreeNode* root){
			TreeNode*node=root;
            //vector<int>ans;
            TreeNode*prev=nullptr;
            return inorder(root,prev);
		}
};

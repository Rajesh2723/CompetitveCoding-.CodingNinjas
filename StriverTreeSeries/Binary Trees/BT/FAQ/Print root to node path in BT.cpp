/*
Given the root of a binary tree. Return all the root-to-leaf paths in the binary tree.



A leaf node of a binary tree is the node which does not have a left and right child.


Examples:
Input : root = [1, 2, 3, null, 5, null, 4]

Output : [ [1, 2, 5] , [1, 3, 4] ]

Explanation : There are only two paths from root to leaf.

From root 1 to 5 , 1 -> 2 -> 5.

From root 1 to 4 , 1 -> 3 -> 4.
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
		vector<vector<int>> allRootToLeaf(TreeNode* root) {
            vector<vector<int>>ans;
            vector<int>s;
            f(root,s,ans);
            return ans;
		}
        void f(TreeNode*node,vector<int>&path,vector<vector<int>>&ans){
            if(!node)return;
            path.push_back(node->data);
            if(!node->left and !node->right){
                ans.push_back(path);
            }
            else{
                f(node->left,path,ans);
                f(node->right,path,ans);
            }
            path.pop_back();
        }
};

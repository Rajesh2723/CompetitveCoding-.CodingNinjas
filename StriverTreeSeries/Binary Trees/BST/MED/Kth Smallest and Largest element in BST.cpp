/*
Given the root node of a binary search tree (BST) and an integer k.



Return the kth smallest and largest value (1-indexed) of all values of the nodes in the tree.



Return the 1st integer as kth smallest and 2nd integer as kth largest in the returned array.


Examples:
Input : root = [3,1,4,null,2] , k = 1

Output : [1, 4]

Explanation :

The 1st smallest value in given BST is 1.

The 1st largest value in given BST is 4.

Input : root = [5, 3, 6, 2, null, null, null, 1] , k = 3

Output : [3, 3]

Explanation :

The 3rd smallest value in given BST is 3.

The 3rd largest value in given BST is 3.
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

class Solution {
public:
    void inorder(TreeNode*node,int k,vector<int>&ans){
        if(!node)return;
        inorder(node->left,k,ans);
        ans.push_back(node->data);
        inorder(node->right,k,ans);
    }
	vector<int> kLargesSmall(TreeNode* root,int k){
		vector<int>ans;
        inorder(root,k,ans);
        int firstSmallest,lastLargest=0;
        if(k<=ans.size()){
            firstSmallest=ans[k-1];
            lastLargest=ans[ans.size()-k];
        }
        return {firstSmallest,lastLargest};
	}
};

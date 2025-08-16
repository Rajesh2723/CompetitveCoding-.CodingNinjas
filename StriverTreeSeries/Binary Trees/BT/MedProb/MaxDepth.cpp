/*
Given root of the binary tree, return its maximum depth.



A binary tree's maximum depth is number of nodes along the longest path from root node down to the farthest node.


Examples:
Input : root = [1, 2, 3, null, null, null , 6]

Output : 3

Explanation : The path from root node 1 to node with value 6 has maximum depth with 3 nodes along path.



Input : root = [3, 9, 20, null, null, 15 , 7]

Output : 3

Explanation : The path from root node 3 to node with value 15 has maximum depth with 3 nodes along path.

There exists other paths to reach the solution.
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
//we can do this in level order traversal as well.
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root)return 0;
        int maxi1=maxDepth(root->left);
         int maxi2=maxDepth(root->right);
        return 1+max(maxi1,maxi2);
    }
};

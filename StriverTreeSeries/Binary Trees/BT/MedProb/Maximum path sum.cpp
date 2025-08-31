/*
In a binary tree, a path is a list of nodes where there is an edge between every pair of neighbouring nodes. A node may only make a single appearance in the sequence.



The total of each node's values along a path is its path sum. Return the largest path sum of all non-empty paths given the root of a binary tree.



Note: The path does not have to go via the root.


Examples:
Input : root = [20, 9, -10, null, null, 15, 7]

Output : 34

Explanation : The path from node 15 to node 9 has maximum path sum.

The path is 15 -> -10 -> 20 -> 9.



Input : root = [-10, 9, 20, null, null, 15, 7]

Output : 42

Explanation : The path from node 15 to node 7 has maximum path sum.

The path is 15 -> 20 -> 7.



Input : root = [1, 2, 3, null, 4]


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
    int maxPathSum(TreeNode* root) {
       int ans=INT_MIN;
       PathSum(root,ans);
       return ans;
    }
    int PathSum(TreeNode*node, int &ans){
        if(!node)return 0;
        int leftData=max(0,PathSum(node->left,ans));
        int rightData=max(0,PathSum(node->right,ans));
        ans=max(ans,leftData+rightData+node->data);
        return node->data+max(leftData,rightData);
    }
};	

/*
Given a root of binary tree, find the lowest common ancestor (LCA) of two given nodes (p, q) in the tree.



The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).


Examples:
Input : root = [3, 5, 1, 6, 2, 0, 8, null, null, 7, 4] , p = 5, q = 1

Output : 3

Explanation :



Input : root = [3, 5, 1, 6, 2, 0, 8, null, null, 7, 4] , p = 5, q = 4

Output : 5

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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
         if (root == nullptr || root == p || root == q) 
        return root;

    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);

    if (left != nullptr && right != nullptr) 
        return root;

    return (left != nullptr) ? left : right;
    }
};

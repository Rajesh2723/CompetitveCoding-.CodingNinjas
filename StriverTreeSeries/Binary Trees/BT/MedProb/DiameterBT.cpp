/*
Given the root of a binary tree, return the length of the diameter of the tree.



The diameter of a binary tree is the length of the longest path between any two nodes in the tree. It may or may not pass through the root.


Examples:
Input : root = [1, 2, 3, 4, 5]

Output : 3

Explanation : The path length between node 4 and 3 is of length 3.

There are other ways to reach the solution.





Input : root = [1, 2, 3, null, 4, null, 5]

Output : 4

Explanation : The path length between node 4 and 5 is of length 4.
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
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter=0;
        height(root,diameter);
        return diameter;
    }
    private :
     int height(TreeNode* node, int& diameter) {
               if (!node) {
                    return 0;
               }
               int leftHeight = height(node->left, diameter);
               int rightHeight = height(node->right, diameter);
               diameter = max(diameter, leftHeight + rightHeight);
               return 1 + max(leftHeight, rightHeight);
          }
};

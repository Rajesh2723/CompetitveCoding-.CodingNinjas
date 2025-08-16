/*
Given the roots of two binary trees p and q, write a function to check if they are the same or not.



Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.


Examples:
Input : p = [1, 2, 3] , q = [1, 2, 3]

Output : true

Explanation : Both trees images are shown below









Input : p = [1, 2, 1] , q = [1, 1, 2]

Output : false

Explanation : Both trees images are shown below
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p and !q)return true;
         if(!p || !q)return false;
         if(p->data != q->data)return false;
        return isSameTree(p->left,q->left) and (isSameTree(p->right,q->right));
    }
};

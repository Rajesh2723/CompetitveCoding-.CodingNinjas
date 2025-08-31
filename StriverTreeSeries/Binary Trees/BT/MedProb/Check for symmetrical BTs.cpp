/*
Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).


Examples:
Input : root = [1, 2, 2, 3, 4, 4, 3]

Output : true

Explanation :



Input : root = [1, 2, 2, null, 3, null, 3]

Output : false

Explanation : When a straight line is drawn through the root node and the tree is folded around it, the rightmost node 3 is overlapped with null node and the node 3 present at left of root node is overlapped with null nodes.

So both node 3 in tree does not show symmetric behaviour.



Input: root = [1, 2, 3]
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
    bool isSymmetric(TreeNode* root) {
        if(!root)return true;
        return isMirror(root->left,root->right);
    }
    bool isMirror(TreeNode *t1,TreeNode*t2){
        if(!t1 and !t2)return true;
        if(!t1 || !t2)return false;
        if(t1->data !=t2->data)return false;
        return (isMirror(t1->left,t2->right)&&(isMirror(t1->right,t2->left)));
    }
};

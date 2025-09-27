/*
Given the root of a binary search tree (BST) and an integer val.



Find the node in the BST that the node's value equals val and return the subtree rooted with that node. If such a node does not exist, return null.


Examples:
Input : root = [4, 2, 7, 1, 3] , val = 2

Output : [2, 1, 3]
  */
class Solution {	
public:	
    TreeNode* searchBST(TreeNode* node, int val) {
        if(!node)return nullptr;
        if(node->data==val){
            return node;
        }
        if(node->data>val){
            return searchBST(node->left,val);
        }
        if(node->data<val){
           return searchBST(node->right,val);
        }
        
    }
     

};

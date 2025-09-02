/*
Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).


Examples:
Input : root = [1, 2, 3, null, 4, 8, 5]

Output : [ [1] , [3, 2], [4, 8, 5] ]

Explanation : So at root we move from left to right.

At next level we move in opposite direction i.e. from right to left.

At next level again reverse the traversal i.e. from left to right.





Input : root = [3, 9, 20, null, null, 15, 7]

Output : [ [3] , [20, 9], [15, 7] ]

Explanation : So at root we move from left to right.

At next level we move in opposite direction i.e. from right to left , from 20 to 9.

At next level again reverse the traversal i.e. from left to right, from 15 to 7.





Input : root = [5, 1, 2, 8, null, 4, 5, null, 6]

Output:
[ [5], [2, 1], [8, 4, 5], [6] ]
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
    vector<vector<int> > zigzagLevelOrder(TreeNode* root) {
        vector<vector<int> >ans;
        queue<TreeNode*>q;
        q.push(root);
        bool leftToRight=true;
        while(!q.empty()){
            int n=q.size();
            vector<int>mid(n);
            for(int i=0;i<n;i++){
                TreeNode*node=q.front();
                q.pop();
                int index=leftToRight?i:(n-1-i);//n-1,n-2,n-3,n-4
                mid[index]=node->data;
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
            ans.push_back(mid);
            leftToRight=!leftToRight;
        }
        return ans;
    }
};

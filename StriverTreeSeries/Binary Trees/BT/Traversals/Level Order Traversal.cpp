/*
Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).


Examples:
Input : root = [3, 9, 20, null, null, 15, 7]

Output : [ [3] , [9, 20] , [15, 7] ]


Input : root = [1, 4, null, 4 2]

Output : [ [1] , [4] , [4, 2] ]

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
    vector<vector<int> > levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        queue<TreeNode*>q;
        if(!root)return ans;
        TreeNode*node=root;
        q.push(node);
        while(!q.empty()){
            vector<int>mid;
            int n=q.size();
            for(int i=0;i<n;i++){
                 TreeNode*t=q.front();
            q.pop();
            if(t->data){mid.push_back(t->data);}
            if(t->left){
                q.push(t->left);
            }
            if(t->right){
                q.push(t->right);
            }
            }
           ans.push_back(mid);
        }
        return ans;
    }
};

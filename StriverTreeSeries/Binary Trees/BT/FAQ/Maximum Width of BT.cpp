/*
Given the root of a binary tree, return the maximum width of the given tree.



The maximum width of a tree is the maximum width among all levels. The width of a level is determined by measuring the distance between its end nodes, which are the leftmost and rightmost non-null nodes. The length calculation additionally takes into account the null nodes that would be present between the end nodes if a full binary tree were to stretch down to that level.


Examples:
Input : root = [1, 3, 2, 5, 3, null, 9]

Output : 4

Explanation :

So if the below tree would be a full binary tree then there would be total 4 nodes in the last level.

So the maximum width of the binary tree is between the nodes with value 5 and 9 is equal to 4.


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
    long long int widthOfBinaryTree(TreeNode* root) {
        long long ans=0;
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        while(!q.empty()){
            int size=q.size();
            int minn=q.front().second;
            long long first,last;
            for(int i=0;i<size;i++){
                TreeNode*node=q.front().first;
                int cur_id=q.front().second-minn;
                q.pop();
                if(i==0)first=cur_id;
                if(i==size-1)last=cur_id;
                if(node->left)q.push({node->left,cur_id*2+1});
                if(node->right)q.push({node->right,cur_id*2+2});
            }
            ans=max(ans,last-first+1);
        }
        return ans;
    }
};

/*
Given the root of a binary tree, return the top view of the binary tree.



Top view of a binary tree is the set of nodes visible when the tree is viewed from the top. Return nodes from the leftmost node to the rightmost node. Also if 2 nodes are outside the shadow of the tree and are at the same position then consider the left ones only(i.e. leftmost). 


Examples:
Input : root = [1, 2, 3, 4, 5, 6, 7]

Output : [4, 2, 1, 3, 7]

Explanation :



Input : root = [10, 20, 30, 40, 60, 90, 100]

Output : [40, 20, 10, 30, 100]

Explanation :



Input : root = [5, 1, 2, 8, null, 4, 5, null, 6]

Output:
[8, 1, 5, 2, 5]
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

class Solution{
    public:
    vector<int> topView(TreeNode *root){
        vector<int>ans;
        map<int,int>map;
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        while(!q.empty()){
            TreeNode*node=q.front().first;
            int hd=q.front().second;
            q.pop();
            if(map.find(hd)==map.end()){
                map[hd]=node->data;
            }
            if(node->left)q.push({node->left,hd-1});
            if(node->right)q.push({node->right,hd+1});
        }
        for(auto &x:map){
            ans.push_back(x.second);
        }
        return ans;
    }
};

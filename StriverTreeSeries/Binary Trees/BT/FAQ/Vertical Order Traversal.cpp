/*
Compute the binary tree's vertical order traversal given its root.

The left and right children of a node at location (row, col) will be at (row + 1, col - 1) and (row + 1, col + 1), respectively. The tree's root is located at (0, 0).



The vertical order traversal of a binary tree is a list of top-to-bottom orderings for each column index starting from the leftmost column and ending on the rightmost column. There may be multiple nodes in the same row and same column. In such a case, sort these nodes by their values. Return the binary tree's vertical order traversal.


Examples:
Input : root = [3, 9, 20, null, null, 15, 7]

Output : [ [9] , [3, 15] , [20] , [7] ]

Explanation :

Column -1: Only node 9 is in this column.

Column 0: Nodes 3 and 15 are in this column in that order from top to bottom.

Column 1: Only node 20 is in this column.

Column 2: Only node 7 is in this column.



Input : root = [1, 2, 3, 4, 5, 6, 7]

Output : [ [4] , [2] , [1, 5, 6] , [3] , [7] ]

Explanation :

Column -2: Only node 4 is in this column.

Column -1: Only node 2 is in this column.

Column 0: Nodes 1, 5, and 6 are in this column.1 is at the top, so it comes first. 5 and 6 are at the same position (2, 0), so we order them by their value, 5 before 6.

Column 1: Only node 3 is in this column.

Column 2: Only node 7 is in this column.

  */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *      TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
 * };
 */

class Solution {
public:
    vector<vector<int> > verticalTraversal(TreeNode* root) {
    	vector<vector<int>>ans;
        map<int,map<int,priority_queue<int,vector<int>,greater<int>>>>nodesMap;
        queue<pair<TreeNode*,pair<int,int>>>q;
        q.push({root,{0,0}});
        while(!q.empty()){
            auto p=q.front();
            q.pop();
            TreeNode*node=p.first;
            int x=p.second.first;
            int y=p.second.second;
            nodesMap[x][y].push(node->data);
            if(node->left)q.push({node->left,{x-1,y+1}});
            if(node->right)q.push({node->right,{x+1,y+1}});
        }
        for(auto &p:nodesMap){
            vector<int>column;
            for(auto &q:p.second){
                while(!q.second.empty()){
                    column.push_back(q.second.top());
                    q.second.pop();
                }
            }
            ans.push_back(column);
        }
        return ans;
    }
};

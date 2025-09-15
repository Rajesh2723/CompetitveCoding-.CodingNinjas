/*
Given the root of a binary tree, the value of a target node target, and an integer k. Return an array of the values of all nodes that have a distance k from the target node.



The answer can be returned in any order (N represents null).


Examples:
Input : root = [3, 5, 1, 6, 2, 0, 8, N, N, 7, 4] , target = 5, k = 2

Output : [1, 4, 7]

Explanation : The nodes that are a distance 2 from the target node (with value 5) have values 7, 4, and 1.
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
	vector<int> distanceK(TreeNode* root, TreeNode* target, int k){
		unordered_map<TreeNode*,TreeNode*>parentMap;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode*node=q.front();
            q.pop();
            if(node->left){
                parentMap[node->left]=node;
                q.push(node->left);
            }
            if(node->right){
                parentMap[node->right]=node;
                q.push(node->right);
            }
        }
        vector<int>result;
        unordered_set<TreeNode*>visited;
        q.push(target);
        visited.insert(target);
        int currentDistance=0;
        while(!q.empty()){
            if(currentDistance==k){
                while(!q.empty()){
                    result.push_back(q.front()->data);
                    q.pop();
                }
                return result;
            }
            int size=q.size();
            for(int i=0;i<size;i++){
                TreeNode*node=q.front();
                q.pop();

                if(node->left && visited.find(node->left)==visited.end()){
                    q.push(node->left);
                    visited.insert(node->left);
                }
                if(node->right && visited.find(node->right)==visited.end()){
                    q.push(node->right);
                    visited.insert(node->right);
                }
                if(parentMap.find(node)!=parentMap.end() && visited.find(parentMap[node])==visited.end()){
                    q.push(parentMap[node]);
                    visited.insert(parentMap[node]);
                }
            }
            currentDistance++;
        }
        return result;

    }
};

/*
Problem statement
You are given an n-ary tree consisting of ‘N’ nodes. Your task is to return the zigzag level order traversal of the nodes' values of the given tree. Zigzag traversal means starting from left to right, then right to the left for the next level and then again left to right, and so on in an alternate manner.

For example:
For the given tree:
Tree1

The zigzag level order traversal will be 1 3 2 4 5 6 7.
Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= T <= 10
0 <= N <= 5000
0 <= DATA <= 10^4

Where ‘T’ is the number of test cases, and ‘N’ is the total number of nodes in the binary tree, and “DATA” is the value of the tree node.

Time Limit: 1 sec
Sample Input 1:
2
7
1 2 3 -1 4 5 6 -1 7 -1 -1 -1 -1 -1
4
1 2 3 4 -1 -1 -1 -1
Sample Output 1:
1 3 2 4 5 6 7
1 4 3 2
Explanation of Sample Input 1:
Test Case 1: Given the tree:
Tree1

The zigzag level order traversal will be 1 3 2 4 5 6 7.

Test Case 2: Given the tree:
Tree1

The zigzag level order traversal will be 1 4 3 2.
Sample Input 2:
2 
3
1 3 -1 5 -1 -1
5
10 9 8 -1 1 2 -1 -1 -1 -1
Sample Output 2:
1 3 5
10 8 9 1 2
  */
#include<bits/stdc++.h>
using namespace std;
/**************************************************
   
    class TreeNode
    {
    public:
        int val;
        vector < TreeNode* > child;
        
        TreeNode(int val)
        {
            this->val = val;
        }

        ~TreeNode()
        {
            for( int i=0 ; i<child.size();i++)
            {
                delete child[i];
            }
        }
    };
    
*****************************************************/

vector<int> zigzagLevelOrder(int n, TreeNode* root)
{
     vector<int> result,ans;
     if(root==NULL) return result;
     queue<TreeNode*>q;
     q.push(root);
     int x=0;
      while(!q.empty()){
          int level=q.size();
          for(int i=0;i<level;i++){
              TreeNode* temp=q.front();
              q.pop();
                     
              ans.push_back(temp->val);
            for( int i=0 ; i<temp->child.size();i++)//we have to take all the childs of upto temp size.
                {
                    q.push(temp->child[i]);
                }
          }
          if(x%2!=0){
              reverse(ans.begin(),ans.end());
          }
          for(auto &x:ans){
              result.push_back(x);
          }
          ans.clear();
          x+=1;
          
      }
      return result;
}

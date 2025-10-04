/*
Given a sorted dictionary of an alien language having N words and K starting alphabets of a standard dictionary. Find the order of characters in the alien language.

There may be multiple valid orders for a particular test case, thus you may return any valid order as a string. The output will be True if the order returned by the function is correct, else False denoting an incorrect order. If the given arrangement of words is inconsistent with any possible letter ordering, return an empty string "".


Examples:
Input: N = 5, K = 4, dict = ["baa","abcd","abca","cab","cad"]



Output: b d a c



Explanation: 

We will analyze every consecutive pair to find out the order of the characters.

The pair “baa” and “abcd” suggests ‘b’ appears before ‘a’ in the alien dictionary.

The pair “abcd” and “abca” suggests ‘d’ appears before ‘a’ in the alien dictionary.

The pair “abca” and “cab” suggests ‘a’ appears before ‘c’ in the alien dictionary.

The pair “cab” and “cad” suggests ‘b’ appears before ‘d’ in the alien dictionary.

So, [‘b’, ‘d’, ‘a’, ‘c’] is a valid ordering.

Input: N = 3, K = 3, dict = ["caa","aaa","aab"]



Output: c a b



Explanation: Similarly, if we analyze the consecutive pair 

for this example, we will figure out [‘c’, ‘a’, ‘b’] is 

a valid ordering.
*/
class Solution {
public:
	string findOrder(string dict[], int N, int K) {
        string ans;
		vector<int>adj[K];
        vector<int>inDegree(K,0);
        for(int i=1;i<N;i++){
            string first=dict[i-1];
            string second=dict[i];
            int start=0,end=0;
            while(start<first.size() and end<second.size()){
                if(first[start]==second[end]){
                    start++;
                    end++;
                }else {
                    int u=first[start]-'a';
                    int v=second[end]-'a';
                    adj[u].push_back(v);
                    inDegree[v]++;
                    break;
                }
            }
        }
        queue<int>q;
        for(int i=0;i<K;i++){
            if(inDegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int node=q.front();
            ans.push_back(node+'a');
            q.pop();
            for(auto it:adj[node]){
                inDegree[it]--;
                if(inDegree[it]==0){
                    q.push(it);
                }
            }
        }
        return ans;
	}
};

/*
Problem statement
You are given two arrays of non-negative integers say ‘arr1’ and ‘arr2’. Your task is to find the maximum value of ( ‘A’ xor ‘B’ ) where ‘A’ and ‘B’ are any elements from ‘arr1’ and ‘arr2’ respectively and ‘xor’ represents the bitwise xor operation.

Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <=  T  <= 5
1 <=  N, M <= 1000
0 <=  arr1[i], arr2[i]  <= 10 ^ 9

Where 'T' denotes the number of test cases, 'N', ‘M’ denotes the number of elements in the first array and second array, ‘arr1[i]', and ‘arr2[i]’ denotes the 'i-th' element of the first array and second array.

Time limit: 1 sec
Sample Input 1:
1
7 7
6 6 0 6 8 5 6
1 7 1 7 8 0 2
Sample Output 1:
15
Explanation of sample input 1:
First testcase:
Possible pairs are (6, 7), (6, 8), (6, 2), (8, 7), (8, 8), (6, 2). And 8 xor 7 will give the maximum result i.e. 15
Sample Input 2:
1
3 3
25 10 2
8 5 3
Sample Output 2:
28
Explanation of sample input 2:
First test case:
28 is the maximum possible xor given by pair = (25, 5). It is the maximum possible xor among all possible pairs.
  */
//brute force approach ...it does pass some test cases.
int maxXOR(int n, int m, vector<int> &arr1, vector<int> &arr2) 
{
    int maxi=0;
    for(int i=0;i<arr1.size();i++){
        for(int j=0;j<arr2.size();j++){
            maxi=max(maxi,arr1[i]^arr2[j]);
        }
    } 
    return maxi;
}

///optimized approach using tries.
struct Node{
    Node*links[2];
    
    bool Containskey(int bit){
        return links[bit]!=NULL;
    }
    Node*get(int bit){
        return links[bit];
    }
    void put(int bit,Node *node){
        links[bit]=node;
    }


};
class Trie{
    private:Node *root;
    
    public:
    Trie(){
        root=new Node();
    }
    public:
    void insert(int num){
        Node *node=root;
        for(int i=31;i>=0;i--){
            int bit=(num>>i)&1;
            if(!node->Containskey(bit)){
                node->put(bit,new Node());
            }
            node=node->get(bit);
        }
    }
     public:
    int getMax(int num){
        Node*node=root;
        int maxNum=0;
       for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1; // Corrected the bit extraction
            if (node->Containskey(1 - bit)) { // Checking for opposite bit
                maxNum |= (1 << i);
                node = node->get(1 - bit);
            } else {
                node = node->get(bit);
            }
        }
        return maxNum;
    }

};
int maxXOR(int n, int m, vector<int> &arr1, vector<int> &arr2) 
{
    Trie trie;
    for(auto &it:arr1){
        trie.insert(it);
    }
    int maxi=0;
    for(auto it:arr2){
        maxi=max(maxi,trie.getMax(it));
    }
    return maxi;
}

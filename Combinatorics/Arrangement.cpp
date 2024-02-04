/*
Problem statement
You are given a number 'N'. Your goal is to find the number of permutations of the list 'A' = [1, 2, ......, N], satisfying either of the following conditions:

A[i] is divisible by i or i is divisible by A[i], for every 'i' from 1 to 'N'.

Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= T <= 10
0 <= N <= 15

Time Limit: 1 sec
Sample Input 1:
2
1
2
Sample Output 1:
1
2
Explanation for Sample Input 1:
In test case 1:
The only permutation is A=[1]
    A[1] = 1 is divisible by i = 1

The permutation is satisfying the conditions therefore answer is 1

In test case 2:
The 1st permutation is A=[1,2]:
    A[1] = 1 is divisible by i = 1
    A[2] = 2 is divisible by i = 2
The 2nd permutation is A=[2,1]:
    A[1] = 2 is divisible by i = 1
    i = 2 is divisible by A[2] = 1

Both permutations are satisfying either of the conditions therefore answer is 2
Sample Input 2:
2
3
4
Sample Output 2:
3
8
  */
// int ans=0;
// void f(int pos,vector<bool>&visited,int n){
//     if(pos>n){
//         ans++;
//     }
//     for(int i=1;i<n;i++){
//         if(!visited[i] and (i*pos || i/pos)){
//             visited[i]=true;
//             f(pos+1,visited,n);
//             visited[i]=false;
//         }
//     }

// }
// int countArrangement(int n) {
//      vector<bool>visited(n,false);
//     f(0,visited,n); 
//      return ans;
// }



void f(int pos, vector<bool> &visited, int n,int &ans) {
    if (pos == n) {
        ans++;
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (!visited[i] && ((pos+1)%i == 0 || i % (pos+1) == 0)) {  //checking for both 
            visited[i] = true;
            f(pos + 1, visited, n,ans);
            visited[i] = false;//for recheking of 1,2,3,4->for 4 we have 8 also as multiple we should check that also .
        }
    }
}

int countArrangement(int n) {
    vector<bool> visited(n + 1, false);
    int ans = 0;
    f(1, visited, n,ans);
    return ans;
}


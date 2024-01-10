/*
Problem statement
Gary is bored and wants to play an interesting but tough game . So he figured out a new board game called "destroy the neighbours" . In this game there are N integers on a board. In one move, he can pick any integer x from the board and then all the integers with value x+1 or x-1 gets destroyed .This move will give him x points.

He plays the game until the board becomes empty . But as he want show this game to his friend Steven, he wants to learn techniques to maximise the points to show off . Can you help Gary in finding out the maximum points he receive grab from the game ?

Detailed explanation ( Input/output format, Notes, Images )
Constraints :
 1 <= T <= 50
 1 <= N <= 10^5
 1 <= A[i] <= 1000
Sample Input :
1
2
1 2
Sample Output :
2
Explanation:
Gary can receive a maximum of 2 points, by picking the integer 2. 
  */
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int maxPoints(ll n,vector<int>&arr){
    int m=0;
    for(int i=0;i<1000;i++){
        m=max(m,arr[i]);
    }
    int freq[1002]={0};
    for(int i=0;i<n;i++){
        freq[arr[i]]++;
    }
    int dp[1002];
    dp[0]=0;
    dp[1]=freq[1];
    for(int i=2;i<=1000;i++){
            dp[i]=max(dp[i-1],dp[i-2]+i*freq[i]);//if we are picking ith element i-1 is skipped and i-2 can pic 
    }
    return dp[1000];
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
         vector<int>arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
         
        cout<<maxPoints(n,arr)<<endl;//just pass n only not n-1)
    }

    return 0;
}

/*
Valid pairs
Send Feedback
Given an array of integers and numbers k and m, write a function that returns true if given array can be divided into pairs such that the sum of every pair gives remainder m when divided by k.
Input format :
Line 1 : Integer N 
Line 2 : N integers separated be a single space
Line 3 : Integer K
Line 4 : Integer M
Output Format :
 Boolean
Constraints :
 1 <= N <= 10^4
 1 <= M < K <= 10^2
Sample Input :
4
2 1 5 7
9
3
Sample Output :
true
Explanation :
Pairs will be (2,1) and (5,7)
*/
#include<bits/stdc++.h>
bool CheckSumPairs(int arr[], int n, int k, int m) {

  unordered_map<int,int>map;
    for(int i=0;i<n;i++){
        map[arr[i]%k]++;
    }
    
    
    int check1,check2;
    for(int i = 0; i<n;i++){
        check1 = map[arr[i]%k];
        
        if(arr[i]%k <=m){
            check2 = map[m-arr[i]%k];
        }
        else{
            check2 = map[k-(arr[i]%k) +m];
        }
        if(check1 !=check2)
            return false;
    }
    return true;
    
   
}
#include <bits/stdc++.h>
using namespace std;
#include "solution.h"

int main() {
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int k,m;
	cin>>k>>m;
	if(CheckSumPairs(arr,n,k,m))
		cout<<"true";
	else
		cout<<"false";
}

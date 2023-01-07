/*
Minimum Absolute Difference in Array
Send Feedback
Given an integer array A of size N, find and return the minimum absolute difference between any two elements in the array.
We define the absolute difference between two elements ai and aj (where i != j ) as |ai - aj|.
Input format :
The first line of input contains an integer that denotes the number of test cases. Let us denote it by the symbol T. 
Each of the test cases contain two lines. The first line of each test case contains an integer, that denotes the value of N. The following line contains N space separated integers, that denote the array elements.
Constraints :
1 <= T <= 10
2 <= N <= 10^5
0 <= arr[i] <= 10^8
Output Format :
You have to print minimum difference for each test case in new line.
Sample Input 1:
1
5
2 9 0 4 5
Sample Output 1:
1
*/
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int minAbsoluteDiff(int arr[], int n) {

  sort(arr, arr + n);
  int minimum = INT_MAX;
  for (int i = 1; i < n; i++) {
    minimum = min(minimum, arr[i] - arr[i - 1]);
  }
  return minimum;
}

int main() {

int t;
cin>>t;
while (t--) {
  int size;
  cin >> size;

  int *input = new int[1 + size];

  for (int i = 0; i < size; i++)
    cin >> input[i];

  cout << minAbsoluteDiff(input, size) << endl;
}
  return 0;
}

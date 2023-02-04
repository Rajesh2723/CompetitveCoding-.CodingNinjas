/*
Aggressive Cows
Send Feedback
Given an array of length ‘N’, where each element denotes the position of a stall. Now you have ‘N’ stalls and an integer ‘K’ which denotes the number of cows that are aggressive. To prevent the cows from hurting each other, you need to assign the cows to the stalls, such that the minimum distance between any two of them is as large as possible. Return the largest minimum distance.
Input format :
The first line contains a single integer ‘T’ denoting the number of test cases.

The first line of each test case contains two integers ‘N’ and ‘K’ denoting the number of elements in the array/list and the number of aggressive cows.

The second line contains ‘N’ single space-separated integers denoting the elements of the array.
Output format :
For each test case, print the majority element in a separate line.
Note :
You do not need to print anything; it has already been taken care of.
Constraints :
1 <= T <= 5
2 <= N <= 20000
2 <= C <= N
0 <= ARR[i] <= 10 ^ 9

Where ‘T’ is the number of test cases, 'N' is the length of the given array and, ARR[i] denotes the i-th element in the array.

Time Limit: 1 sec.
Sample Input 1 :
2
3 2
1 2 3
5 2
4 2 1 3 6
Sample Output 1 :
2
5
Explanation to Sample Input 1 :
In the first test case, the largest minimum distance will be 2 when 2 cows are placed at positions {1, 3}.

In the second test case, the largest minimum distance will be 5 when 2 cows are placed at positions {1, 6}.
Sample Input 2 :
2
6 4
0 3 4 7 10 9
6 3
0 4 3 7 10 9
Sample Output 2 :
3
4
Explanation to Sample Input 2 :
In the first test case, the largest minimum distance will be 3 when 4 cows are placed at positions {0, 3, 7, 10}.

In the second test case, the largest minimum distance will be 4 when 3 cows are placed at positions {0, 4, 10}.
*/
int ispossible(vector<int>&stalls,int n,int k,int mid){
   int latpos=stalls[0];
   int cowcount=1;
   for(int i=0;i<n;i++){
      if(stalls[i]-latpos>=mid){
         cowcount++;
         if(cowcount==k){
            return true;
         }
         latpos=stalls[i];
      }
   }
   return false;
}
int aggressiveCows(vector<int> &stalls, int k)
{
   sort(stalls.begin(),stalls.end());
   int n=stalls.size();
   int start=0;
   int ans=-1;
   int end=stalls[n-1];
  while(start<=end){
     int mid=start+(end-start)/2;
     if(ispossible(stalls,n,k,mid)){
        ans=mid;
        start=mid+1;
     }else{
        end=mid-1;
     }
  }
  return ans;
}
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;
#include "solution.h"

class Runner
{
    int t;
    vector<vector<int>> arr;
    vector<int> k;

public:
    void takeInput()
    {
        cin >> t;
        arr.resize(t);
        k.resize(t);
        for (int c = 0; c < t; c++)
        {
            int n;
            cin >> n;
            arr[c].resize(n);

            cin >> k[c];
            for (int i = 0; i < n; i++)
            {
                cin >> arr[c][i];
            }
        }
    }

    void execute()
    {
        vector<vector<int>> arrCopy = arr;
        vector<int> kCopy = k;
        for (int i = 0; i < t; i++)
        {
            int ans = aggressiveCows(arrCopy[i], kCopy[i]);
        }
    }

    void executeAndPrintOutput()
    {
        for (int i = 0; i < t; i++)
        {
            int ans = aggressiveCows(arr[i], k[i]);
            cout << ans << "\n";
        }
    }
};

int main()
{
    Runner runner;
    runner.takeInput();
    runner.executeAndPrintOutput();

    return 0;
}

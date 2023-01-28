/*
Relative Sorting
Send Feedback
Given two arrays ‘ARR’ and ‘BRR’ of size ‘N’ and ‘M’ respectively. Your task is to sort the elements of ‘ARR’ in such a way that the relative order among the elements will be the same as those are in ‘BRR’. For the elements not present in ‘BRR’, append them in the last in sorted order.
For example
Consider the arrays as ARR = { 9, 5, 8, 4, 6, 5 } and BRR = { 8, 4, 5 }
The output for the above example  is { 8, 4, 5, 5, 6, 9 }.
Note:
Elements of ‘BRR’ are non repeating.
Input Format:
The first line contains an integer 'T' which denotes the number of test cases or queries to be run. Then, the ‘T’ test cases follow.

The first line of each test case or query contains two single-space separated integers 'N' and ‘M’ representing the size of the ‘ARR’ and ‘BRR’ respectively.

The second line contains 'N' single space-separated integers, representing the elements of array ‘ARR’.

The third line contains 'M' single space-separated integers, representing the elements of array ‘BRR’.
Output format:
For each test case, print ‘N’ single space-separated integers, representing the elements of ‘ARR’ after the required sorting order in a single line.

Print the output of each test case in a separate line.
Note:
You do not need to print anything, it has already been taken care of. Just implement the given function.
Constraints:
1 <= T <= 5
1 <= N <= 10 ^ 5
1 <= M <= 10 ^ 5
(-10 ^ 9) <= ARR[i] , BRR[i]  <= (10 ^ 9) 

Time limit: 1 sec
Sample Input 1:
2
6 3
9 5 8 4 6 5 
8 4 5
4 4
1 8 1 6 
1 9 6 7 
Sample Output 1:
8 4 5 5 6 9
1 1 6 8
Explanation:
For test case 1:
As 8 comes first in BRR, so we first add all occurrences of 8 in ARR, in our resultant array RES. Now, RES={8} and ARR={9,5,4,6,5}.
After 8, 4 comes in BRR, so we add all occurrences of 4 that are in ARR, in the RES array. Now, RES={8,4} and ARR={9,5,6,5}.
After 4, 5 comes in BRR, so we add all occurrences of 5 that are in ARR, in the RES array. Now, RES={8,4,5,5} and ARR={9,6}.
Now, after processing all the elements of BRR, we will add the remaining elements of ARR in sorted order, in our RES array.
So the final RES is {8,4,5,5,6,9}.

For test case 2: 
As 1 comes first in BRR, so we first add all occurrences of 1 in ARR, in our resultant array RES. Now, RES={1,1} and ARR={8,6}.
After 1, 9 comes in BRR, so we add all occurrences of 9 that are in ARR, in the RES array, but 9 is not present in ARR, so RES remains the same. Now, RES={1,1} and ARR={8,6}.
After 9, 6 comes in BRR, so we add all occurrences of 6 that are in ARR, in the RES array. Now, RES={1,1,6} and ARR={8}.
After 9, 7 comes in BRR, so we add all occurrences of 7 in ARR, in our RES, but 7 is not present in ARR, so RES remains the same. Now, RES={1,1,6} and ARR={8}.
Now, after processing all the elements of BRR, we will add the remaining elements of ARR in sorted order, in our RES array.
So the final RES is {1,1,6,8}.
Sample Input 2:
2
3 5
7 5 8  
8 4 5 6 3
4 2
9 2 2 4 
5 2 
Sample Output 2:
8 5 7
2 2 4 9
*/
#include<algorithm>
#include<unordered_map>
vector<int> relativeSorting(vector<int> &arr, vector<int> &brr, int n, int m)
{
   unordered_map<int,int>map;
   for(int i=0;i<n;i++){
       map[arr[i]]++;
   }
   vector<int>ans;
   for(int i=0;i<m;i++){
       if(map.count(brr[i])==0){
           continue;
       }else{
           while(map[brr[i]]!=0){
               ans.push_back(brr[i]);
               map[brr[i]]--;
           }
           map.erase(brr[i]);
       }
   }
   vector<int>rem;
   for(auto x:map){
       while(x.second!=0){
           rem.push_back(x.first);
           x.second--;
       }
   }
   sort(rem.begin(),rem.end());
   ans.insert(ans.end(),rem.begin(),rem.end());
   return ans;
}
#include <iostream>
#include <vector>
using namespace std;

#include "solution.h"

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, m;
        cin >> n >> m;

        vector<int> arr(n);

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        vector<int> brr(m);

        for (int i = 0; i < m; i++)
        {
            cin >> brr[i];
        }

        vector<int> result = relativeSorting(arr, brr, n, m);

        for (int i = 0; i < n; i++)
        {
            cout << result[i] << " ";
        }
        cout << endl;
    }
}

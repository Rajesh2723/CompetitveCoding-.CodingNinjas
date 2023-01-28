/*
Minimum number of swaps required to sort an array
Send Feedback
You have been given an array 'ARR' of 'N' distinct elements.
Your task is to find the minimum no. of swaps required to sort the array.
For example:
For the given input array [4, 3, 2, 1], the minimum no. of swaps required to sort the array is 2, i.e. swap index 0 with 3 and 1 with 2 to form the sorted array [1, 2, 3, 4].
Input Format:
The first line of input contains an integer ‘T’ representing the number of test cases. Then the test cases follow.

The first line of each test case contains an integer ‘N’ representing the size of the input array.

The second line of each test case contains the 'N' elements of the array separated by a single space.
Output Format:
For each test case, print a single line containing a single integer which represents the minimum no. of swaps required to sort the array.

The output for each test case is in a separate line.
Note:
You do not need to print anything; it has already been taken care of. Just implement the given function.
Constraints:
1 <= T <= 100
1 <= N <= 1000
0 <= ARR[i] <= 10 ^ 9

Where 'ARR[i]' is the value of the input array elements.

Time Limit: 1 sec
Sample Input 1:
2
4
4 3 2 1
5
1 5 4 3 2
Sample Output 1:
2
2
Explanation of Sample Input 1:
For the first test case, swap index 0 with 3 i.e. 4 -> 1 and 1 with 2 i.e. 3 -> 2 to form the sorted array {1, 2, 3, 4}.

For the second test case, swap index 1 with 4 i.e. 5 -> 2 and 2 with 3 i.e. 4 -> 3 to form the sorted array {1, 2, 3, 4, 5}.
Sample Input 2:
2
4
1 2 3 4
6
3 5 2 4 6 8
Sample Output 2:
0
3
*/
int minSwaps(vector<int> &arr)
{
	vector<pair<int,int>>res;
      for(int i=0;i<arr.size();i++)
          res.push_back({arr[i],i});
      sort(res.begin(),res.end());
   int cnt=0;
   for(int i=0;i<arr.size();i++){
       if(res[i].first!=arr[i]){
           swap(res[i],res[res[i].second]);
           cnt++;
         i--;
       }
   }
   return cnt;
}
#include <algorithm>
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
using namespace std;

#include "solution.h"

int main() {
    // For Fast IO
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> arr(n);

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        int ans = minSwaps(arr);

        cout << ans << endl;
    }
}

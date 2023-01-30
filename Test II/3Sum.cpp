/*
3Sum
Send Feedback
You are given an array/list ARR consisting of N integers. Your task is to find all the distinct triplets present in the array which adds up to a given number K.
An array is said to have a triplet {ARR[i], ARR[j], ARR[k]} with sum = 'K' if there exists three indices i, j and k such that i!=j, j!=k and i!=j and ARR[i] + ARR[j] + ARR[k] = 'K'.
Note:
1. You can return the list of values in any order. For example, if a valid triplet is {1, 2, -3}, then {2, -3, 1}, {-3, 2, 1} etc is also valid triplet. Also, the ordering of different triplets can be random i.e if there are more than one valid triplets, you can return them in any order.
2. The elements in the array need not be distinct.
3. If no such triplet is present in the array, then return an empty list, and the output printed for such a test case will be "-1".
Input Format:
The first line of the input contains an integer T, denoting the number of test cases.

The first line of each test case contains the integer N, denoting the size of the array.

The second line of each test case contains N space-separated integers denoting the array elements.

The third line of each test case contains the integer K, denoting the required sum for each triplet.
Output Format:
For each test case, every line of output contains three spaced integers denoting a valid triplet as described in the statement. Refer to sample input 2 for more clarification.
Note :
You do not need to print anything, it has already been taken care of. Just implement the given function.
Constraints:
1 <= T <=  50
1 <= N <= 10^3  
-10^6 <= ARR[i] <= 10^6
-10^9 <= K <= 10^9

Time Limit: 1 sec
Sample Input 1:
1
5
10 5 5 5 2
12
Sample Output 1:
5 5 2
Explanation for Sample Input 1:
5 5 2 is the only triplet that adds up to 15. Note that the order of the output doesn’t matter, so 5 2 5 or 2 5 5 is also acceptable.
Sample Input 2:
3
6
1 2 3 1 2 3
6
4
1 2 3 4 
11
6
1 1 2 2 1 1
4
Sample Output 2:
1 2 3
-1
1 1 2
Explanation for Sample Input 2:
In the first input, (1, 2, 3) is the only unique triplet that adds up to six.

In the second input, since there are no such triplets, we print -1.

For the third input, the only distinct triplet is (1, 1, 2), so just print 1 1 2.
*/
#include <bits/stdc++.h> 
vector<vector<int>> findTriplets(vector<int>arr, int n, int K) {
	sort(arr.begin(),arr.end());

set<vector<int>>s;

vector<vector<int>>ans;

for(int i=0;i<n;++i)

{

int j=i+1;

int k=n-1;

while(j<k)

{

int sum=arr[i]+arr[j]+arr[k];

            if(sum==K)

{

s.insert({arr[i],arr[j],arr[k]});

j++;

k--;

}

else if(sum<K)

{

j++;

}

else 

{

k--;

}

}

}

for(auto x:s)

{

ans.push_back(x);

}

return ans;

}
	

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

#include "solution.h"

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int K;
        cin >> K;
        vector <vector<int>> ans = findTriplets(arr, n, K);
        if (ans.size() == 0) {
            cout << -1 << '\n';
            continue;
        }
        for (int i = 0; i < (int) ans.size(); i++) {
            sort(ans[i].begin(), ans[i].end());
            cout << ans[i][0] << ' ' << ans[i][1] << ' ' << ans[i][2] << '\n';

        }
    }
}

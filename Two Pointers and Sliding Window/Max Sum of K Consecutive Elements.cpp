/*
Max Sum of K Consecutive Elements
Send Feedback
You are given an array of ‘N’ integers. You have to find the maximum sum over all subarrays of size ‘K’.
For example:
If N=3, K=2 and array elements are [ -100, 20, 40 ]. Following are the subarrays of size 2:
[ -100, 20 ] having sum = -100 + 20 = -80.
[ 20, 40 ] having sum = 20 + 40 = 60.

The maximum sum between -80 and 60 is 60. Hence, the output is 60.
Input Format :
The first line of the input contains an integer, 'T’, denoting the number of test cases.

The first line of each test case will contain two space-separated integers ‘N’ and ‘K’, denoting the size of the array and the subarray size.

The second line of each test case contains ‘N’ space-separated integers denoting elements of the array.
Output Format :
For each test case, print the maximum sum over all subarrays of size ‘K’.

Print a separate line for each test case.
Note :
You do not need to print anything, it has already been taken care of. Just implement the given function.
Constraints:
1 <= T <= 10
1 <= N <= 10000
1 <= K <= N
-10000 <= nums[i] <= 10000

Time limit: 1 sec
Sample Input 1 :
2
3 2 
-100 20 40
2 1
12 -34
Sample output 1 :
60
12
Explanation For Sample Output 1:
For the first test case,
N=3, K=2 and array elements are [ -100, 20,40 ]. Following are the subarrays of size 2:
[-100, 20] having sum = -100 + 20 = -80.
[20, 40] having sum = 20 + 40 = 60.

The maximum sum between -80 and 60 is 60. Hence, the output is 60.

For the second test case,
N=2, K=1 and array elements are [ 12, -34 ]. Following are the subarrays of size 1:
[12] having sum =12.
[-34] having sum = -34.

The maximum sum between 12 and -34  is 12. Hence, the output is 12.
Sample Input 2 :
2
5 2
7 10 -6 3 5
6 6
4 8 5 -1 -9 10
Sample output 2 :
17
17
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <climits>

using namespace std;

// #include "solution.h"

/*
    Time Complexity:  O( N ).
    Space Complexity:O( 1 ).

    Where 'N' is the size of the array.
*/

int maxOfK(int n, int k, vector<int> &num)
{

    int ans = INT_MIN, sum = 0;

    // Taking sum of first k elements.
    for (int i = 0; i < k; i++)
    {
        sum += num[i];
    }

    ans = sum;
    int d = 0;

    for (int i = k; i < n; i++)
    {
        // Adding ith element.
        sum += num[i];

        // Removing ith element.
        sum -= num[d];

        d += 1;

        // Update the answer.
        ans = max(ans, sum);
    }

    // Return the ans.
    return ans;
}

class Runner
{
    int t;
    vector<int> n, k;
    vector<vector<int>> res;

public:
    void takeInput()
    {
        cin >> t;

        n.resize(t);
        k.resize(t);
        res.resize(t);

        for (int i = 0; i < t; i++)
        {
            cin >> n[i] >> k[i];
            vector<int> temp(n[i]);
            for (int j = 0; j < n[i]; j++)
            {
                cin >> temp[j];
            }
            res[i] = temp;
        }
    }

    void execute()
    {
        vector<int> nCpy = n;
        vector<int> kCpy = k;
        vector<vector<int>> resCpy = res;

        for (int i = 0; i < t; i++)
        {
            int ans = maxOfK(nCpy[i], kCpy[i], resCpy[i]);
        }
    }

    void executeAndPrintOutput()
    {
        for (int i = 0; i < t; i++)
        {
            int ans = maxOfK(n[i], k[i], res[i]);
            cout << ans << "\n";
        }
    }
};

int main()
{

#ifndef ONLINE_JUDGE
    // freopen("TestCases/large/in/input11.txt", "r", stdin);
    // freopen("TestCases/large/out/output11.txt", "w", stdout);
#endif
    Runner runner;
    runner.takeInput();
    runner.executeAndPrintOutput();
    return 0;
}
int maxOfK(int n, int k, vector<int> &num)
{
    int maxSubsum=INT_MIN;
    int sum=0;
    for(int i=0;i<k;i++){
        for(int j=0;j<n;j++){
            maxSubsum+=num[i];
            if(maxSubsum>sum){
                sum=maxSubsum;
            }
        }
    }
    return sum;
}
/*
int maxOfK(int n, int k, vector<int> &num)
{
   int cur_sum=0;
   for(int i=0;i<n;i++){
       if(k==0||k>n){
           return ;
       }
   }
   int maxi=INT_MAX;
   for(int i=0;i<n;i++){
       if(i<k){
           cur_sum+=nums[i];
       }else if(i==k-1){
           maxi=max(maxi,cur_sum);
       }else if(i>=k){
           cur_sum+=nums[i];
           cur_sum-=a[i-k];
           maxi=max(maxi,cur_sum);
       }
   }
   return maxi;
}
*/

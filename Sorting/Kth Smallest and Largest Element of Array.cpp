/*
  Kth Smallest and Largest Element of Array
Send Feedback
You are given an array ‘Arr’ consisting of ‘N’ distinct integers and a positive integer ‘K’. Find out Kth smallest and Kth largest element of the array. It is guaranteed that K is not greater than the size of the array.
Example:
Let ‘N’ = 4,  ‘Arr’ be [1, 2, 5, 4] and ‘K’ = 3.  
then the elements of this array in ascending order is [1, 2, 4, 5].  Clearly, the 3rd smallest and largest element of this array is 4 and 2 respectively.
Input format:
The first line of input contains an integer ‘T’ denoting the number of test cases.
The next 2*T lines represent the ‘T’ test cases.

The first line of each test case contains two space-separated integers  ‘N’ and ‘K’ respectively.

The second line of the test case contains ‘N’ space-separated integers representing elements of the array ‘Arr’.
Output format :
For each test case, print a line consisting of two space-separated integers that represent the Kth smallest and Kth largest elements of the array.
Note:
You do not need to print anything, it has already been taken care of. Just implement the given function. In the given function, you need to return an array consisting of 2 integers, where the first integer gives Kth smallest element and the second integer gives the Kth largest element.
Constraints:
1 <= T <= 50
1 <= N <= 10^4
1 <= K <= N
-10^9 <= Arr[i] <= 10^9

Where ‘T’ is the total number of test cases, ‘N’ is the size of array ‘Arr’ and Arr[i] is the element of the given array.

Time limit: 1 sec
Sample Input 1:
2
4 4
5 6 7 2
4 3
1 2 5 4
Sample Output 1:
7 2 
4 2
Explanation of Sample Input 1:
Test case 1:
Here, ‘N’ = 4, ‘Arr’ = [5, 6, 7, 2] and ‘K’ = 3.
Elements of the array in ascending order are [2, 5, 6, 7]
Thus the 4rd smallest and 4rd largest elements of this array are 7 and 2 respectively.

Test case 2:
See problem statement for an explanation.
Sample Input 2:
 2
 1 1
 2
 5 1
 5 4 3 2 1
Sample Output 2:
 2 2
 1 5
 */
#include<bits/stdc++.h>
vector<int> kthSmallLarge(vector<int> &arr, int n, int k)
{
	vector<int>v;
	sort(arr.begin(),arr.end());
	for(int i=0;i<n;i++){
	
			v.push_back(arr[k-1]); //kth smallest
			v.push_back(arr[n-k]); ///kth largest 
		
	}
	return v;
}
#include <iostream>
#include <vector>

using namespace std;

#include "solution.h"

class Runner
{
    int t;
    vector<vector<int>> arrs;
    vector<int> ns, ks;

public:
    void takeInput()
    {
        cin >> t;
        for (int i = 0; i < t; i++)
        {
            int n, k;
            cin >> n >> k;

            vector<int> arr(n);
            for(int i = 0; i < n; i++) 
            {
                cin >> arr[i];
            }

            ns.push_back(n);
            ks.push_back(k);
            arrs.push_back(arr);
        }
    }

    void execute()
    {
        vector<vector<int>> arrsCopy = arrs;
        vector<int> nsCopy = ns;
        vector<int> ksCopy = ks;
        for (int i = 0; i < t; i++)
        {
            vector<int> result = kthSmallLarge(arrsCopy[i], nsCopy[i], ksCopy[i]);
        }
    }

    void executeAndPrintOutput()
    {
        for (int i = 0; i < t; i++)
        {
            vector<int> result = kthSmallLarge(arrs[i], ns[i], ks[i]);
            cout << result[0] << ' ' << result[1] << '\n';
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
   

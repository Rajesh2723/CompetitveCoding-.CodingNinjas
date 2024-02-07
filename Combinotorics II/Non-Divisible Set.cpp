/*
Problem statement
A range of integers from 1 to ‘N’ is given to you. You are also given a set of integers. Return the number of integers in the given range which are not divisible by any of the elements of the given set.

For Example:
‘N’ = 7, ‘Set’ = [2, 3]

Integers in the range [1, 7] that are not divisible by any of the elements of the given set are [1, 5, 7].
The total number of non-divisible integers is 3. Hence the output will be 3.
Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1 :
2
7 2
2 3
13 3
4 7 19
Sample Output 1 :
3
9
Explanation For Sample Input 1 :
For First Case - Same as explained in above example.

For the second case - 

‘N’ = 13, ‘Set’ = [4, 7, 19]

Integers in the range [1, 13] that are not divisible by any of the elements of the given set are [1, 2, 3, 5, 6, 9, 10, 11, 13].
The total number of non-divisible integers is 9. Hence the output will be 9.
Sample Input 2 :
2
40 6
8 5 2 7 3 12
18 3
1 2 3
Sample Output 2 :
9
0
  */
#include<bits/stdc++.h>
using namespace std;
int includedElements(int n, vector<int> &arr)
{
	set<int> multiples;
    int k = arr.size(); // Size of the array 'arr'

    // Iterate through the elements of the 'arr' vector
    for (int num : arr) {
        // For finding duplicates only once
        if (multiples.find(num) == multiples.end()) {
            // Inserting all multiples of 'num' into the set
            for (int j = 1; j <= n / num; j++) {
                multiples.insert(num * j);
            }
        }
    }

    // Returning the count of numbers that are not divisible by any element in 'arr'
    return n - multiples.size();
}

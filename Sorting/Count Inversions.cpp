/*
Count Inversions
Send Feedback
For a given integer array/list 'ARR' of size 'N' containing all distinct values, find the total number of 'Inversions' that may exist.
An inversion is defined for a pair of integers in the array/list when the following two conditions are met.
A pair ('ARR[i]', 'ARR[j]') is said to be an inversion when:

1. 'ARR[i] > 'ARR[j]' 
2. 'i' < 'j'

Where 'i' and 'j' denote the indices ranging from [0, 'N').
Input format :
The first line of input contains an integer 'N', denoting the size of the array.

The second line of input contains 'N' integers separated by a single space, denoting the elements of the array 'ARR'.
Output format :
Print a single line containing a single integer that denotes the total count of inversions in the input array.
Note:
You are not required to print anything, it has been already taken care of. Just implement the given function.  
Constraints :
1 <= N <= 10^5 
1 <= ARR[i] <= 10^9

Where 'ARR[i]' denotes the array element at 'ith' index.

Time Limit: 1 sec
Sample Input 1 :
3
3 2 1
Sample Output 1 :
3
Explanation of Sample Output 1:
We have a total of 3 pairs which satisfy the condition of inversion. (3, 2), (2, 1) and (3, 1).
Sample Input 2 :
5
2 5 1 3 4
Sample Output 2 :
4
Explanation of Sample Output 1:
We have a total of 4 pairs which satisfy the condition of inversion. (2, 1), (5, 1), (5, 3) and (5, 4).
*/
#include <bits/stdc++.h> 
long long merge(long long arr[],int left,int mid,int right){
    long long temp[right-left+1];
    int i = left;
    int j=mid;
    int k = 0;
    long long count = 0;
    while(i < mid && j <= right){
        if(arr[i] <= arr[j]){
            temp[k++] = arr[i++];
        }else{
			count += mid - i;
            temp[k++] = arr[j++];
        }
    }
    while(i<mid){
        temp[k++] = arr[i++];
    }
    while(j<=right){
        temp[k++] = arr[j++];
    }
    for(int i=left,k=0;i<=right;i++,k++){
        arr[i] = temp[k];
    }
    return count;
 
}

long long merge_sort(long long  arr[],int left,int right){
    long long count = 0;
    if(right > left){
        int mid = (left+right)/2;
        long long leftCount = merge_sort(arr,left,mid);
        long long rightCount = merge_sort(arr,mid+1,right);
        long long mergeCount = merge(arr,left,mid+1,right); 
        return leftCount + rightCount + mergeCount;
    }
    
    return count;
}

long long getInversions(long long *arr, int n)
{
    long long ans = merge_sort(arr,0,n-1);
    return ans;
}
#include <iostream>
using namespace std;

#include "solution.h"

int main()
{
    int n;
    cin >> n;

    long long* arr = new long long[n];

    for(int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    cout << getInversions(arr, n);

    delete arr;
}

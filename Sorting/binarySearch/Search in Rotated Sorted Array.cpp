/*
Search in Rotated Sorted Array
Send Feedback
Aahad and Harshit always have fun by solving problems. Harshit took a sorted array consisting of distinct integers and rotated it clockwise by an unknown amount. For example, he took a sorted array = [1, 2, 3, 4, 5] and if he rotates it by 2, then the array becomes: [4, 5, 1, 2, 3].
After rotating a sorted array, Aahad needs to answer Q queries asked by Harshit, each of them is described by one integer Q[i]. which Harshit wanted him to search in the array. For each query, if he found it, he had to shout the index of the number, otherwise, he had to shout -1.
For each query, you have to complete the given method where 'key' denotes Q[i]. If the key exists in the array, return the index of the 'key', otherwise, return -1.
Note:
Can you solve each query in O(logN) ?
Input Format:
The first line of input contains the size of the array: N

The second line contains N single space-separated integers: A[i].

The third line of input contains the number of queries: Q

The next Q lines of input contain: the number which Harshit wants Aahad to search: Q[i]
Output Format:
For each test case, print the index of the number if found, otherwise -1.

Output for every test case will be printed in a separate line.
Note:
You are not required to explicitly print the expected output, just return it and printing has already been taken care of.
Constraints:
1 <= N <= 10^6
-10^9 <= A[i] <= 10^9
1 <= Q <= 10^5
-10^9 <= Q[i] <= 10^9

Time Limit: 1sec
Sample Input 1:
4
2 5 -3 0
2
5
1
Sample Output 1:
1
-1
Explanation For Sample Input 1:
In the 1st test case, 5 is found at index 1

In the 2nd test case, 1 is not found in the array, hence return -1.
Sample Input 2:
5
100 -2 6 10 11
2
100
6
Sample Output 2:
0
2
*/
int pivot1(int *arr,int n){
    int start=0;
    int end=n-1;
    int mid=start+(end-start)/2;
    while(start<end){
        if(arr[mid]>=arr[0]){
            start=mid+1;
        }else {
            end=mid;
        }
        mid=start+(end-start)/2;
    }
    return start;
}
int binarySearch(int *arr,int left,int right,int key){
    
    int mid=left+(right-left)/2;
    while(left<=right){
        if(arr[mid]==key){
            return mid;
        }else if(arr[mid]<key){
            left=mid+1;
        }else{
            right=mid-1;
        }
        mid=left+(right-left)/2;
    }
    return -1;

}

int search(int* arr, int n, int key) {
  int pivot=pivot1(arr,n);
  if(key>=arr[pivot]&&key<=arr[n-1]){
      return binarySearch(arr,pivot,n-1,key);
  }else{
      return binarySearch(arr,0,pivot-1,key);
  }
}
#include <iostream>
using namespace std;

#include "solution.h"

int main()
{
	int n;
	cin >> n;
	int* arr = new int[n];

	for(int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}

	int q;
	cin >> q;

	while(q--)
	{
		int target;
		cin >> target;
		cout << search(arr, n, target) << "\n";
	}
} 
/*
int search(int* nums, int n, int target) {
    
   
    int low = 0 , high=n-1;
        while(low<=high){
            int mid = (low+high)/2;
            if(nums[mid]==target){
                return mid;
            }else if(nums[low]<=nums[mid]){
                if(nums[low]<=target && nums[mid]>=target){
                    high=mid-1;
                }else{
                    low=mid+1;
                }
            }else{
                if(nums[mid]<=target && nums[high]>=target){
                    low=mid+1;
                }else{
                    high=mid-1;
                }
            }
        }
        return -1;
    
}*/

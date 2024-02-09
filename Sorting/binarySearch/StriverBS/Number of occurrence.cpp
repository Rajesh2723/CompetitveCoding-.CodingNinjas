/*
Problem statement
You have been given a sorted array/list of integers 'arr' of size 'n' and an integer 'x'.



Find the total number of occurrences of 'x' in the array/list.



Example:
Input: 'n' = 7, 'x' = 3
'arr' = [1, 1, 1, 2, 2, 3, 3]

Output: 2

Explanation: Total occurrences of '3' in the array 'arr' is 2.


Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1:
7 3
1 1 1 2 2 3 3


Sample Output 1:
2


Explanation For Sample Input 1:
In the given list, there are 2 occurrences of integer 3.


Sample Input 2:
 5 6
 1 2 4 4 5


Sample Output 2:
 0


Explanation For Sample Input 2:
In the given list, there are 0 occurrences of integer 6.


Expected time complexity:
The expected time complexity is O(log 'n').


Constraints:
1 <= n <= 10^4
1 <= arr[i] <= 10^9
1 <= x <= 10^9
Where arr[i] represents the element i-th element in the array/list.

Time Limit: 1sec
*/
int count1=0;
int firstOcc(vector<int>&arr,int x,int n){
    int start=0;
    int end=arr.size()-1;
     int first=0;
    while(start<=end){
        int mid=start+(end-start)/2;
        if(arr[mid]==x){
            first=mid;
            end=mid-1;
        }else if(arr[mid]<x){
            start=mid+1;
        }else{
            end=mid-1;
        }
    }
    return first;
}
int secondOcc(vector<int>&arr,int x,int n){
    int start=0;
    int end=arr.size()-1;
    int second=0;
    while(start<=end){
        int mid=start+(end-start)/2;
        if(arr[mid]==x){
            second=mid;
            start=mid+1;
        }else if(arr[mid]<x){
            start=mid+1;
        }else{
            end=mid-1;
        }
    }
    return second;
}
int count(vector<int>& arr, int n, int x) {
	 int i= firstOcc(arr,x,n);
          int j=secondOcc(arr,x,n);
		  if(i==0 and j==0){
			  return 0;
		  }
		 return j-i+1;
}

/*
Find The Repeating And Missing Number
Send Feedback
You are given an array 'nums' consisting of first N positive integers. But from the N integers, one of the integers occurs twice in the array, and one of the integers is missing. You need to determine the repeating and the missing integer.
Example:
Let the array be [1, 2, 3, 4, 4, 5]. In the given array ‘4’ occurs twice and the number ‘6’ is missing.
Input format:
The very first line of input contains an integer ‘T’ denoting the number of test cases. 

The first line of every test case contains an integer ‘N’ denoting the number of elements present in the array.

The second line of every test case contains ‘N’ space-separated integers denoting the elements present in the array.
Output format:
For each test case, print the two space-separated integers denoting the repeating and the missing numbers, in the same order.
Note:
You do not need to print anything, it has already been taken care of. Just implement the given function. 
Follow Up:
Can you solve this in O(N) time and O(1) space complexities?
Constraints:
1 <= T <= 100 
2 <= N <= 10^4
1 <= nums[i] <= N

Time Limit: 1 sec
Sample Input 1:
2
5
1 4 2 5 2
2
2 2    
Sample Output 1:
2 3
2 1
Explanation For Sample Input 1:
For the first test case we have, array: [1, 4, 2, 5, 2] and N = 5.

In the given array ‘2’ occurs twice and the number ‘3’ is missing. Hence, we output 2 and 3 for the repeating and the missing number, respectively.

For the second test case we have, array: [2, 2] and N = 2.

In the given array ‘2’ occurs twice and the number ‘1’ is missing. Hence, we output 2 and 1 for the repeating and the missing number, respectively.
Sample Input 2:
3
4
1 2 2 3
10
1 3 4 5 5 6 7 8 9 10
3
1 2 2
Sample Output 2:
2 4 
2 5 
2 3
  */
vector<int> findRepeatingAndMissingNumbers(vector<int> nums)
{
    int res = 0;

   for(int i = 0 ; i<nums.size();i++){
       res = res^nums[i];
   }
   for (int i = 1; i <= nums.size(); i++) {
     res = res^i;
   }

   int bit = res & ~(res -1);

   int x = 0,y=0;
   for(int i = 0 ; i<nums.size() ;i++){
       if(nums[i]&bit){
           x=x^nums[i];
       }else{
         y = y ^ nums[i];
       }
   }
   for (int i = 1; i <= nums.size(); i++) {
     if (i & bit) {
       x = x ^ i;
     } else {
       y = y ^ i;
     }
   }


   for(int i = 0 ; i<nums.size();i++){
    if(nums[i]==x){
        return {x,y};
    }
  
   }

   return {y,x};
}

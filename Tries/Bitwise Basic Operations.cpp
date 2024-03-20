/*
Problem statement
You are given six positive integers, ’a’, ’b’, ’c’, ’d’, ’e’, and ’f’.



You will be given three functions ’getXOR’, ’getBit’, and ’setBit’.



Your task is to do the following:

In function ‘getXOR’, you will be given two parameters, ‘a’, and ‘b’. Your task is to return the XOR of ‘a’, and ‘b’.
In the function ‘getBit’, you will be given two parameters, ‘c’ and ‘d’. Your task is to return 1 if ‘c’th bit of ‘d’ is set. Otherwise, return 0.
In the function ‘setBit’, you will be given two parameters, ‘e’ and ‘f’. Your task is to set the ‘e’th bit in ‘f’ if it is not set. At last, return integer ‘f’.
The expected time complexity is ’O(1)’, and the expected space complexity is ’O(1)’.



Note:
In the output, you will see the output of the three functions in the order of ‘getXOR’, ‘getBit’, and ‘setBit’.
Example:
Input: ‘a’ = 1, ‘b’ = 2, ‘c’ = 1, ‘d’ = 3, ‘e’ = 2, ‘f’ = 3

Output: 3 1 7

Explanation: On XORing the integers ‘a’ and ‘b’, we get ‘3’. On checking the ‘c’th bit in ‘d’, since it is present, we returned 1. On making the ‘e’th bit in ‘f’ set, the integer becomes 7.
Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1:
1 2 1 3 2 3
Sample Output 1 :
3 1 7
Explanation Of Sample Input 1:
Input: ‘a’ = 1, ‘b’ = 2, ‘c’ = 1, ‘d’ = 3, ‘e’ = 2, ‘f’ = 3

Output: 3 1 7

Explanation: On XORing the integers ‘a’ and ‘b’, we get ‘3’. On checking the ‘c’th bit in ‘d’, since it is present, we returned 1. On making the ‘e’th bit in ‘f’ set, the integer becomes 7.
Sample Input 2:
52 49 0 49 2 31
Sample Output 2:
5 1 31
Explanation Of Sample Input 2:
Input: ‘a’ = 52, ‘b’ = 49, ‘c’ = 0, ‘d’ = 49, ‘e’ = 2, ‘f’ = 31

Output: 5 1 31

Explanation: On XORing the integers ‘a’ and ‘b’, we get ‘5’. On checking the ‘c’th bit in ‘d’, since it is present, we returned 1. On making the ‘e’th bit in ‘f’ set, but since it is already set, the integer remains 31.
Constraints:
1 <= a <= 10^5
1 <= b <= 10^5
0 <= c <= 15
1 <= d <= 10^5
0 <= e <= 15
1 <= f <= 10^5

Time Limit: 1-sec
  */
int getXOR(int a, int b) {
   return a^b;
}

int getBit(int c, int d) {
     int val=1<<c;
     if(val&d){
         return 1;
     }
     return 0;
}

int setBit(int e, int f) {
    if ((f & (1 << e)) == 0) {
        // If not set, set the 'e'th bit by ORing with (1 << e)
        f |= (1 << e);
    }
    // Returning the updated 'f'
    return f;
}

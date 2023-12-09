/*
You are given an array ARR having N integers. Your task is to find the sum of Hamming Distance for each pair of the array elements.
  Hamming Distance for two given integers 'A' and 'B' is defined as the minimum number of bits that needs to be toggled to make both the integers equal.
  Consider A=4 and B=7
Binary representation of 4 = 100
Binary representation of 7 = 111
For the given example, if we flip the values of the last two least significant bits of A to 1 then A will become 7. As we can change the value of A to B by 2 flips. Therefore the Hamming Distance, in this case, is 2.
 2
3
4 1 3
2
2 2
output
  12
0
For the first test case:
All the 9 possible pairs of array elements are (4,4), (4,1), (4,3), (1,4), (1,1), (1,3), (3,4), (3,1), (3,3)
1) (4,4) => Hamming Distance = 0
2) (4,1) => Hamming Distance = 2
3) (4,3) => Hamming Distance = 3 
4) (1,4) => Hamming Distance = 2
5) (1,1) => Hamming Distance = 0
6) (1,3) => Hamming Distance = 1
7) (3,4) => Hamming Distance = 3
8) (3,1) => Hamming Distance = 1
9) (3,3) => Hamming Distance = 0
The sum of all the above values is 12. Therefore, the answer is 12 in this case.

For the second test case:
As all the elements of the array are equal, the hamming distance is 0 for every pair of array elements. Therefore the overall sum of Hamming distance is 0 in this case.
*/
/*
     Time Complexity : O(N*log(MAX))
     Space Complexity : O(log(MAX))
     
     where 'N' is the number of elements o the array and 'MAX' is the maximum value among array elements
*/

long long sumOfHammingDistance(vector<int> arr, int n) {
    // Initializing the two arrays
    int countOne[32] = { 0 };
    int countZero[32] = { 0 };

    // Iterating through all the array elements
    for (int i = 0; i < n; i++) {
        int j = 0;
        // Iterating through all the bits
        while (j < 32) {
            // Checking if the jth bit is zero
            if (arr[i] % 2 == 0) {
                countZero[j] += 1;
            } else {
                countOne[j] += 1;
            }
            // Moving to the next bit
            arr[i] /= 2;
            j++;
        }
    }

    // Initializing the answer
    long long ans = 0;

    // Iterating through all the bits
    for (int i = 0; i < 32; i++) {
        // Finding contribution of each bit
        long long int contribution = 2 * countZero[i] * countOne[i];

        // Adding the contribution to answer
        ans += contribution;
    }

    // Returning the overall sum
    return ans;
}

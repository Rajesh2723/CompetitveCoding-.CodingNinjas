/*
Problem statement
Bob lives with his wife in a city named Berland. Bob is a good husband, so he goes out with his wife every Friday to ‘Arcade’ mall.

‘Arcade’ is a very famous mall in Berland. It has a very unique transportation method between shops. Since the shops in the mall are laying in a straight line, you can jump on a very advanced trampoline from the shop i, and land in any shop between (i) to (i + Arr[i]), where Arr[i] is a constant given for each shop.

There are N shops in the mall, numbered from 0 to N-1. Bob's wife starts her shopping journey from shop 0 and ends it in shop N-1. As the mall is very crowded on Fridays, unfortunately, Bob gets lost from his wife. So he wants to know, what is the minimum number of trampoline jumps from shop 0 he has to make in order to reach shop N-1 and see his wife again. If it is impossible to reach the last shop, return -1.

Detailed explanation ( Input/output format, Notes, Images )
Constraints :
1 <= T <= 10
1 <= N <= 5 * 10^4
0 <= Arr[i] <= N
Where T is the number of test cases, N is the size of the array and Arr[i] is the ith element in the array.
Sample Input 1:
2
5
2 1 3 2 4
3
3 2 1
Sample Output 1:
2
1
Explanation For Sample Input 1:
In the 1st test case, Bobs jumps from shop 0 to shop 2 and then jumps from shop 2 to shop 4, so he needs two jumps to reach the last shop.

In the 2nd test case, Bobs jumps from shop 0 to shop 2, so he needs only one jump to reach the last shop.
Sample Input 2:
2
5
1 0 3 2 1
4
1 1 1 1
Sample Output 2:
-1
3
*/
int minimumJumps(vector<int> &arr, int n)
{
    int jumps=0;
    int curPointer=0;
    int maxReach=0;
    for(int i=0;i<n-1;i++){
        maxReach=max(maxReach,i+arr[i]);
        if(i==curPointer){
            jumps++;
            curPointer=maxReach;

            if(curPointer<=i)return -1;
        }

    }
    return curPointer>=n-1?jumps:-1;
}

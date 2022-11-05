/*
Closest Distance Pair
Send Feedback
You are given an array containing 'N' points in the plane. The task is to find out the distance of the closest points.
Note :
Where distance between two points (x1, y1) and (x2, y2) is calculated as [(x1 - x2) ^ 2] + [(y1 - y2) ^ 2].
Input Format :
The first line contains a single integer 'N' denoting the number of points.

The next 'N' lines contain two integers separated by a single space, where the first integer represents the x coordinate and the second integer represents the y coordinate.
Output Format :
The only line contains the minimum distance between the 'N' points.
Note:
You do not need to print anything, it has already been taken care of. Just implement the given function.
Constraints :
2 <= 'N' <= 10^5
-10^5 <= 'x' <= 10^5 
-10^5 <= 'y' <= 10^5

Time Limit: 1 sec
Sample Input 1:
5
1 2
2 3
3 4
5 6
2 1
Sample Output 1:
2
Explanation of Sample Output 1:
We have 2 pairs which are probable answers (1, 2) with (2, 3) and (2, 3) with (3, 4). The distance between both of them is equal to 2.
Sample Input 2 :
3
0 0
-3 -4
6 4
Sample Output 2 :
25
Explanation of Sample Output 1 :
If we choose the pairs (0, 0) and (-3, -4), the distance between them is 3^2 + 4^2 = 25. This is the optimal answer for this test case.
*/
/*
bruteforce approach we will get a TLE for this
#include <climits>

long dist(pair<int, int> &p1, pair<int, int> &p2) 
{
    //Find distance between points p1 and p2
    long dis = (long)((long)p1.first - p2.first) * (p1.first - p2.first) +
               (long)((long)p1.second - p2.second) * (p1.second - p2.second);

    return dis;
}

long closestPair(pair<int, int>* coordinates, int n) 
{
    long ans = LONG_MAX;

    for (int i = 0; i < n - 1; ++i) 
    {
        for (int j = i + 1; j < n; ++j) 
        {
            ans = min(ans, dist(coordinates[i], coordinates[j]));
        }
    }

    return ans;
}

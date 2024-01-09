/*
Problem statement
Return the number of undirected graphs that can be formed using 'N' vertices, allowing for disconnected components within the graph. Self-edges and multiple edges are not allowed.



For Example:
For N = 2,
Count is 2.
Consider the vertices to be ‘A’ and ‘B’.
These are the possible 2 graphs.  

Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1:
3
Sample Output 1:
8   
Explanation of sample output 1:
For ‘N’ = 3,
Consider the vertices to be ‘A’, ’B’ and ‘C’.
These are the possible 8 graphs.

Sample Input 2:
5
Sample Output 2:
1024
Constraints:
1 <= ‘N’ <= 8
Time Limit: 1 sec
  */
int countingGraphs(int n)
{
   return pow(2,(n*(n-1))/2);
}

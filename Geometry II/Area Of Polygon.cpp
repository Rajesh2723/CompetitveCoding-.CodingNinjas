/*
Problem statement
A convex polygon is a set of n vertices that are joined by n edges, such that no two edges intersect and all angles are less than 180 degrees. We can represent a polygon by listing all the vertices, starting at one vertex and following the edges until that vertex is reached again. Thus, element 0 in the array represents the first vertex. The first vertex is connected to the second vertex (element 1), the second vertex is connected to the third vertex (element 2) and so on. The last element represents the last vertex, which is connected to the first vertex.

Given the vertices of a polygon, return its exact area.

Note: Get the integer part of the area. (It can be long). So get your answer in double, and typecast it into long.

Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= T <= 10^5
1 <= N <= 50
1 <= X <= Y <= 10^5
The given polygon is guranted to be convex.
Output Format:
For each test case, print the area of polygon in new line.
Sample Input 1:
1
4
1 5
2 2
9 2
7 5
Sample Output 1:
19
  */
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> x(n), y(n);

        // Input the vertices
        for (int i = 0; i < n; i++)
            cin >> x[i] >> y[i];

        // Calculate the area using the shoelace formula
        double area = 0;
        for (int i = 0; i < n; i++) {
            int j = (i + 1) % n;
            area += (y[i] + y[j]) * (x[j] - x[i]);
        }
        area = abs(area) / 2;

        // Output the area after typecasting to long
        cout << static_cast<long long>(area) << endl;
    }

    return 0;
}

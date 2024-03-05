/*
Problem statement
Calculate the Grundy Number for the given 'n' in the game.

The game starts with a number- ‘n’ and the player to move divides the number- ‘n’ with 2, 3 or 6 and then takes the floor. If the integer becomes 0, it is removed. The last player to move wins. Which player wins the game?

Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= T <= 10^4
1 <= N <= 10^6
Output Format:
Print the Grundy Number(n) for each test case in a new line.
Sample Input 1:
1
10
Sample Output 1:
0
 


*/
#include <bits/stdc++.h>
using namespace std;

int mex(int n1, int n2, int n3) {
    set<int> temp;
    temp.insert(n1);
    temp.insert(n2);
    temp.insert(n3);

    int maximum = max(n1, max(n2, n3));
    for (int i = 0; i <= maximum; i++) {
        if (temp.count(i) == 0) {
            return i;
        }
    }

    return maximum + 1;
}

int grundy(int n, vector<int>& memo) {
    if (n == 0) {
        return 0;
    }

    if (memo[n] != -1) {
        return memo[n];
    }

    int grundy_n = mex(grundy(n / 2, memo), grundy(n / 3, memo), grundy(n / 6, memo));
    memo[n] = grundy_n;
    return grundy_n;
}

int main() {
    int t;
    cin >> t;

    vector<int> memo(1000001, -1); // Initialize memoization array
    while (t--) {
        int n;
        cin >> n;
        cout << grundy(n, memo) << endl;
    }

    return 0;
}

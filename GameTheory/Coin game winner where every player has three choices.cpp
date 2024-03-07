/*
Two players 'X' and 'Y', are playing a coin game. Initially, there are 'N' coins. Each player can pick exactly 'A' coins or 'B' coins or 1 coin. A player loses the game if he is not able to pick any coins. 'X' always starts the game, and each player plays optimally. You are supposed to find which player wins the coin game.

Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= T <= 10
1 <= N <= 10^5

Time limit: 1 sec
Sample Input 1:
2
5 3 4
4 2 3
Sample Output 1:
1
0
Explanation for Sample Input 1:
For the first test case, There are 5 coins, every player can pick 1 or 3 or 4 coins on his/her turn. X picks 3 coins in the first turn, now the remaining coins are 2, Y can only pick 1 coin. So, X wins by picking the last coin.

For the second test case, No, matter what coins X picks, Y always wins.
Sample Input 2:
2
8 2 4
9 3 4
Sample Output 2:
1
0
  */
#include <vector>
using namespace std;

int coinGameWinner(int n, int a, int b) {
    vector<int> dp(n + 1, 0);
    dp[1] = 1; // Base case: If there's only one coin, the current player wins

    for (int i = 2; i <= n; ++i) {
        if (i - 1 >= 0 && !dp[i - 1]) {
            dp[i] = 1; // If the player can make the other player lose by taking 1 coin, mark it as winning position
        }
        if (i - a >= 0 && !dp[i - a]) {
            dp[i] = 1; // If the player can make the other player lose by taking 'a' coins, mark it as winning position
        }
        if (i - b >= 0 && !dp[i - b]) {
            dp[i] = 1; // If the player can make the other player lose by taking 'b' coins, mark it as winning position
        }
    }

    return dp[n]; // Return whether the first player can win with n coins
}

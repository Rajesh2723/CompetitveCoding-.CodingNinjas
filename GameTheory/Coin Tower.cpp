/*
Problem statement
Whis and Beerus are playing a new game today. They form a tower of N coins and make a move in alternate turns. Beerus plays first. In one step, the player can remove either 1, X, or Y coins from the tower. The person to make the last move wins the game. Can you find out who wins the game?

Detailed explanation ( Input/output format, Notes, Images )
Constraints :
1 <= N <= 10 ^ 6
2 <= X <= Y<= 50

Time Limit: 1 sec
Sample Input 1 :
4 2 3
Sample Output 1 :
Whis
Sample Input 2 :
10 2 4
Sample Output 2 :
Beerus
Explanation to Sample Input 1:
Initially, there are 4 coins,  In the first move, Beerus can remove either 1, 2, or 3 coins in all three cases, Whis can win by removing all the remaining coins. 
		return "Beerus";
	}else{
		return "Whis";
	}
}

*/
#include<bits/stdc++.h>
string findWinner(int n, int a, int b)
{
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

    // return dp[n]; // Return whether the first player can win with n coins
	if(dp[n]){
		return "Beerus";
	}else{
		return "Whis";
	}
}

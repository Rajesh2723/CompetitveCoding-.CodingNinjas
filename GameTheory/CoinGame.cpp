/*
Raman is playing a game with his friend Moni. They have a pile containing N coins. Players take alternate turns, removing some coins from the pile. On each turn, a player can remove either one coin or coins equal to some prime power. Game ends when the pile becomes empty. The player who picks the last stone wins.

Your task is to find out who will win the game if Raman plays first.

Detailed explanation ( Input/output format, Notes, Images )
Input Format :
8
Output Format :
Raman
Explanation:
Raman will remove all 8 coins from the pile and win the game. The Raman can remove 8 coins because 8 is a prime power, as 8 = 2^3.
  */
 if (noOfCoins % 6 == 0) {
        cout << "Moni" << endl;
    } else {
        cout << "Raman" << endl;
    }

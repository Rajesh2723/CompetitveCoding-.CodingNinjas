/*
Problem statement
Aahad and Harshit are playing a game. In this game, they have a chocolate of n X m dimensions. In each move, they can cut the chocolate horizontally or vertically. After cutting the chocolate into two pieces, the next player can choose any of the parts. Aahad always starts the game. Both of them are playing the game optimally. The one who cannot make a move will lose the game. You have to tell the name of winner.

Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= t <= 1000
1<= n, m <= 10^9
Time Limit: 1 second
Sample Input:
2
1 2
1 3
Sample Output:
Aahad
Harshit
Explanation:
Example case 1. There is only one possible move, so Harshit even won't have a chance to make move.

Example case 2. There are only two ways Aahad can make the first move, after each of them only one move is left, so Aahad cannot win.
		
 

*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
	cin>>t;
	while(t-->0){
		 int a,b;
		 cin>>a>>b;
		
		
		if((a*b)%2==0)
			cout<<"Aahad"<<endl;
		else
			cout<<"Harshit"<<endl;
		
	}
	return 0;
}

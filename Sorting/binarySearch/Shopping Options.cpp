/*
Shopping Options
Send Feedback
You are given the list of costs of pants in an array “pants”, shirts in an array “shirts”, shoes in an array “shoes”, and skirts in an array “skirts”. You are also given a budget amount ‘X’ to spend. You want to buy exactly 1 item from each list. Your task is to determine the total number of possible combinations that you can buy, given that the total amount of your purchase does not exceed your budget amount.
Input Format:
The first line of input contains an integer ‘T’ denoting the number of test cases to run. Then the test case follows.

The first line of each test case contains five integers ‘P’, ‘Q’, ‘R’, ‘S’ and, ‘X’. Denotes the number of pants, shirts, shoes, skirts, and budget amount respectively.

The second line of each test case contains exactly ‘P’ integers. Denotes the cost of each pant.

The third line of each test case contains exactly ‘Q’ integers. Denotes the cost of each shirt.

The fourth line of each test case contains exactly ‘R’ integers. Denotes the cost of each shoe.

The fifth line of each test case contains exactly ‘S’ integers. Denotes the cost of each skirt.
Output Format :
For each test case, return an integer that represents the total number of combinations to buy that are valid according to the above conditions.

Output for each test case will be printed in a new line. 
Note:
You do not need to print anything; it has already been taken care of. Just implement the given functions.
Constraints:
1 <= T <= 100
1 <= ‘P’, ‘Q’, ‘R’, ‘S’  <= 10
1 <= ‘X’ <= 10^9
1 <= pants[i], shirts[i], shoes[i], skirts[i] <= 10^9

Time Limit: 1 sec
Sample Input 1:
2
2 2 1 1 10
3 4
2 4
2
1
3 2 2 1 15
3 4 6
1 4
2 3
8
Sample Output 1:
3
3
Explanation For Sample Output 1:
In the first case, 
There are a total of four ways to buy. Only valid purchases are [3, 2, 2, 1], [3, 4, 2, 1], [4, 2, 2, 1] because the sum of the cost of each item of each valid purchase is less than the budget amount.

In the second case, 
There are a total of four ways to buy. Only valid purchases are [3, 1, 2, 8], [3, 1, 3, 8], [4, 1, 2, 8] because the sum of the cost of each item of each valid purchase is less than the budget amount.
Sample Input 2 :
2
3 3 3 3 14
3 4 7
1 3 5 
6 8 10
1 2 3
4 3 2 2 20
2 8 7 10
5 5 5
6 3
4 5
Sample Output 2:
12
21
*/
int shoppingOptions(vector<int>& pants, vector<int>& shirts, vector<int>& shoes, vector<int>& skirts, int budget)
{
	int count=0;
    for(int i=0;i<pants.size();i++){
        for(int j=0;j<shirts.size();j++){
            for(int k=0;k<shoes.size();k++){
                for(int l=0;l<skirts.size();l++){
                    if(pants[i]+shirts[j]+shoes[k]+skirts[l]<=budget){
                        count++;
                    }
                }
            }
        }
    }
    return count;
}
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

#include "solution.h"

class Runner {
    int t;

    vector < vector < int > > arrP, arrQ, arrR, arrS;

    vector<int> arrX;

public:
    void takeInput() {

        cin >> t;

        arrX.resize(t);
        arrP.resize(t);
        arrQ.resize(t);
        arrR.resize(t);
        arrS.resize(t);

        for (int c = 0; c < t; c++) {

            int p, q, r, s, x;
            cin >> p >> q >> r >> s >> x;

            arrP[c].resize(p);
            arrQ[c].resize(q);
            arrR[c].resize(r);
            arrS[c].resize(s);

            for (int i = 0; i < p; i++) {
                cin >> arrP[c][i];
            }
            for (int i = 0; i < q; i++) {
                cin >> arrQ[c][i];
            }
            for (int i = 0; i < r; i++) {
                cin >> arrR[c][i];
            }
            for (int i = 0; i < s; i++) {
                cin >> arrS[c][i];
            }

            arrX[c] = x;

        }
    }

    void execute() {

        vector < vector < int > > arrCopyP = arrP, arrCopyQ = arrQ, arrCopyR = arrR, arrCopyS = arrS;

        vector<int> arrCopyX = arrX;

        for (int i = 0; i < t; i++) {

            int ans = shoppingOptions( arrCopyP[i], arrCopyQ[i], arrCopyR[i], arrCopyS[i], arrCopyX[i] );

        }

    }

    void executeAndPrintOutput() {

        for (int i = 0; i < t; i++) {

            int ans = shoppingOptions( arrP[i], arrQ[i], arrR[i], arrS[i], arrX[i] );

            cout << ans;

            cout << "\n";
        }
    }
};

int main() {
    Runner runner;
    runner.takeInput();
    runner.executeAndPrintOutput();

    return 0;
}

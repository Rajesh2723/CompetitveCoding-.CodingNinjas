/*
Two City Scheduling
Send Feedback
Ninja is planning to organize an exhibition in which ‘2N’ peoples are coming. The hall’s capacity in which the exhibition is going to take place is only ‘N’. So, ninja thinks of organizing two exhibitions in 2 different cities, ‘CITY_A’ and ‘CITY_B’, each of capacity ‘N’. All ‘2N’ people will come to the exhibition but in the group of ‘N’ in two different cities. Ninja wants your help in organizing this event.
You are given an array ‘COST’ where “COST[i] = [COST_TO_Ai, COST_TO_Bi]”, in which ‘COST_TO_Ai’ is the cost of the ith person to fly to the city A, and ‘COST_TO_Bi’ is the cost of the ith person to fly to the city B. Your task is to find the minimum cost of organizing the exhibition in which every person flies to a city such that exactly ‘N’ people arrive in each city.
Note:
The intersection of the set of the persons who go to ‘CITY_A’ to those going to ‘CITY_B’ is to be disjoint set, whereas the union must be the ‘2N’.
Input Format:
The first line contains an integer ‘T’, which denotes the number of test cases to be run. Then, the 'T' test cases follow. 

The first line of each test case contains a positive integer, ‘N’,  such that ‘2N’ is the number of people coming to the exhibition.

The next ‘2N’ lines of each test case contain two integers, ‘COST_TO_Ai’, and ‘COST_TO_Bi’, as described in the problem statement.
Note:
The ‘COST’ will be passed to the function as an array of arrays. Each array will contain two integers, ‘COST_TO_Ai’, and ‘COST_TO_Bi’ in that order.
Output Format:
For each test case, return the minimum cost of organizing the exhibition, as described in the problem statement.
Note:
You do not need to print anything. It has already been taken care of. Just implement the given function.
Constraints:
1 <= T <= 10
1 <= N <= 50
COST.length == 2*N
1 <= CostToAi, CostToBi <= 10^4

Time Limit: 1sec
Sample Input 1:
1
2
5 100
50 10
10 200
100 20
Sample Output 1:
45
Explanation for sample input 1:
The first person will go to City ‘A’ at the cost of 5.

The second person will go to City ‘B’ at the cost of 10.

The third person will go to City ‘A’ at the cost of 10.
The last person will go to City ‘B’ at the cost of 20.
So, the total minimum cost will be = 5 + 10 + 10 + 20 = 45. There is no other way to get the cost less than 45.
Sample Input 2:
1
1
200 200
100 200
Sample Output 2:
300
Explanation for sample input 2:
The first person will go to City ‘B’ at the cost of 200.

The second person will go to City ‘A’ at the cost of 100.
So, the total minimum cost will be = 200 + 100 = 300. There is no other way to get the cost less than 300.
*/
int findMinCost(int n, vector<vector<int>> &cost)
{
    // Create a new vector that will contain the difference between the
    // CostToB and the CostToA for each person.
    vector<int> sendAtoB;
    int totalCost = 0;
    // Fill the sendAtoB vector, and send all persons to A.
    for (int i = 0; i < 2 * n; i++)
    {
        sendAtoB.push_back(cost[i][1] - cost[i][0]);
        totalCost += cost[i][0];
    }

    // Sort the vector.
    sort(sendAtoB.begin(), sendAtoB.end());
    // Send first N persons to City B from City A.
    for (int i = 0; i < n; i++)
    {
        totalCost += sendAtoB[i];
    }

    return totalCost;
}
#include <stdio.h>
#include <cstdlib>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <math.h>
#include <utility>
#include <algorithm>

using namespace std;
#include "solution.h"

class Runner
{
    int t;
    vector<vector<vector<int>>>cost;

public:
    void takeInput()
    {
        cin >> t;
        for (int c = 0; c < t; c++)
        {
            int n;
            vector<vector<int>>tmp;
            cin >> n;
            for (int i = 0; i < 2 * n; i++)
            {
                vector<int>z;
                int x, y;
                cin >> x >> y;
                z.push_back(x);
                z.push_back(y);
                tmp.push_back(z);
            }
            cost.push_back(tmp);
        }

    }


    void execute()
    {
        vector<vector<vector<int>>> copy = cost;
        for (int i = 0; i < t; i++)
        {
            int n = copy.size() / 2;
            int result = findMinCost(n, copy[i]);
        }

    }

    void executeAndPrintOutput()
    {
        vector<vector<vector<int>>> copy = cost;
        for (int i = 0; i < t; i++)
        {
            int n = copy[i].size() / 2;
            int result = findMinCost(n, copy[i]);
            cout << result << '\n';
        }

    }

};

int main()
{
    Runner runner;
    runner.takeInput();
    runner.executeAndPrintOutput();

    return 0;
}

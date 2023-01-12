/*
Fractional Knapsack
Send Feedback
You are given weights and values of N items. You have to select and put these selected items in a knapsack of capacity W. Select the items in such a way that selected items give the maximum total value possible with given capacity of the knapsack.
Note: You are allowed to break the items in parts.
Input Format:
The first line of input contains two space separated integers, that denote the value of N and W.
Each of the following N lines contains two space separated integers, that denote value and weight, respectively, of the N items.    
Constraints:
1 <= N = 2*10^5
1 <= W <= 10^9
1 <= value, weight <= 10^5
Time Limit: 1 sec
Output Format:
Print the maximum total value upto six decimal places.
Sample Input 1:
4 22
6 4
6 4
4 4
4 4
Sample Output 1:
20.000000
Explanation:
The total weight of all the items is 16 units, which is less than the total capacity of knapsack, i.e 22 units. Hence, we will add all the items in the knapsack and total value will be 20 units.
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool cmp(pair<int, int> &a, pair<int, int> &b) {
  double f = ((double)a.first) / a.second;
  double s = ((double)b.first) / b.second;

  return f > s; // statement 1
}
void solve() {
  int n, capacity;
  cin >> n >> capacity;
  vector<pair<int, int>> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].first >> a[i].second;
  }

  sort(a.begin(), a.end(), cmp); // statement 2

  int total_weight = 0;
  double profit = 0.0;
  for (int i = 0; i < n; i++) {
    if (total_weight + a[i].second <= capacity) {
      total_weight += a[i].second; // statement 3
      profit += (double)a[i].first;
    } else {
      double remain = capacity - total_weight;
      profit +=
          (double)(a[i].first) * ((double)remain / a[i].second); // statement 4
      break;
    }
  }
  cout << fixed << setprecision(6) << profit;
}

int main() {
  solve();
  return 0;
}

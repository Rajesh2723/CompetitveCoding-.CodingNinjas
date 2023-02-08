/*
Smart Intervals
Send Feedback
You are given an array of intervals, where intervals[i] = [start(i), end(i)] and each start(i) is unique.
The smart interval for an interval ‘i’ is an interval ‘j’ such that start(j) is greater than or equal to end(i) and start(j) should be minimum.
Your task is to return an array of smart interval indices for each interval. If no smart interval exists for an interval ‘i’, then place -1 at index ‘i’ in the output array.
Input Format:
The first line contains a single integer T representing the number of test cases.

The first line of the test case contains an integer ‘N’ denoting the number of intervals.

Each of the following ‘N’ lines contains 2 space-separated integers denoting the start and end of an interval. 
Output Format :
The first and only line of output contains ‘N’ space-separated integers as described above.

The output of every test case is printed in a separate line.
Note :
You do not need to print anything; it has already been taken care of. Just implement the given function.
Constraints:
1 <= T <= 10
1 <= N <= 10^4
1 <= start, end <= 10^4

Time Limit : 1sec
Sample Input 1:
1
3
1 2
2 3
3 4
Sample output 1:
1 2 -1
Explanation of Sample output 1:
Smart interval for the interval [1, 2] is [2, 3] because the start point of [2, 3] is equal to the end point of [1, 2]. The index of [2, 3] is 1.
Smart interval for the interval [2, 3] is [3, 4] because the start point of [3, 4] is equal to the end point of [2, 3]. The index of [3, 4] is 2.
Smart interval for the interval [3, 4] does not exist. Hence, -1.
Therefore, the final answer is [1, 2, -1]. 
Sample Input2:
2
2
3 2
2 3
1 
1 1
Sample Output2:
1 0
0
Explanation of Sample output 2
Test Case 1:
Smart interval for the interval [3, 2] is [2, 3]. The index of [2, 3] is 1.
Smart interval for the interval [2, 3] is [3, 2]. The index of [3, 2] is 2. 
Hence, the answer is [1, 0]. 

Test Case 2: 
Do you really need an explanation? 
*/

#include<bits/stdc++.h>
vector<int> smartInterval(vector<vector<int>> &intervals, int n)
{
	vector<int>ans;
    vector<pair<int,int>>sortedStart(n),sortedEnd(n);
    for(int i=0;i<n;i++){
      sortedStart[i]={intervals[i][0],i};
      sortedEnd[i]={intervals[i][1],i};
    }
    sort(sortedStart.begin(),sortedStart.end());
    sort(sortedEnd.begin(),sortedEnd.end());
    int i=0;
    int j=0;
    vector<int>result(n,-1);
    while(i<n and j<n){
        if(sortedStart[i].first>=sortedEnd[j].first){
            int index=sortedEnd[j].second;
            result[index]=sortedStart[i].second;
            j++;
        }else{
            i++;
        }
    }
    return result;

}
#include <cstdlib>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

#include "solution.h"

class Runner
{
    int t;
    vector<vector<vector<int>>>Arrays;
public:
    void takeInput()
    {
        cin >> t;
        for (int c = 0; c < t; c++)
        {
            int n;
            cin >> n;
        	
        	vector<vector<int> >temp;
            
            while(n)
            {
            	vector<int>A(2);
            	cin>>A[0]>>A[1];
            	
            	temp.push_back(A);
            	n -= 1;
			}
			Arrays.push_back(temp);
        }
    }

    void execute()
    {
        vector<vector<vector<int> > >arrCopy = Arrays;
        for (int i = 0; i < t; i++)
        {
            vector<int> ans = smartInterval(arrCopy[i], arrCopy[i].size());
        }
        Arrays.clear();
    }

    void executeAndPrintOutput()
    {
        for (int i = 0; i < t; i++)
        {
            vector<int> ans = smartInterval(Arrays[i], Arrays[i].size());
            for(int i = 0; i < ans.size(); i++)
            {
            	cout<<ans[i]<<" ";
			}
            cout << "\n";
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



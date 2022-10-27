/*
Time-based Key Value Store
Send Feedback
You are given a stream of tuples which constitute three things ‘Key’, ‘Val’, and the ‘Timestamp’.
Your task is to implement the ‘TimeBased’ class having the two functions:
1) The first function is ‘setKey(string Key, string Val, int Timestamp)’, which stores the ‘Key’ and the ‘Val’ along with the ‘Timestamp’.

2) The second function is ‘getValue(string TargetKey, int TargetTimestamp)’, which returns the value of ‘Val’ associated with the ‘TargetKey’ such that its ‘Timestamp’ value is less than or equal to the ‘TargetTimestamp’. If there are multiple values of ‘Val’, return the value of ‘Val’ with the highest value of ‘Timestamp’ among the valid ones. If there is no valid value of ‘Val’ return “-1” as a string.
‘Timestamps’ will always be in strictly increasing order.
Input format:
The first line of input contains an integer ‘T’, denoting the number of test cases. 

The first line of each test case contains an integer ‘N’, representing the total number of queries.

Then the next ‘N’ lines contain ‘N’ queries. A query can be of two types:
1 Key Val Timestamp  → stores the Key and the Val along with the Timestamp
2 TargetKey TargetTimestamp → returns the value of ‘Val’
Output format:
For each test case, print the value of ‘Val’ for each query of type 2 only, output the answer to the query in a single line.
Note:
You do not need to print anything. It has already been taken care of. Just implement the given functions.
Constraints:
1 <= T <= 10
1 <= N <= 3 * 10^4
1 <= | Val |, | Key | <= 10
1 <= Timestamp <= 10^7

Where ‘T’ represents the number of test cases, ‘N’ represents the number of queries, ‘Val’, ‘Key’ and ‘Timestamp’ are added to the stream.


Time Limit: 1 sec
Sample Input 1:
 2
 4
 1 abc def 10
 1 abc ghi 20
 2 abc 10
 2 abc 5
 3
 1 bbb ccc 5
 1 ddd ccc 5
 2 ddd 6 
Sample Output 1:
 def  -1
 ccc
Explanation For sample Input 1:
For the first test case, 
First, “abc” is added as a key and “def” as a value, and 10 as a timestamp. So at this moment, we have a single data, i.e. {“abc”, “def”, 10}. Then again, “abc” is added as a key along with “ghi” as a value and 20 as the timestamp. Now we have two records, i.e. {“abc”, “ghi”, 20} and {“abc”, “def”, 10}. Now query of type 2 is called, and we have to find the value of ‘Val’ such that its key is “abc” and its timestamp value should be less than or equal to the target timestamp ‘TargetTimestamp’ i.e 10. So the output for this query is “def”. Now again, the query of type 2 is called, and we have to find the value of ‘Val’ such that its key is “abc” and its timestamp value should be less than or equal to the target timestamp ‘TargetTimestamp’ i.e 5. So the output for this query is “-1” as there exists no value of timestamp, which is less than or equal to 5.


For the second test case, 
First, “bbb” is added as a key along with “ccc” as a value and 5 as a timestamp. So at this moment, we have a single data, i.e. {“bbb”, “ccc”, 5}. Then again, the query of type 1 is executed, and “ddd” is added as a key along with “ccc” as value and 5 as a timestamp. Now we have two records, i.e. {“bbb”, “ccc”, 5} and {“ddd”, “ccc”, 5}. Now query of type 2 is called, and we have to find the value of ‘Val’ such that its key is “ddd” and its timestamp value should be less than or equal to target timestamp ‘TargetTimestamp’ i.e 6. So the output for this query is “ccc”. 
*/
/*
    Your Timebased object will be instantiated and called as such:

    Timebased* obj = new Timebased();
    obj->setKey(key,value,timestamp);
    string ans = obj->getValue(targetKey,targetTimestamp);
*/
#include<bits/stdc++.h>
class Timebased {
      unordered_map<string,vector<pair<string,int>>> mp;
    public:
  
        Timebased() {
            //
        }

    void setKey(string key, string val, int timestamp) {
    	mp[key].push_back(make_pair(val,timestamp));   
    }
    string getValue(string targetKey, int targetTimestamp) {
        vector<pair<string,int>>v=mp[targetKey];
        string ans="-1";
        for(int i=v.size()-1;i>=0;i--){
            auto it=v[i];
            string val=it.first;
            int time=it.second;
            if(time<=targetTimestamp){
                ans=val;
                break;
            }
        }
        return ans;
    }
};
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

#include "solution.h"


class Runner {
    int t ;
    vector<vector<vector<string>>> brr;
    vector<vector<vector<string>>> crr;
    vector<vector<vector<int>>> drr;

public:
    void takeInput()
    {
        cin >> t;
        brr.resize(t);
        crr.resize(t);
        drr.resize(t);
        for (int i = 0; i < t; i++)
        {
            int n;
            cin >> n;
            brr[i].resize(n);
            crr[i].resize(n);
            drr[i].resize(n);
            for (int j = 0 ; j < n ; j++) {
                brr[i][j].resize(5);
                crr[i][j].resize(5);
                drr[i][j].resize(5);
                string id;
                cin >> id;
                if (id == "1") {
                    string key , val;
                    int time;
                    cin >> key;
                    cin >> val;
                    cin >> time;
                    brr[i][j][0] = id;
                    brr[i][j][1] = key;
                    crr[i][j][0] = val;
                    drr[i][j][0] = time;
                } else {
                    string key;
                    int time;
                    cin >> key;
                    cin >> time;
                    brr[i][j][0] = id;
                    brr[i][j][1] = key;
                    drr[i][j][0] = time;
                }
            }
        }
    }

    void execute()
    {
        vector<vector<vector<string>>>brrCopy = brr;
        vector<vector<vector<string>>>crrCopy = crr;
        vector<vector<vector<int>>>drrCopy = drr;
        for (int i = 0; i < t; i++)
        {
            Timebased *obj = new Timebased();
            for (int j = 0; j < brrCopy[i].size(); j++)
            {
                if (brrCopy[i][j][0] == "1") {
                    obj->setKey(brrCopy[i][j][1] , crrCopy[i][j][0] , drrCopy[i][j][0]);
                } else {
                    string ans = obj->getValue(brrCopy[i][j][1] , drrCopy[i][j][0]);
                }
            }
            delete obj;
        }
    }

    void executeAndPrintOutput()
    {
        for (int i = 0; i < t; i++)
        {
            Timebased *obj = new Timebased();
            for (int j = 0; j < brr[i].size(); j++)
            {
                if (brr[i][j][0] == "1") {
                    obj->setKey(brr[i][j][1] , crr[i][j][0] , drr[i][j][0]);
                } else {
                    string ans = obj->getValue(brr[i][j][1] , drr[i][j][0]);
                    cout << ans << " ";
                }
            }
            cout << endl;
            delete obj;
        }
    }
};

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    Runner runner;
    runner.takeInput();
    runner.executeAndPrintOutput();

    return 0;
}

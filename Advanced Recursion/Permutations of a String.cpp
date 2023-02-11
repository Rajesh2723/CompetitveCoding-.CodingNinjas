/*
Permutations of a String
Send Feedback
You are given a string 'STR' consisting of lowercase English letters. Your task is to return all permutations of the given string in lexicographically increasing order.
String A is lexicographically less than string B, if either A is a prefix of B (and A ≠ B), or there exists such i (1 <= i <= min(|A|, |B|)), that A[i] < B[i], and for any j (1 <= j < i) A[i] = B[i]. Here |A| denotes the length of the string A.
For example :
If the string is “bca”, then its permutations in lexicographically increasing order are { “abc”, “acb”, “bac”, “bca”, “cab”, “cba” }.
Note:
Given string contains unique characters.
Input Format :
The first line of input contains a single integer 'T', representing the number of test cases or queries to be run. Then the T test cases follow.

The first line and only line of each test case contains a string 'STR' consisting of lowercase English letters.
Output Format :
For every test case, the permutations of the given string are printed in lexicographically increasing order separated by space.

The output of each test case is printed in a separate line.
Note :
You do not need to print anything, it has already been taken care of. Just implement the given function.
Constraints :
1 <= T <= 5
1 <= |STR| <= 9

Where |STR| is the length of the string.

Time Limit: 1 sec
Sample Input 1:
3
abc
bc
c
Sample Output 1:
abc acb bac bca cab cba
bc cb
c
Explanation for Sample Input 1:
In the 1st test case, there are 6 permutations of the given string.
In the 2nd test case, there are 2 permutations of the given string.
In the 3rd test case, there is only 1 permutation of the given string.
Sample Input 2:
1
xyz
Sample Output 2:
xyz xzy yxz yzx zxy zyx 
*/
#include<bits/stdc++.h>
void generatePermutations(string &s,int ind,int n,vector<string>&ans){
   if(ind>=n){
      ans.push_back(s);
      return;
   }
   for(int i=ind;i<n;i++){
      swap(s[i],s[ind]);
      generatePermutations(s,ind+1,n,ans);
      swap(s[i],s[ind]);
   }

}
vector<string> generatePermutations(string &str)
{
   vector<string>ans;
   // vector<string>temp;
   int n=str.size();
   generatePermutations(str,0,n,ans);
   sort(ans.begin(),ans.end());
   return ans;
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
    vector<string> str;

public:
    void takeInput()
    {
        cin >> t;
        for (int c = 0; c < t; c++)
        {
            string temp;
            cin >> temp;
            str.push_back(temp);
        }
    }

    void execute()
    {
        vector<string> strCopy = str;
        for (int i = 0; i < t; i++)
        {
            vector<string> ans = generatePermutations(strCopy[i]);
        }
    }

    void executeAndPrintOutput()
    {
        for (int i = 0; i < t; i++)
        {
            vector<string> ans = generatePermutations(str[i]);
            for (int i = 0; i < ans.size(); i++)
            {
                cout << ans[i] << " ";
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

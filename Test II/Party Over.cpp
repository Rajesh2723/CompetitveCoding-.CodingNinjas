/*
Party Over
Send Feedback
Ninja is coming after a long party to his home, but he faces a monster while returning. Monster puts up a condition to Ninja in order to free him. The monster gives him ‘n’ strings and asks him to sort them. However, he adds an extra condition to him.
Since the monster knows that Ninja could do it easily, the monster wants him to sort them using the last letter of each string. If there are strings with the same last character, sort them based on their second last character and so on.
Ninja gets totally confused, he asks you to solve the problem. Can you help Ninja figure out the correct order of strings?
Input Format:
The first line of input contains an integer ‘T,’ denoting the number of test cases. The test cases follow.

The first line of each test case contains a number ‘n’ denoting the number of strings.

The second line of each test case contains ‘n’ space-separated strings that the monster gave to Ninja.
Output Format:
For each test case, print the strings sorted according to the last character.

Print the output of each test case in a separate line.
Note:
You are not required to print the expected output; it has already been taken care of. Just implement the function.
Constraints:
1 <= T <= 10
1 <= n <= 10^3
1 <= size of string <= 10^2

Where 'T’ is the number of test cases, ‘n’ denotes the number of strings

Time Limit: 1 sec
Sample Input 1:
2
5
abc abd aba xyb cdg
3
jog oop nop
Sample Output 1:
aba xyb abc abd cdg
jog nop oop
Explanation for Sample Input 1:
In the first test case, the given strings are [“abc”,”abd”,”xyb”,”cdg”], the last character of strings are: ‘c’,’d’,’a’,’b’,’g’. So their sorted order is: ‘a’,’b’,’c’,’d’,’g’. Hence the sorted order of strings are:“aba”,”xyb”,”abc”,”abd”,”cdg”.

In the second test case, the given strings are [“jog”,”nop”,”oop”] the last characters of strings are: ‘g’,’p’,’p’.So their sorted order is : ‘g’,’p’,’p’. As we can see for strings “oop” and “nop”, their last character matches; we need to check from the second previous character till we find a mismatched character and sort them accordingly. Hence the sorted order of strings are: “jog”,” nop”,” oop”.
Sample Input 2:
2
4
truck bus car auto
3
teacher student headmaster
Sample Output 2:
truck auto car bus
teacher headmaster student
Explanation for Sample Input 2:
In the first test case, the given strings are [“truck”,”bus”,”car”,”auto”], the last character of strings are: ‘k’,’s’,’r’,’o’.So their sorted order is: ‘k’,’o’,’r’,’s’’. Hence the sorted order of strings are:“truck”,”auto”,”car”,”bus”.

In the second test case, the given strings are [“teacher”,”student”,”headmaster”] the last characters of strings are: ‘r’,’t’,’r’.So their sorted order is : ‘r’,’r’,’t’. As we can see for strings “teacher” and “headmaster”, their last character matches; we need to check from the second previous character till we find a mismatched character and sort them accordingly. Hence the sorted order of strings are: “teacher”,” headmaster”,”student”.
*/
#define fr(i, a, b) for (int i = a; i < b; i++)
#include <bits/stdc++.h>

bool cmp(string s1, string s2)
{
    int n=s1.size(),m=s2.size(),flag=0;
   for(int i=0;i<min(s1.size(),s2.size());i++)
   {
       if(s1[n-i-1]==s2[m-i-1])
           continue;
       else
       {
           flag==1;
           return s1[n-i-1]<s2[m-i-1];
           
       }
   }
    if(flag==0)
    {
        return s1.size()<s2.size();
    }
   
}

vector<string> ninjaParty(vector<string> &arr)
{
    vector<string> v;
    // for (int i = 0; i < arr.size(); i++)
    // {
    //     for (int j = 0; j < arr.size(); j++)
    //     {
    //         if (arr[i].back() < arr[j].back())
    //         {
    //             v.push_back(arr[i]);
    //         }
    //         else if (arr[i].back() == arr[j].back())
    //         {
    //             if (arr[i].back()-1 < arr[j].back()-1)
    //             {
    //                 v.push_back(arr[i]);
    //             }
    //         }
    //     }
    // }
    sort(arr.begin(), arr.end(), cmp);
    fr(i, 0, arr.size()) v.push_back(arr[i]);
   // vector<int>::iterator it;
  
    //it = v.();
    //v.pop_back();
    //v.erase(it);
    return v;
}
#include <cstdlib>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

#include "solution.h"

class Runner
{
    int t;

    vector<vector<string>> arr;
    


public:
    void takeInput()
    {

        cin >> t;
        arr.resize(t);

        for (int tc = 0; tc < t; tc++)
        {
            int n;
            cin >> n;


            arr[tc].resize(n);

            for (int i = 0; i < n; i++)
            {
                cin >> arr[tc][i];
            }
        }
    }

  
    void execute()
    {
        vector<vector<string>> arrCopy = arr;
        // vector<int> kArrCopy = kArr;

        for (int i = 0; i < t; i++)
        {
            vector<string> ans = ninjaParty(arr[i]);

        }
    }


    void executeAndPrintOutput()
    {
        for (int i = 0; i < t; i++)
        {
            vector<string> ans = ninjaParty(arr[i]);
           
            for(string s:ans)
            {
                cout << s << " ";
            }
            cout << endl;
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

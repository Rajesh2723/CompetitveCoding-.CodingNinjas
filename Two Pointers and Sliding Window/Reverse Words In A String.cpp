/*
Reverse Words In A String
Send Feedback
You are given a string of length N. You need to reverse the string word by word. There can be multiple spaces between two words and there can be leading or trailing spaces but in the output reversed string you need to put a single space between two words, and your reversed string should not contain leading or trailing spaces.
For example :
If the given input string is "  Welcome to   Coding  Ninjas", then you should return "Ninjas Coding to Welcome" as the reversed string has only a single space between two words and there is no leading or trailing space.
Input Format :
The first line of input contains a single integer T, representing the number of test cases or queries to be run. 
Then the T test cases follow.

The first and only one of each test case contains a string that you need to reverse word by word.
Output Format :
For every test case, print the reversed string such that there should be only one space between two strings and there should not be any trailing space.
Note :
Do not print anything. It has already been taken care of.

If the string data type is immutable in your language, consider using a mutable data type as an alternative.
Follow-up:
If the string data type is mutable in your language, can you solve it in place with O(1) extra space?
Constraints :
1 <= T <= 50
0 <= N <= 10^5

Time Limit: 1 sec
Sample Input 1 :
2
Welcome   to Coding Ninjas
   I am   a    star
Sample Output 1:
Ninjas Coding to Welcome
star a am I
Explanation For Sample Input 1:
In the first test case, you need to reduce multiple spaces between two words to a single space in the reversed string and observe how the multiple spaces, leading and trailing spaces have been removed.

In the second test case, Your reversed string should not contain leading or trailing spaces.
Sample Input 2 :
1
Hello  World!!
Sample Output 2:
World!! Hello
*/
#include<bits/stdc++.h>
string reverseString(string str)
{
    
    // if the string is " " then return ""
    if(str == "" || str == " ")
    {
        return "";
    }

    string ans;

    int start = str.length() - 1;

    while(start >= 0)
    {
        
        // Skip multiple spaces
        if(str[start] == ' ')
        {
            start--;
        }
        else
        {
            
            // Add space between words
            if(ans.length() > 0)
            {
                ans.push_back(' ');
            }

            int j = start;

            while(j >= 0 && str[j] != ' ')
            {
                j--;
            }

            // add current word to ans
            ans.append(str.substr(j+1, start-j));
            start = j;
        }
    }

    return ans;
}
#include <iostream>
#include <string>
#include <ios>
#include <limits>
using namespace std;
#include "solution.h"

int main()
{
    int t;
    cin >> t;

    cin.ignore(numeric_limits<streamsize>::max(),'\n'); 

    while(t--)
    {
        string str;

        getline(cin, str);
        
        if(str[str.size()-1] == 13)
            str.erase(str.size()-1);

        cout << reverseString(str) << '\n';
    }
}

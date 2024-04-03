/*
Problem statement
You are given a string ‘S’. Your task is to find the length of it’s longest possible chunked palindrome. In other words, you have to split the string ‘S’ into ‘K’ substrings ((Sub)1, (Sub)2, (Sub)3, ..., (Sub)K) such that:

1. The substring ‘(Sub)i’ is a non-empty string, for all 1 <= i <= K.
2. (Sub)1 + (Sub)2 + (Sub)3 + … + (Sub)K = ‘S’, which means the concatenation of all the substrings is equal to ‘S’.
3. (Sub)i = (Sub)(K-i+1), for all 1 <= i <= ‘K’.
You have to find the largest possible value of ‘K’

Note :

1. The string ‘S’ consists of only lowercase English alphabets.
2. A ‘substring’ is a contiguous sequence of characters within a string.
Detailed explanation ( Input/output format, Notes, Images )
Constraints :
1 <= T <= 10
1 <= |S| <= 1000

where 'T' denotes the number of test cases and |S| denotes the size of the string.

Time Limit: 1 sec
Sample Input 1 :
1
abcdefgdefabc
Sample Output 1 :
5
Explanation for sample input 1 :
We can split the string into “(abc)(def)(g)(def)(abc)”.
Sample Input 2 :
1
ninjas
Sample Output 2 :
1
Explanation for sample input 2 :
We can split the string into “(ninjas)”.
*/
#include <iostream>
#include <string>

using namespace std;

int longestChunkedPal(string &s) {
    int count = 0;
    string left = "", right = "";
    for (int i = 0; i < s.length(); i++) {
        left += s[i];
        cout<<"left is:"<<left<<endl;
        right = s[s.length() - i - 1] + right;
        cout<<"right is:"<<right<<endl;
        if (left == right) {
            count++;
            left = "";
            right = "";
        }
    }
    return count;
}

int main() {
    string input;
    cout << "Enter a string: ";
    cin >> input;

    int result = longestChunkedPal(input);

    cout << "The length of the longest possible chunked palindrome is: " << result << endl;

    return 0;
}

/*
You are given a two-dimensional grid having 'N' rows and 'M' columns, consisting of upper case characters. You are also given a word 'WORD'. You have to find the number of occurrences of that word in the grid.

Starting from a given cell, a word can be formed by moving in all eight directions: horizontally left, horizontally right, vertically up, vertically down, and four diagonal directions.

Example :
There are three occurrences of the word 'NINJA' in the following grid:

Note :
1) Given word will not be a single character.

2) If occurrences of the given word start from two different cells, then these two occurrences are considered to be different.

Consider the word 'XYX' to be searched in the string 'AXYXB'. Here, we find an occurrence of 'XYX' at index 2 going in the right direction, and another occurrence at index 4 going in the left direction.

Although these two words correspond to the same word, they will be considered as different occurrences.
Detailed explanation ( Input/output format, Notes, Images )
Constraints :
1 <= N <= 10^3
1 <= M <= 10^3
1 <= N*M <= 10^6
2 <= WORD.size <= 10^3

Time Limit : 1 sec
Sample Input 1 :
5 5
AANIQ
PJINT
NINJA
BLJIJ
PRADN
NINJA
Sample Output 1 :
3
Explanation For Sample Input 1 :

Sample Input 2 :
3 4
RIAN
IAIR
AIRI
AIR
Sample Output 2 :
5
  */
#include <bits/stdc++.h>
using namespace std;

int kmp(string s, string word, vector<int>& lps){
    int n = s.size(), m = word.size();
    int cnt=0;

    int i = 0, j = 0;
    while (i < n) {
        if (j == m) {
            cnt++;
            j = lps[j - 1];
        } else if (s[i] == word[j]) {
            i++;
            j++;
        } else if (j) {
            j = lps[j - 1];
        } else {
            i++;
        }
    }
    if (j == m)
        cnt++;
    
    return cnt;
}
int wordSearch(string g[], int n, int m, string word){
    int len = word.size();
    //compute lps array
    vector<int> lps(len, 0);
    int i=1, j=0;
    while(i<len){
        if(word[i]==word[j]) lps[i++] = ++j;
        else if(j) j = lps[j-1];
        else i++;
    }
    int ans = 0;
    //rows
    for(int i=0; i<n; ++i){
        ans += kmp(g[i], word, lps);
        ans += kmp(string(g[i].rbegin(), g[i].rend()), word, lps);
    }
    //cols
    for(int j=0; j<m; ++j){
        string s;
        for(int i=0; i<n; ++i)
            s.push_back(g[i][j]);
        ans += kmp(s, word, lps);
        ans += kmp(string(s.rbegin(), s.rend()), word, lps);
    }
    //upper diag
    for(int i=0; i<n; ++i){
        string s;
        for(int j=0; i+j<n && j<m; ++j)
            s.push_back(g[i+j][j]);
        ans += kmp(s, word, lps);
        ans += kmp(string(s.rbegin(), s.rend()), word, lps);
    }
    for(int j=1; j<m; ++j){
        string s;
        for(int i=0; i<n && j+i<m; ++i)
            s.push_back(g[i][j+i]);
        ans += kmp(s, word, lps);
        ans += kmp(string(s.rbegin(), s.rend()), word, lps);
    }

    //lower diag
    for(int i=0; i<n; ++i){
        string s;
        for(int j=0; i-j>=0 && j<m; ++j)
            s.push_back(g[i-j][j]);
        ans += kmp(s, word, lps);
        ans += kmp(string(s.rbegin(), s.rend()), word, lps);
    }

    for(int j=1; j<m; ++j){
        string s;
        for(int i=n-1; ~i && j+(n-1)-i<m; --i){
            s.push_back(g[i][j+(n-1)-i]);
        }
        ans += kmp(s, word, lps);
        ans += kmp(string(s.rbegin(), s.rend()), word, lps);
    }

    return ans;
}

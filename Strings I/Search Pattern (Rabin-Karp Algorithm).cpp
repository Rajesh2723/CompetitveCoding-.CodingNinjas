/*
Problem statement
You’re given two strings, 'text' of length 'n' and 'pattern' of length 'm', consisting of lowercase characters.



Find all the occurrences of the string ‘pattern’ in ‘text’.



For each occurrence, print the index from where it starts in the string ‘text’ (1 - indexed).



Example:
Input: ‘text’ = “cxyzghxyzvjkxyz” and ‘pattern’ = “xyz”

Output: 2 7 13

Explanation: The pattern ‘pattern’ = “xyz” appears at 3 positions in ‘text’.
Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1:
cxyzghxyzvjkxyz
xyz


Sample Output 1:
3
2 7 13


Explanation Of Sample Input 1 :
The pattern ‘pattern’ = “xyz” appears at 3 positions in ‘text’.


Sample Input 2 :
ababacabab
aba


Sample Output 2 :
3
1 3 7


Explanation Of Sample Input 2 :
Here we have an overlap between the first occurrence (at position 1) and the second occurrence (at position 3), and we are considering both.


Sample Input 3 :
abcd
xy


Sample Output 3 :
0


Expected time complexity:
The expected time complexity is O(‘n’ + ‘m’).


Constraints:
1 <= ‘n’ <= 10^5
1 <= ‘m’ <= ‘n’

*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int prime = 101; // Prime number for hashing

// Function to calculate hash value for a substring
int calculateHash(string const& str, int len) {
    int hash = 0;
    for (int i = 0; i < len; i++) {
        hash += str[i] * pow(prime, i);
    }
    return hash;
}

// Function to slide the window and update the hash value
int recalculateHash(string const& str, int oldIndex, int newIndex, int oldHash, int patLength) {
    int newHash = oldHash - str[oldIndex];
    newHash /= prime;
    newHash += str[newIndex] * pow(prime, patLength - 1);
    return newHash;
}
vector<int> stringMatch(string text, string pattern) {
	vector<int> occurrences;
    int textLength = text.length();
    int patternLength = pattern.length();
    int patternHash = calculateHash(pattern, patternLength);
    int textHash = calculateHash(text, patternLength);

    for (int i = 0; i <= textLength - patternLength; i++) {
        if (textHash == patternHash) {
            bool match = true;
            for (int j = 0; j < patternLength; j++) {
                if (text[i + j] != pattern[j]) {
                    match = false;
                    break;
                }
            }
            if (match) {
                occurrences.push_back(i + 1); // 1-indexed position
            }
        }
        if (i < textLength - patternLength) {
            textHash = recalculateHash(text, i, i + patternLength, textHash, patternLength);
        }
    }
    return occurrences;
}

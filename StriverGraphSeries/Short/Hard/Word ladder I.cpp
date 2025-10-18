/*
Given are the two distinct words startWord and targetWord, and a list of size N, denoting wordList of unique words of equal size M. Find the length of the shortest transformation sequence from startWord to targetWord.



Keep the following conditions in mind:



A word can only consist of lowercase characters.
Only one letter can be changed in each transformation.
Each transformed word must exist in the wordList including the targetWord.
startWord may or may not be part of the wordList


Note: If there’s no possible way to transform the sequence from startWord to targetWord return 0.


Examples:
Input: wordList = ["des","der","dfr","dgt","dfs"], startWord = "der", targetWord = "dfs"

Output: 3

Explanation: The length of the smallest transformation sequence from "der" to "dfs" is 3 i.e. "der" -> (replace ‘e’ by ‘f’) -> "dfr" -> (replace ‘r’ by ‘s’) -> "dfs". So, it takes 3 different strings for us to reach the targetWord. Each of these strings are present in the wordList.

Input: wordList = ["geek", "gefk"], startWord = "gedk", targetWord= "geek"

Output: 2

Explanation: The length of the smallest transformation sequence from "gedk" to "geek" is 2 i.e. "gedk" -> (replace ‘d’ by ‘e’) -> "geek" .

So, it takes 2 different strings for us to reach the targetWord. Each of these strings are present in the wordList.

Input: wordList = ["hot", "dot", "dog", "lot", "log"], startWord = "hit", targetWord = "cog"

Output:
0
Constraints:
N= Number of Words
M= Length of Word
1 ≤ N ≤ 100
1 ≤ M ≤ 10
  */
class Solution {
public:
    
    /* Function to determine number of steps
    to reach from start ward to target word */
    int wordLadderLength(string startWord, 
                        string targetWord,
                        vector<string> &wordList) {
            
        
        /* Queue data structure to store pair:
         {"word", steps to reach "word"} */
        queue<pair<string, int>> q;

        // Add the starting word to queue
        q.push({startWord, 1});

        // Add all the words to a hashset
        unordered_set<string> st(wordList.begin(), 
                                 wordList.end());
        
        /* If target word is not there in word list,
        return 0 as it is not possible to transform */
        if(st.find(targetWord) == st.end()) return 0;

        /* Erase the starting word 
        from set (if it exists) */
        st.erase(startWord);
        
        // Until the queue is empty
        while (!q.empty()){
            
            // Get the word from queue
            string word = q.front().first;
            
            // Get the steps from queue
            int steps = q.front().second;
            q.pop();

            // Return steps if target word is achieved
            if (word == targetWord)
                return steps;
            
            // Iterate on every character
            for (int i=0; i < word.size(); i++) {
                // Store the original letter 
                char original = word[i];
                
                /* Replacing current character with
                letters from 'a' to 'z' to match 
                any possible word from set */
                
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    word[i] = ch;
                    
                    // Check if it exists in the set
                    if (st.find(word) != st.end()) {
                         
                        // Erase the word from set 
                        st.erase(word);
                        
                        // Add the transition to the queue
                        q.push({word, steps + 1});
                    }
                }
                
                // Update the original letter back
                word[i] = original;
            }
        }
        
        /* If no transformation sequence 
        is found, return 0 */
        return 0;
    }
};

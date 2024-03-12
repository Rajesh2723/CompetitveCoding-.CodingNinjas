/*
Problem statement
You’re given a string S of length N and a string P of length M. Your task is to find the number of occurrences of P in S in linear time.

For example:
If S = "ababa", and P = "ab", then "ab" occurs twice in "ababa".
Note:
The string only consists of lowercase English alphabets.
Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= T <= 100
1 <= N, M <= 10^4

Time Limit: 1 sec
Sample Input 1:
2
5 2
ababa
ab
4 10
codercodes
code
Sample Output 1:
2
2
Explanation of Sample Input 1:
In the 1st testcase,
"ab" occurs two times in "ababa". The first occurrence is from position 1 to position 2 and the second occurrence is from position 4 to position 5.

In the 2nd testcase, 
"code" occurs two times in "codercodes". The first occurrence is from position 1 to position 4 and the second occurrence is from position 6 to position 9.
Sample Input 2:
2
7 3
aababba
aba
6 2
zzzzyz
zz   
Sample Output 2:
1
3
  */
int zAlgorithm(string s, string p, int n, int m)
{
	 ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int count=0;
	for(int i=0;i<n;i++){

        if(s[i]==p[0]){

            if(s.substr(i,m)==p){

                count++;

            }

        }

    }

    return count;
}

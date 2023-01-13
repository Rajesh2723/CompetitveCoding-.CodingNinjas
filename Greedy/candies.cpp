/*
Candies
Send Feedback
Prateek is a kindergarten teacher. He wants to give some candies to the children in his class. All the children stand in a line and each of them has a grade according to his or her performance in the class. Prateek wants to give at least one candy to each child. If two children are standing adjacent to each other, then the one with the higher rating must get more candies than the other. Prateek wants to minimize the total number of candies he must buy.
Given an array 'STUDENTS' of size 'N' that contains the grades for each student, your task is to find what is the minimum number of candies Prateek must buy so that he can distribute them among his students according to the criteria given above.
Example :
Given students' ratings : [5, 8, 1, 5, 9, 4]. 
He gives the students candy in the following minimal amounts : [1, 2, 1, 2, 3, 1]. He must buy a minimum of 10 candies.
Note :
1. If two students having the same grade are standing next to each other, they may receive the same number of candies.
2. Every student must get at least a candy.
Input format :
The first line of input contains an integer 'T' representing the number of the test case. Then the test case follows.

The first line of each test case contains an integer ‘N’ representing the number of students.

The second line of each test case contains 'N' space-separated integers representing the grades of each student.
Output Format :
For each test case, print the minimum number of candies required.
Note :
You don't need to print anything. It has already been taken care of. Just implement the given function.
Constraints :
1 <= T <= 10^2
1 <= N <= 10^4
1 <= STUDENTS[i] <= 10^5

Time Limit : 1 sec
Sample Input 1 :
3
2
1 5
3
1 3 4
3
1 2 2
Sample Output 1 :
3
6
4
Explanation For Sample Input 1 :
(i) Optimal distribution will be 1 2
(ii) Optimal distribution will be 1 2 3
(iii) Optimal distribution will be 1 2 1 because for children with equal grades one child can have less candies
Sample Input 2 :
3
1
100
5
1 5 3 4 6
6
1 9 1 3 2 4
Sample Output 2 :
1
9
9
Explanation For Sample Input 2 :
(i) Optimal distribution will be 1
(ii) Optimal distribution will be 1 2 1 2 3
(iii) Optimal distribution will be 1 2 1 2 1 2
*/
int requiredCandies(vector < int > &students) {
    // Write your code here.
    int sum=0;
    vector<int>res(students.size(),1);
    for(int i=0;i<students.size()-1;i++){
        if(students[i+1]>students[i]){
            res[i+1]=res[i]+1;
        }
    }
    for(int  i=students.size()-2;i>=0;i--){
        if(students[i]>students[i+1]  and res[i] <= res[i+1]){
            res[i]=res[i+1]+1;
        }
        sum+=res[i];
    }
   sum+=res[students.size()-1];
    return sum;
}
#include <iostream>
#include <vector>

using namespace std;
#include "solution.h"

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);

        for (int i = 0; i < n; i++)
        {
           cin >> arr[i];
        }



        cout << requiredCandies(arr) <<endl;
    }
}

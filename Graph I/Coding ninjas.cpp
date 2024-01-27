/*
Problem statement
Given a NxM matrix containing Uppercase English Alphabets only. Your task is to tell if there is a path in the given matrix which makes the sentence “CODINGNINJA” .

There is a path from any cell to all its neighbouring cells. A neighbour may share an edge or a corner.

Detailed explanation ( Input/output format, Notes, Images )
Constraints :
1 <= T <= 10
1 <= N <= 1000
1 <= M <= 1000
Sample Input :
1
2 11
CXDXNXNXNXA
XOXIXGXIXJX
Sample Output :
1
  */
//Hello Rajesh
#include <iostream>
#include <string>
using namespace std;

const int MAXN = 1002;

// Function to check if a cell is within the matrix boundaries
bool isSafe(int i, int j, int N, int M) {
    return (i >= 0 && i < N && j >= 0 && j < M);
}

// Modified function to return a boolean indicating whether a valid path is found
bool solveHelper(char Graph[][MAXN], int N, int M, int i, int j, string S, int **visited) {
    if (S.size() == 0) {
        return true;
    }

    if (!isSafe(i, j, N, M) || visited[i][j] || S[0] != Graph[i][j]) {
        return false;
    }

    visited[i][j] = 1;

    bool result = solveHelper(Graph, N, M, i - 1, j, S.substr(1), visited) ||
                  solveHelper(Graph, N, M, i + 1, j, S.substr(1), visited) ||
                  solveHelper(Graph, N, M, i, j - 1, S.substr(1), visited) ||
                  solveHelper(Graph, N, M, i, j + 1, S.substr(1), visited) ||
                  solveHelper(Graph, N, M, i + 1, j - 1, S.substr(1), visited) ||
                  solveHelper(Graph, N, M, i + 1, j + 1, S.substr(1), visited) ||
                  solveHelper(Graph, N, M, i - 1, j - 1, S.substr(1), visited) ||
                  solveHelper(Graph, N, M, i - 1, j + 1, S.substr(1), visited);

    visited[i][j] = 0;
    return result;
}

// Modified function to return a boolean indicating whether a valid path is found
bool solve(char Graph[][MAXN], int N, int M) {
    string S = "CODINGNINJA";

    int **visited = new int *[N];
    for (int i = 0; i < N; i++) {
        visited[i] = new int[M];
        for (int j = 0; j < M; j++) {
            visited[i][j] = 0;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (Graph[i][j] == 'C' && solveHelper(Graph, N, M, i, j, S, visited)) {
                // Deallocate memory for visited array
                for (int i = 0; i < N; i++) {
                    delete[] visited[i];
                }
                delete[] visited;
                return true;
            }
        }
    }

    // Deallocate memory for visited array
    for (int i = 0; i < N; i++) {
        delete[] visited[i];
    }
    delete[] visited;

    return false;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N, M;
        cin >> N >> M;

        char Graph[MAXN][MAXN];

        for (int i = 0; i < N; i++) {
            cin >> Graph[i];
        }

        cout << solve(Graph, N, M) << endl;
    }

    return 0;
}

/*
Problem statement
You have a 2D grid of ‘N’ rows and ‘M’ columns which are initially filled with water. You are given ‘Q’ queries each consisting of two integers ‘X’ and ‘Y’ and in each query operation, you have to turn the water at position (‘X’, ‘Y’) into a land. You are supposed to find the number of islands in the grid after each query.

An island is a group of lands surrounded by water horizontally, vertically, or diagonally.

Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= T <= 5
1 <= N <= 1000
1 <= M <= 1000
1 <= Q <= 100000
0 <= X < N
0 <= Y < M

Time limit: 1 sec
Sample Input 1:
2
3 3
4
0 0
0 1
1 2
2 1
4 5
4
1 1
0 1
3 3
3 4
Sample Output 1:
1 1 2 3
1 1 2 2
Explanation of Sample Output 1:
In test case 1, 

0.  000
    000
    000

1.  100
    000
    000

2.  110
    000
    000

 3. 110
    001
    000

 4. 110
    001
    100

So, the answer is 1, 1, 2, 3.

In test case 2,

0.  00000
    00000
    00000
    00000

1.  00000
    01000
    00000
    00000

2.  01000
    01000
    00000
    00000

 3. 01000
    01000
    00000
    00010

 4. 01000
    01000
    00000
    00011

So, the answer is 1, 1, 2, 2.
Sample Input 2:
2
2 2
2
0 0
1 1
1 1
1
0 0
Sample Output 2:
1 2
1
Explanation of Sample Output 2:
In test case 1, 

0.  00
    00

1.  10
    00

2.  10
    01

So, the answer is 1, 2.

In test case 2,

0.  0

1.  1

So, the answer is 1.
  */
class DSU {
	private:
		vector<int> parent, size;
	
	public:
		DSU(int n) {
			parent.resize(n+1);
			size.resize(n+1, 1);

			for(int i = 0;i<=n;i++)
				parent[i] = i;
		}

		int getParent(int u) {
			if(parent[u] == u)
				return u;

			return parent[u] = getParent(parent[u]);
		}

		bool unionBySize(int u, int v) {
			int p_u = getParent(u);
			int p_v = getParent(v);

			if(p_u == p_v) return false;
			if(size[p_u] > size[p_v]) {
				parent[p_v] = p_u;
				size[p_u] += size[p_v];
			} else {
				parent[p_u] = p_v;
				size[p_v] += size[p_u];
			}

			return true;
		}
};

bool valid(int x, int y, int n, int m) {
	if(x <0 || y <0 || x >= n || y >= m) return false;

	return true;
}

int getPos(int x, int m, int y) {
	return x * m + y; 
}

vector<int> numOfIslandsII(int n, int m, vector<vector<int>> &q){
	// Write your code here.

	vector<int> ans;
	DSU dsu(n * m + 1);
	int res = 0;
	vector<vector<bool>> vis(n, vector<bool>(m, false));
	vector<int> dir = {-1, 0, 1, 0, -1}; 
	for(auto query: q) {
		int x = query[0], y = query[1];
		int pos = getPos(x, m, y);
		res += 1;

		if(vis[x][y]) {
			ans.push_back(res);
			continue;
		}
		vis[x][y] = true;

		for(int i = 0;i<dir.size() - 1;i++) {
			int new_x = x + dir[i], new_y = y + dir[i+1];
			if(valid(new_x, new_y, n, m) && vis[new_x][new_y]) {
				res -= (dsu.unionBySize(pos, getPos(new_x, m, new_y))) ? 1 : 0;
			}
		}

		ans.push_back(res);
	}

	return ans;
}

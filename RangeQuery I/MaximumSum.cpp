/*
Problem statement
You are given a sequence A[1], A[2], ..., A[N], ( 0 ≤ A[i] ≤ 10^8 , 2 ≤ N ≤ 10^5 ). There are two types of operations and they are defined as follows:

Update:

This will be indicated in the input of a 'U' followed by space and then two integers i and x.

U i x
This operation sets the value of A[i] to x.

Query:

This will be indicated in the input of a 'Q' followed by a single space and then two integers x and y.

Q x y
You must find two integers i and j such that x ≤ i, j ≤ y and i != j, such that the sum A[i]+A[j] is maximized. Print the sum A[i]+A[j].

Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 ≤ i ≤ N
0 ≤ x ≤ 10^8
1 ≤ x < y ≤ N
Output Format:
For each query, print the maximum sum mentioned above, in a new line.
Sample Input 1:
5
1 2 3 4 5
6
Q 2 4
Q 2 5
U 1 6
Q 1 5
U 1 7
Q 1 5
Sample Output 1:
7
9
11
12
*/
#include<bits/stdc++.h>
#define M (beg+end)/2
using namespace std;

const int N = (int)(1e5+5);

int a[N];

pair<int, int> st[4*N];

pair<int, int> combine(pair<int, int> l, pair<int, int> r) {
	if(l.first < r.first) swap(l, r);

	return {l.first, max(l.second, r.first)};
}

void build(int beg, int end, int pos) {
	if(beg == end) {
		st[pos] = {a[beg], -1};
		return;
	}

	build(beg, M, 2*pos+1);
	build(M+1, end, 2*pos+2);
	st[pos] = combine(st[2*pos+1], st[2*pos+2]);
}

void update(int beg, int end, int idx, int val, int pos) {
	if(beg == end) {
		st[pos] = {val, -1};
		return;
	}

	if(idx <= M) update(beg, M, idx, val, 2*pos+1);
	else update(M+1, end, idx, val, 2*pos+2);

	st[pos] = combine(st[2*pos+1], st[2*pos+2]);
}

pair<int, int> query(int beg, int end, int ql, int qr, int pos) {
	if(ql <= beg and qr >= end) {
		return st[pos];
	} else if (ql > end or qr < beg) {
		return {-1, -1};
	}

	return combine(query(beg, M, ql, qr, 2*pos+1), query(M+1, end, ql, qr, 2*pos+2));
}


signed main() {
	freopen("input.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	int n;
	cin>>n;
	for(int i=0; i<n; i++) cin>>a[i];

	build(0, n-1, 0);
	int q;
	cin>>q;
	while(q--) {
		string type;
		cin>>type;
		if(type == "U") {
			int idx, val;
			cin>>idx>>val;
			idx-=1;
			update(0, n-1, idx, val, 0);
		} else {
			int l, r;
			cin>>l>>r;
			l--;
			r--;
			pair<int, int> ans = query(0, n-1, l, r, 0);
			cout<<(ans.first + ans.second) <<"\n";
		}
	}
	return 0;
}

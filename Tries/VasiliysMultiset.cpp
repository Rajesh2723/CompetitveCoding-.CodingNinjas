/*
#include<bits/stdc++.h>
#define int long long

using namespace std;

typedef struct Node {
	Node *left, *right;
	int cnt;

	Node() {
		left = right = NULL;
		cnt = 0;
	}
}Node;

void insert(Node *curr, int x, int i) {
	curr->cnt += 1;
	if(i == -1) return;

	if((x&(1ll<<i)) > 0) {
		if(curr->right == NULL) {
			curr->right = new Node();
		}
		insert(curr->right, x, i-1);
	} else {
		if(curr->left == NULL) {
			curr->left = new Node();
		}
		insert(curr->left, x, i-1);
	}
}

Node *remove(Node *curr, int x, int i) {
	curr->cnt -= 1;
	if(curr->cnt == 0) return NULL;
	if(i == -1) return curr;
	if((x&(1ll<<i)) > 0) {
		curr->right = remove(curr->right, x, i-1);
	} else{
		curr->left = remove(curr->left, x, i-1);
	}
	return curr;
}

int search(Node *curr, int x, int i) {
	if(i == -1) return 0;
	if((x&(1ll<<i)) > 0) {
		if(curr->left != NULL) {
			return ((1ll<<i) + search(curr->left, x, i-1));
		}
		return search(curr->right, x, i-1);
	} else{
		if(curr->right != NULL) {
			return ((1ll<<i) + search(curr->right, x, i-1)); 
		}
		return search(curr->left, x, i-1);
	}
}

signed main() {
	freopen("input.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	Node * root = new Node();
	int M = 31;
	insert(root, 0, M);
	int q;
	cin>>q;
	while(q--) {
		string type;
		int x;
		cin>>type>>x;

		if(type == "+") {
			insert(root, x, M);
		} else if(type == "-") {
			root = remove(root, x, M);
		} else {
			cout<<search(root, x, M)<<"\n";
		}
	}
	return 0;
}
*/

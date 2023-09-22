#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <string>
#include <stack>
#include <deque>
#include <cmath>
#include <tuple>
#include <memory.h>

using namespace std;
int n;
vector<int> adj[30];
int visited[30];

void preorder(int here) { // 전위 순회
	if (here == -1) return;
	if (visited[here] == 0) {
		visited[here] = 1;
		cout << char(here + 'A');
		if (adj[here].size() == 1) preorder(adj[here][0]);
		if (adj[here].size() == 2) {
			preorder(adj[here][0]);
			preorder(adj[here][1]);
		}
	}
}

void inorder(int here) { // 중위 순회
	if (here == -1) return;
	if (visited[here] == 0) {
		if (adj[here].size() == 1) {
			inorder(adj[here][0]);
			visited[here] = 1;
			cout << char(here + 'A');
		}
		else if (adj[here].size() == 2) {
			inorder(adj[here][0]);
			visited[here] = 1;
			cout << char(here + 'A');
			inorder(adj[here][1]);
		}
		else {
			visited[here] = 1;
			cout << char(here + 'A');
		}
	}
}

void postorder(int here) { // 후위 순회
	if (here == -1) return;
	if (visited[here] == 0) {
		if (adj[here].size() == 1) postorder(adj[here][0]);
		if (adj[here].size() == 2) {
			postorder(adj[here][0]);
			postorder(adj[here][1]);
		}
		visited[here] = 1;
		cout << char(here + 'A');
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		char a, b, c;
		cin >> a >> b >> c;
		if (b != '.') {
			adj[a - 'A'].push_back(b - 'A');
		}
		else {
			adj[a - 'A'].push_back(-1);
		}
		if (c != '.') {
			adj[a - 'A'].push_back(c - 'A');
		}
		else {
			adj[a - 'A'].push_back(-1);
		}
	}

	int root = 0;
	preorder(root);
	memset(visited, 0, sizeof(visited));
	cout << "\n";
	inorder(root);
	memset(visited, 0, sizeof(visited));
	cout << "\n";
	postorder(root);

	return 0;
}
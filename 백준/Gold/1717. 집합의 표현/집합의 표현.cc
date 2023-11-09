#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n, m;
int parent[1000005];

int findParent(int a) {
	if (a == parent[a]) {
		return a;
	}
	else {
		return parent[a] = findParent(parent[a]);
	}
}

void unionParent(int a, int b) {
	a = findParent(a);
	b = findParent(b);

	if (a != b) {
		parent[b] = a;
	}
}

bool check(int a, int b) {
	a = findParent(a);
	b = findParent(b);

	if (a == b) {
		return 1;
	}
	else return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < m; i++) {
		int cmd, a, b;
		cin >> cmd >> a >> b;
		if (cmd == 0) {
			unionParent(a, b);
		}
		else if (cmd == 1) {
			if (check(a, b)) {
				cout << "YES\n";
			}
			else {
				cout << "NO\n";
			}
		}
	}
	
	return 0;
}
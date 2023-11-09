#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n, m;
int parent[205];

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

	cin >> n;
	cin >> m;
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int num;
			cin >> num;
			if (num == 1) {
				unionParent(i, j);
			}
		}
	}
	int start = 0;
	for (int i = 0; i < m; i++) {
		int num;
		cin >> num;
		if (i == 0) start = findParent(num);
		else {
			if (findParent(start) != findParent(num)) {
				cout << "NO";
				exit(0);
			}
		}
	}

	cout << "YES";
	
	return 0;
}
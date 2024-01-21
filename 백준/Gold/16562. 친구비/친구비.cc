#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n, m, k;
int parent[10005];
int friends[10005];
int visited[10005];
int res;

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
		// 친구비 적은 곳
		if (friends[a] > friends[b]) swap(a, b);
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

	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
		cin >> friends[i];
	}

	for (int i = 0; i < m; i++) {
		int v, w;
		cin >> v >> w;
		unionParent(v, w);
	}

	for (int i = 1; i <= n; i++) {
		int num = findParent(i);
		// 방문 체크
		if (!visited[num]) {
			visited[num] = 1;
			res += friends[num];
		}
	}

	if (res > k) {
		cout << "Oh no";
	}
	else cout << res;

	return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n, m, k;
int c[30005];
int sz[30005];
int parent[30005];
vector<pii> v;
int dp[30005];

int findParent(int a) {
	if (a == parent[a]) return a;
	else return parent[a] = findParent(parent[a]);
}

void unionParent(int a, int b) {
	a = findParent(a);
	b = findParent(b);
	if (a > b) swap(a, b);
	if (a == b) return;

	parent[b] = a;
	c[a] += c[b];
	sz[a] += sz[b];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m >> k;
	k--;

	for (int i = 1; i <= n; i++) {
		cin >> c[i];

		parent[i] = i;
		sz[i] = 1;
	}

	while (m--) {
		int a, b;
		cin >> a >> b;
		unionParent(a, b);
	}

	//for (int i = 1; i <= n; i++) {
	//	cout << i << " : " << sz[i] << " : " << c[i] << "\n";
	//}

	for (int i = 1; i <= n; i++) {
		if (parent[i] == i) v.push_back({ sz[i], c[i] });
	}

	//for (auto it : v) {
	//	cout << it.first << " : " << it.second << "\n";
	//}

	for (auto it : v) {
		for (int j = k; j >= it.first; j--) {
			dp[j] = max(dp[j], dp[j - it.first] + it.second);
		}
	}

	//for (int i = 1; i <= k; i++) {
	//	cout << dp[i] << " ";
	//}
	//cout << "\n";

	cout << dp[k];

	return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n;
vector<int> adj[55];

int dfs(int now) {
	vector<int> v;

	for (auto next : adj[now]) {
		v.push_back(dfs(next));
	}

	sort(v.begin(), v.end(), greater<>());
	int res = 0;
	for (int i = 0; i < v.size(); i++) {
		res = max(res, v[i] + i + 1);
	}

	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		if (i == 0) continue;
		adj[num].push_back(i);
	}

	cout << dfs(0);

	
	return 0;
}
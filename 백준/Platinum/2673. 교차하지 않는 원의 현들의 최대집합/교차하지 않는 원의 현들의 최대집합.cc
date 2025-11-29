#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int n;
vector<pii> v;
int visited[55];
int ans;

bool check(pii a, pii b) {
	auto [a1, a2] = a;
	auto [b1, b2] = b;

	return ((a1 < b1 && b1 < a2 && a2 < b2) || (b1 < a1 && a1 < b2 && b2 < a2));
}

void dfs(int idx, vector<int> line) {
	if (idx == n) {
		ans = max(ans, (int)line.size());
		return;
	}

	bool flag = true;
	for (auto it : line) {
		if (check(v[idx], v[it])) {
			flag = false;
			break;
		}
	}

	if (flag) {
		line.push_back(idx);
		dfs(idx + 1, line);
		line.pop_back();
	}

	dfs(idx + 1, line);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		if (a > b) swap(a, b);
		v.push_back({ a, b });
	}

	dfs(0, {});
	
	cout << ans << "\n";
	return 0;
}
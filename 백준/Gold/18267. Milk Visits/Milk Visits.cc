#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int n, m;
char milk[100005];
int parent[100005];

int findParent(int a) {
	if (a == parent[a]) return a;
	else return parent[a] = findParent(parent[a]);
}

void unionParent(int a, int b) {
	a = findParent(a);
	b = findParent(b);

	if (a != b) parent[b] = a;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> milk[i];
	}

	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < n - 1; i++) {
		int x, y;
		cin >> x >> y;

		if (milk[x] == milk[y]) {
			unionParent(x, y);
		}
	}

	vector<int> ans;

	for (int i = 1; i <= m; i++) {
		int a, b;
		char c;
		cin >> a >> b >> c;
		if (findParent(a) == findParent(b)) {
			if (milk[a] == c) ans.push_back(1);
			else ans.push_back(0);
		}
		else ans.push_back(1);
	}

	for (auto it : ans) {
		cout << it;
	}
	cout << "\n";

	return 0;
}
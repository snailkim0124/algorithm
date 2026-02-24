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
int deg[505];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		deg[u]++;
		deg[v]++;
	}

	for (int i = 1; i <= n; i++) {
		if (deg[i] == n - 1) {
			cout << n - 1 << "\n";
			exit(0);
		}
	}

	cout << n << "\n";
	
	
	return 0;
}
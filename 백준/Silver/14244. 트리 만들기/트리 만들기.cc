#include <bits/stdc++.h>
#include <limits.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int n, m;
vector<int> adj[55];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	
	int k = n - m + 2;

	for (int i = 0; i < k - 1; i++) {
		cout << i << " " << i + 1 << "\n";
	}

	for (int i = k; i < n; i++) {
		cout << 1 << " " << i << "\n";
	}
	


	return 0;
}
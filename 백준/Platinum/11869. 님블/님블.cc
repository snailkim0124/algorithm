#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int m;
int p[105];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> m;
	int x = 0;
	for (int i = 0; i < m; i++) {
		cin >> p[i];
		x ^= p[i];
	}

	cout << (x ? "koosaga" : "cubelover") << "\n";
	


	return 0;
}
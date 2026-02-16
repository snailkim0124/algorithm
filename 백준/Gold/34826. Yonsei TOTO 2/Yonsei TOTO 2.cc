#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int n, m, s;
vector<pair<double, int>> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m >> s;

	vector<int> a(n), b(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}

	v.resize(n);
	for (int i = 0; i < n; i++) {
		v[i] = { (double)b[i] / a[i] , i };
	}

	sort(all(v), greater<>());

	vector<int> ans(n);
	for (int i = 0; i < n; i++) {
		int tmp = min(s, min(m, a[v[i].second]));
		ans[v[i].second] = tmp;
		s -= tmp;
	}


	for (int i = 0; i < n; i++) {
		cout << ans[i] << " ";
	}
	cout << "\n";
	
	
	return 0;
}
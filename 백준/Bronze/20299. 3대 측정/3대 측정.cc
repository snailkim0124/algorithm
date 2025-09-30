#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int n, k, l;
vector<tii> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> k >> l;
	for (int i = 0; i < n; i++) {
		int x1, x2, x3;
		cin >> x1 >> x2 >> x3;
		if (x1 >= l && x2 >= l && x3 >= l) {
			if (x1 + x2 + x3 >= k) v.push_back({ x1, x2, x3 });
		}
	}

	cout << v.size() << "\n";
	for (auto [x1, x2, x3] : v) {
		cout << x1 << " " << x2 << " " << x3 << " ";
	}
	
	return 0;
}
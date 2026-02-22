#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int a, b, c;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> a >> b >> c;
	int mx = max({ a, b, c });
	int mn = min({ a, b, c });
	int mid = a + b + c - mx - mn;

	if (mx == mn && mn == mid) {
		cout << 2 << "\n";
	}
	else if (mx * mx == mn * mn + mid * mid) {
		cout << 1 << "\n";
	}
	else cout << 0 << "\n";

	return 0;
}
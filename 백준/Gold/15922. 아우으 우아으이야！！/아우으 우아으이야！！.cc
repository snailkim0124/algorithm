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
ll lastx, lasty, ans;
ll x, y;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	cin >> x >> y;
	ans += abs(y - x);
	lastx = x;
	lasty = y;

	for (int i = 1; i < n; i++) {
		cin >> x >> y;
		if (lastx <= x && y <= lasty) continue;
		ans += abs(y - max(x, lasty));
		lasty = y;
	}

	cout << ans;

	return 0;
}
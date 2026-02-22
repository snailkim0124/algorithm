#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int r, w, l;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	for (int T = 1; ; T++) {
		cin >> r;
		if (!r) break;
		cin >> w >> l;

		cout << "Pizza " << T << " ";
		if (w * w + l * l > 4 * r * r) {
			cout << "does not fit on the table.\n";
		}
		else cout << "fits on the table.\n";
	}

	return 0;
}
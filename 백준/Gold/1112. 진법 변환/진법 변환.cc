#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int Mod(int a, int b) {
	return ((a % b) + abs(b)) % abs(b);
}

string ans = "";

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int x, b;
	cin >> x >> b;
	bool neg = false;

	if (x < 0 && b > 0) neg = true;
	if (b > 0) x = abs(x);

	while (1) {
		ans += Mod(x, b) + '0';
		x = (x - Mod(x, b)) / b;

		if (x == 0) break;
	}

	reverse(all(ans));

	if (neg) cout << "-";
	cout << ans << "\n";
	
	return 0;
}
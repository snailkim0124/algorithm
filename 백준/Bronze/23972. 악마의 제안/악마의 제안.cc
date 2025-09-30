#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

ll k, n;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> k >> n;
	if (n == 1) cout << -1 << "\n";
	else if (n * k % (n - 1) == 0) {
		cout << n * k / (n - 1) << "\n";
	}
	else {
		cout << n * k / (n - 1) + 1 << "\n";
	}
	
	return 0;
}
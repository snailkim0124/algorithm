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

int n, k;
string ans, tmp;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> k;
	if ((n / 2) * (n - (n / 2)) < k) {
		cout << -1 << "\n";
		exit(0);
	}

	int cnt = n - (n / 2);
	for (int i = n / 2; i > 0; i--) {
		for (int j = 0; j < k / i; j++) {
			ans += "A";
			cnt--;
		}
		k %= i;
		ans += "B";
	}

	for (int i = 0; i < cnt; i++) {
		ans += "A";
	}


	cout << ans << "\n";


	return 0;
}
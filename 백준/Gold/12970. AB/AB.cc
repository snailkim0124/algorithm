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

	ans = "", tmp = "";
	cin >> n >> k;
	if ((n / 2) * (n - (n / 2)) < k) {
		cout << -1 << "\n";
		exit(0);
	}

	for (int i = 0; i < n - (n / 2); i++) {
		ans += "A";
	}

	for (int i = n - (n / 2); i < n; i++) {
		ans += "B";
	}

	int cnt = (n / 2) * (n - (n / 2));
	cnt -= k;

	// cout << "cnt : " << cnt << "\n";

	int origin = n - (n / 2) - 1;
	int idx = origin;
	int last = n;

	while (cnt--) {
		if (idx + 1 >= last) {
			idx = --origin;
			last--;
		}
		swap(ans[idx], ans[idx + 1]);
		idx++;
		// cout << "ans : " << ans << "\n";
	}

	cout << ans << "\n";


	return 0;
}
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	for (int i = 1; ; i++) {
		int ans = 0;
		int l, p, v;
		cin >> l >> p >> v;
		if (l == 0 && p == 0 && v == 0) break;

		ans = (v / p) * l;
		if (l > (v % p)) {
			ans += v % p;
		}
		else ans += l;

		cout << "Case " << i << ": " << ans << "\n";
	}

	return 0;
}
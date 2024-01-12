#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n;
int ans;
int mx = -1, mn = 987654321;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		mx = max(mx, a);
		mn = min(mn, b);
	}

	ans = mx - mn;
	if (ans < 0) cout << 0;
	else cout << ans;

	return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int k, n, m;
int ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> k >> n >> m;
	ans = k * n - m;

	if (ans < 0) cout << 0;
	else cout << ans;
	return 0;
}
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n;
ll s;
ll arr[25];
ll cnt;

void dfs(ll idx, ll sum) {
	if (idx >= n) return;

	if (sum + arr[idx] == s) cnt++;

	dfs(idx + 1, sum); // 넘어간 경우
	dfs(idx + 1, sum + arr[idx]); // 더한 경우
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	dfs(0, 0);

	cout << cnt;

	return 0;
}
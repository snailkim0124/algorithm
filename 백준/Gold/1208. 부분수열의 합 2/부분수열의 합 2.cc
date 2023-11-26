#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n;
ll s;
ll arr[45];
ll cnt;
map<ll, ll> tmp;

void dfs(ll idx, ll sum) { // 왼쪽
	if (idx >= n / 2) {
		tmp[sum]++;
		return;
	}

	dfs(idx + 1, sum); // 넘어간 경우
	dfs(idx + 1, sum + arr[idx]); // 더한 경우
}

void dfs2(ll idx, ll sum) { // 오른쪽
	if (idx >= n) {
		cnt += tmp[s - sum];
		return;
	}

	dfs2(idx + 1, sum); // 넘어간 경우
	dfs2(idx + 1, sum + arr[idx]); // 더한 경우
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	dfs(0, 0);
	dfs2(n / 2, 0);

	if (s == 0) {
		cout << cnt - 1;
	}
	else
		cout << cnt;

	return 0;
}
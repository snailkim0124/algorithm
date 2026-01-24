#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int n, m;
int arr[1005], dp[1005][1005];

int go(int idx, int sz) {
	if (idx == n) return 0;
	if (dp[idx][sz] != -1) return dp[idx][sz];

	int res = 987654321;

	// 지금 줄
	if (sz + 1 + arr[idx] <= m) {
		res = min(res, go(idx + 1, sz + 1 + arr[idx]));
	}

	// 다음 줄로 스킵
	int tmp = m - sz;
	res = min(res, tmp * tmp + min(res, go(idx + 1, arr[idx])));
	
	return dp[idx][sz] = res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	memset(dp, -1, sizeof(dp));

	cout << go(1, arr[0]) << "\n";
	

	return 0;
}
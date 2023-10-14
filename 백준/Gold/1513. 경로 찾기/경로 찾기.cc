#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n, m, c;
const int mod = 1000007;
int dp[55][55][55][55];
int arr[55][55];

int check(int y, int x, int cnt, int prev) {
	if (y > n || x > m) return 0;
	if (y == n && x == m) {
		if (cnt == 0 && arr[y][x] == 0) return 1; // 오락실이 아닌 경우
		if (cnt == 1 && arr[y][x] > prev) return 1; // 오락실이면서 전보다 크면
		return 0;
	}

	int& res = dp[y][x][cnt][prev];
	if (res != -1) return res;
	res = 0;
	if (!arr[y][x]) { // 오락실 아닌경우
		res = (check(y + 1, x, cnt, prev) % mod + check(y, x + 1, cnt, prev) % mod);
		res %= mod;
	}
	else if (arr[y][x] > prev) { // 오락실인 경우
		res = (check(y + 1, x, cnt - 1, arr[y][x]) % mod + check(y, x + 1, cnt - 1, arr[y][x]) % mod);
		res %= mod;
	}

	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	memset(dp, -1, sizeof(dp));
	cin >> n >> m >> c;
	for (int i = 1; i <= c; i++) {
		int y, x;
		cin >> y >> x;
		arr[y][x] = i;
	}

	for (int i = 0; i <= c; i++) {
		cout << check(1,1,i,0) << " ";
	}

	return 0;
}
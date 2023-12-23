#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n;
int dp[505][505];
const int INF = 987654321;
pair<int, int> v[505];

int go(int x, int y) {
	if (dp[x][y] != INF) { // 값 바뀐 경우
		return dp[x][y];
	}

	if (x == y) { // 같은 경우
		return 0;
	}
	if (x + 1 == y) { // 행렬 계산
		return v[x].first * v[x].second * v[y].second;
	}

	int& res = dp[x][y];

	for (int i = x; i < y; i++) {
		int tmp = v[x].first * v[i].second * v[y].second + go(x, i) + go(i + 1, y);
		res = min(res, tmp);
	}

	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		int r, c;
		cin >> r >> c;
		v[i] = { r,c };
	}


	fill(&dp[0][0], &dp[0][0] + 505 * 505, INF); // 최대로 초기화

	cout << go(1, n);

	return 0;
}
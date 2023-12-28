#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int m;
int dp[20][200005]; // 희소 행렬
int q;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> m;
	for (int i = 1; i <= m; i++) {
		cin >> dp[0][i]; // 한 칸만 가는 경우
	}

	for (int i = 1; i < 20; i++) {
		for (int j = 1; j <= m; j++) {
			int tmp = dp[i - 1][j];
			dp[i][j] = dp[i - 1][tmp];
		}
	}

	cin >> q;
	while (q--) {
		int n, x;
		cin >> n >> x;
		int now = x;
		for (int i = 19; i >= 0; i--) {
			if (n & (1 << i)) { // 2^i 만큼 진행
				now = dp[i][now];
			}
		}

		cout << now << "\n";
	}

	return 0;
}
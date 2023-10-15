#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n;
int arr[2005];
int dp[2005][2005];
int m;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 1 ; i <= n; i++) {
		cin >> arr[i];
	}

	for (int i = 1; i <= n; i++) {
		dp[i][i] = 1; // (1,1) (2,2) ... 자기 자신은 팰린드롬
	}

	for (int i = 1; i <= n; i++) { // (1,2) (2,3) 연속한 수가 같으면 팰린드롬
		if (arr[i] == arr[i + 1]) dp[i][i + 1] = 1;
	}

	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= n - i; j++) { // 처음과 끝이 같다
			if (arr[j] == arr[j + i] && dp[j + 1][j + i - 1]) dp[j][j + i] = 1;
		}
	}

	cin >> m;
	while (m--) {
		int s, e;
		cin >> s >> e;
		cout << dp[s][e] << "\n";
	}



	return 0;
}
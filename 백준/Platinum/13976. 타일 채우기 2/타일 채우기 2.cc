#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll arr[2][2], ans[2][2], tmp[2][2], one[2][2];
ll n;
const int mod = 1000000007;

void matrix_multi(ll a[][2], ll b[][2]) {
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			tmp[i][j] = 0;
			for (int k = 0; k < 2; k++) {
				tmp[i][j] += (a[i][k] * b[k][j]);
			}
			tmp[i][j] %= mod;
		}
	}

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			a[i][j] = (tmp[i][j] + mod) % mod; // 오버플로우 돼도 양수로 만들어줌
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	
	if (n % 2 == 1) { // 홀수일때 0
		cout << 0;
		exit(0);
	}

	n /= 2;
	arr[0][0] = 4;
	arr[0][1] = -1;
	arr[1][0] = 1;
	arr[1][1] = 0;

	for (int i = 0; i < 2; i++) { // 단위행렬 만들기
		ans[i][i] = 1;
	}

	while (n > 0) { // 행렬 곱셈 이용
		if (n % 2 == 1) {
			matrix_multi(ans, arr);
		}
		matrix_multi(arr, arr);
		n /= 2;
	}

	one[0][0] = 1;
	one[1][0] = 1;
	matrix_multi(ans, one);

	cout << ans[0][0];
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll arr[2][2], ans[2][2], tmp[2][2];
ll a, b;
const int mod = 1000000000;

void matrix_multi(ll a[][2], ll b[][2]) {
	memset(tmp, 0, sizeof(tmp));
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
			a[i][j] = tmp[i][j];
		}
	}
}

ll fibo(ll n) {
	memset(arr, 0, sizeof(arr));
	memset(ans, 0, sizeof(ans));

	if (n <= 1) {
		return n;
	}

	for (int i = 0; i < 2; i++) { // 단위행렬 만들기
		ans[i][i] = 1;
	}

	arr[0][0] = 1;
	arr[0][1] = 1;
	arr[1][0] = 1;

	while (n > 0) { // 행렬 곱셈 이용
		if (n % 2 == 1) {
			matrix_multi(ans, arr);
		}
		matrix_multi(arr, arr);
		n /= 2;
	}

	return ans[0][1];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> a >> b;

	cout << (fibo(b + 2) - fibo(a + 1) + mod) % mod; // 음수 처리

	return 0;
}
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll n, b;
ll arr[10][10];
ll ans[10][10];
ll tmp[10][10];
ll mod = 1000;

void matrix_multi(ll a[][10], ll b[][10]) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			tmp[i][j] = 0;
			for (int k = 0; k < n; k++) {
				tmp[i][j] += (a[i][k] * b[k][j]); // 행렬 곱
			}
			tmp[i][j] %= mod; // 모듈러
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			a[i][j] = tmp[i][j];
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> b;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
		ans[i][i] = 1; // 단위행렬
	}

	while (b > 0) {
		if (b % 2 == 1) {
			matrix_multi(ans, arr);
		}
		matrix_multi(arr, arr);
		b /= 2;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << ans[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll d;
const ll mod = 1000000007;
// 지도
ll arr[10][10] = {
	{0,1,1,0,0,0,0,0},
	{1,0,0,1,0,0,0,0},
	{1,0,0,1,1,0,0,0},
	{0,1,1,0,1,1,0,0},
	{0,0,1,1,0,1,1,0},
	{0,0,0,1,1,0,1,1},
	{0,0,0,0,1,1,0,1},
	{0,0,0,0,0,1,1,0}
};
ll ans[10][10];

void matrix_multi(ll a[][10], ll b[][10]) {
	ll tmp[10][10] = { 0 };
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			tmp[i][j] = 0;
			for (int k = 0; k < 8; k++) {
				tmp[i][j] += (a[i][k] * b[k][j]); // 행렬 곱
			}
			tmp[i][j] %= mod; // 모듈러
		}
	}

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			a[i][j] = tmp[i][j];
		}
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> d;

	for (int i = 0; i < 8; i++) {
		ans[i][i] = 1; // 단위행렬
	}

	while (d > 0) {
		if (d % 2 == 1) {
			matrix_multi(ans, arr);
		}
		matrix_multi(arr, arr);
		d /= 2;
	}

	cout << ans[7][7];

	return 0;
}
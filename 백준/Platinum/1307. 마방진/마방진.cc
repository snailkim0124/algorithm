#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n ; i++)
#define rrep(i, r, n) for(int i = r; i < n ; i++)
#define rrrep(i, r, n) for(ll i = r; i < n ; i++)
#define _rrep(i, r, n) for(int i = r; i >= n; i--)
#define _rrrep(i, r, n) for(ll i = r; i >= n; i--)

using namespace std;
typedef long long ll;

void print_arr(int n, int arr[][305]) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
}

void odd_num(int n, int arr[305][305]) {
	int cnt = 1;
	int x1 = n / 2;
	int y1 = 0;
	int x2 = 0, y2 = 0;

	for (int i = 0; i < n * n; i++) {
		arr[y1][x1] = cnt;

		y2 = y1 - 1;
		x2 = x1 + 1;

		if (y2 <= -1) y2 = n - 1;
		if (x2 >= n) x2 = 0;
		if (arr[y2][x2]) {
			y2 = y1 + 1;
			x2 = x1;
		}

		x1 = x2;
		y1 = y2;
		cnt++;
	}
}

void even_num(int n, int arr[305][305]) {

	int sub[305][305] = { 0 };
	int k = n / 2;
	odd_num(k, sub);

	int kk = k / 2;
	//기본 세팅
	rrep(i, k, n) { //C
		rep(j, k) {
			arr[i][j] = 3;
		}
	}
	rep(i, k) { //B
		rrep(j, k, n) {
			if (n - kk < j)
				arr[i][j] = 1;
			else
				arr[i][j] = 2;
		}
	}
	rrep(i, k, n) { //D
		rrep(j, k, n) {
			if (n - kk < j)
				arr[i][j] = 2;
			else
				arr[i][j] = 1;
		}
	}

	rep(i, kk) {
		rep(j, kk) {
			arr[i][j] = 3;
			arr[i + k][j] = 0;
		}
	}

	rrep(j, 1, kk + 1) { //가운데를 바꿈
		arr[kk][j] = 3;
		arr[3 * kk + 1][j] = 0;
	}

	rrep(i, k - kk, k) {
		rep(j, kk) {
			arr[i][j] = 3;
			arr[i + k][j] = 0;
		}
	}

	//세팅된 마방진에 size*size/4를 전부 곱함
	rep(i, n)
		rep(j, n)
		arr[i][j] *= (n * n) / 4;

	//printAll();

	//미리구한 n/2 * n/2 마방진을 각  4분할에 더함
	rep(i, k) {
		rep(j, k) {
			arr[i][j] += sub[i][j]; //A
			arr[i][j + k] += sub[i][j]; //C
			arr[i + k][j + k] += sub[i][j]; //B
			arr[i + k][j] += sub[i][j]; //D
		}
	}
}

void four_num(int n, int arr[305][305]) {
	int cnt = 1;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			arr[i][j] = cnt;
			cnt++;
		}
	}

	for (int i = 0; i < n / 4; i++) {
		int col1 = n / 4;
		int col2 = n - n / 4 - 1;
		for (int j = 0; j < n / 2; j++) {
			swap(arr[i][col1], arr[n - 1 - i][col2]);
			swap(arr[col1][i], arr[col2][n - 1 - i]);
			col1++;
			col2--;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	int arr[305][305] = { 0 };

	cin >> n;
	if (n % 2 == 1) odd_num(n, arr);
	else {
		if (n % 4 == 0) four_num(n, arr);
		else even_num(n, arr);
	}

	print_arr(n, arr);
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n, m;
char arr[10][10];
int res = -1;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);


	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	for (int idx = 0; idx < (1 << (n * m)); idx++) {
		int sum = 0;
		// 가로
		for (int i = 0; i < n; i++) {
			string now = "0";
			for (int j = 0; j < m; j++) {
				int k = i * m + j;
				if (!(idx & (1 << k))) {
					sum += stoi(now);
					now = "0";
				}
				else now += arr[i][j];
			}
			sum += stoi(now); // 나머지 더하기
		}

		// 세로
		for (int j = 0; j < m; j++) {
			string now = "0";
			for (int i = 0; i < n; i++) {
				int k = i * m + j;
				if (idx & (1 << k)) {
					sum += stoi(now);
					now = "0";
				}
				else now += arr[i][j];
			}
			sum += stoi(now);
		}

		res = max(res, sum);
	}

	cout << res;

	return 0;
}
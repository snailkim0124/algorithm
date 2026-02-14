#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int n, m;
char arr[105][105];

// 가로
bool check1(int w) {
	for (int i = 0; i < w; i++) {
		bool flag = true;
		for (int j = 1; j < n; j++) {
			// 경계 체크
			bool flag2 = ((i + j) % w == 0);

			for (int k = 0; k < m; k++) {
				if (flag2) {
					// 색이 달라야함
					if (arr[j - 1][k] == arr[j][k]) {
						flag = false;
						break;
					}
				}
				else {
					if (arr[j - 1][k] != arr[j][k]) {
						flag = false;
						break;
					}
				}

			}
			if (!flag) break;
		}

		if (flag) return true;
	}

	return false;
}

// 세로
bool check2(int w) {
	for (int i = 0; i < w; i++) {
		bool flag = true;
		for (int j = 1; j < m; j++) {
			// 경계 체크
			bool flag2 = ((i + j) % w == 0);

			for (int k = 0; k < n; k++) {
				if (flag2) {
					if (arr[k][j - 1] == arr[k][j]) {
						flag = false;
						break;
					}
				}
				else {
					if (arr[k][j - 1] != arr[k][j]) {
						flag = false;
						break;
					}
				}

			}
			if (!flag) break;
		}

		if (flag) return true;
	}

	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	while (1) {
		cin >> n >> m;
		if (!n && !m) break;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> arr[i][j];
			}
		}

		vector<int> ans;
		for (int w = 1; w <= 200; w++) {
			if (check1(w) && check2(w)) ans.push_back(w);
		}

		if (ans.empty()) {
			cout << -1 << "\n";
		}
		else if (ans.size() == 1) {
			cout << ans[0] << "\n";
		}
		else cout << 0 << "\n";

		memset(arr, 0, sizeof(arr));
	}


	return 0;
}
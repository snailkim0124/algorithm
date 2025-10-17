#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int n;
int arr[25][25];
int res;

void printarr() {
	cout << "======================\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << arr[i][j] << "\t";
		}
		cout << "\n";
	}
	cout << "======================\n";
}

void move(int dir) {
	// 상
	if (dir == 0) {
		for (int j = 0; j < n; j++) {
			// 압축
			vector<int> v;
			for (int i = 0; i < n; i++) {
				if (arr[i][j]) v.push_back(arr[i][j]);
			}

			// 합침
			vector<int> tmp;
			for (int i = 0; i < v.size(); i++) {
				if (i + 1 < v.size() && v[i] == v[i + 1]) {
					tmp.push_back(v[i] + v[i + 1]);
					i++;
				}
				else tmp.push_back(v[i]);
			}
			while (tmp.size() < n) {
				tmp.push_back(0);
			}

			// 압축
			for (int i = 0; i < n; i++) {
				arr[i][j] = tmp[i];
			}
		}
	}
	// 하
	else if (dir == 1) {
		for (int j = 0; j < n; j++) {
			// 압축
			vector<int> v;
			for (int i = n - 1; i >= 0; i--) {
				if (arr[i][j]) v.push_back(arr[i][j]);
			}

			// 합침
			vector<int> tmp;
			for (int i = 0; i < v.size(); i++) {
				if (i + 1 < v.size() && v[i] == v[i + 1]) {
					tmp.push_back(v[i] + v[i + 1]);
					i++;
				}
				else tmp.push_back(v[i]);
			}
			while (tmp.size() < n) {
				tmp.push_back(0);
			}

			// 압축
			for (int i = 0; i < n; i++) {
				arr[n - 1 - i][j] = tmp[i];
			}
		}
	}
	// 좌
	else if (dir == 2) {
		for (int i = 0; i < n; i++) {
			// 압축
			vector<int> v;
			for (int j = 0; j < n; j++) {
				if (arr[i][j]) v.push_back(arr[i][j]);
			}

			// 합침
			vector<int> tmp;
			for (int j = 0; j < v.size(); j++) {
				if (j + 1 < v.size() && v[j] == v[j + 1]) {
					tmp.push_back(v[j] + v[j + 1]);
					j++;
				}
				else tmp.push_back(v[j]);
			}
			while (tmp.size() < n) {
				tmp.push_back(0);
			}

			// 압축
			for (int j = 0; j < n; j++) {
				arr[i][j] = tmp[j];
			}
		}
	}
	// 우
	else if (dir == 3) {
		for (int i = 0; i < n; i++) {
			// 압축
			vector<int> v;
			for (int j = n - 1; j >= 0; j--) {
				if (arr[i][j]) v.push_back(arr[i][j]);
			}

			// 합침
			vector<int> tmp;
			for (int j = 0; j < v.size(); j++) {
				if (j + 1 < v.size() && v[j] == v[j + 1]) {
					tmp.push_back(v[j] + v[j + 1]);
					j++;
				}
				else tmp.push_back(v[j]);
			}
			while (tmp.size() < n) {
				tmp.push_back(0);
			}

			// 압축
			for (int j = 0; j < n; j++) {
				arr[i][n - 1 - j] = tmp[j];
			}
		}
	}
}

int check_score() {
	int mx = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			mx = max(mx, arr[i][j]);
		}
	}

	return mx;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	// 상, 하, 좌, 우 5번씩
	for (int a = 0; a < 4; a++) {
		for (int b = 0; b < 4; b++) {
			for (int c = 0; c < 4; c++) {
				for (int d = 0; d < 4; d++) {
					for (int e = 0; e < 4; e++) {
						int tmp[25][25] = { 0 };
						memcpy(tmp, arr, sizeof(arr)); // 원본 저장
						move(a); move(b); move(c); move(d); move(e); // 이동
						res = max(res, check_score()); // 최대값 찾기
						memcpy(arr, tmp, sizeof(tmp)); // 백트래킹
					}
				}
			}
		}
	}


	cout << res << "\n";

	return 0;
}
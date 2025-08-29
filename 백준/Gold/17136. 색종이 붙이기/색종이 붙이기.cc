#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int arr[15][15];
int paper[10];
int mn = 987654321;

bool check(int y, int x, int val) {
	for (int i = 0; i < val; i++) {
		for (int j = 0; j < val; j++) {
			if (arr[y + i][x + j] == 0) return false;
		}
	}

	return true;
}

void dfs(int y, int x, int cnt) {
	bool flag = false;

	for (int i = y; i < 10; i++) {
		for (int j = (i == y ? x : 0); j < 10; j++) {
			if (arr[i][j] == 1) {
				y = i;
				x = j;
				flag = true;
				break;
			}
		}
		if (flag) break;
	}

	if (!flag) {
		mn = min(mn, cnt);
		return;
	}


	for (int k = 5; k >= 1; k--) {
		if (y + k > 10 || x + k > 10 || paper[k] >= 5) continue;
		if (check(y, x, k)) {
			paper[k]++;

			for (int i = 0; i < k; i++) {
				for (int j = 0; j < k; j++) {
					arr[y + i][x + j] = 0;
				}
			}

			dfs(y, x, cnt + 1);

			paper[k]--;

			for (int i = 0; i < k; i++) {
				for (int j = 0; j < k; j++) {
					arr[y + i][x + j] = 1;
				}
			}
		}
	}

	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cin >> arr[i][j];
		}
	}

	dfs(0, 0, 0);

	if (mn == 987654321) cout << -1 << "\n";
	else cout << mn << "\n";
	
	return 0;
}
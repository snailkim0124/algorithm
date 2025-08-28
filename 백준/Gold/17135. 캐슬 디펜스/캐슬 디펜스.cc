#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int n, m, d;
int arr[20][20];
vector<int> archers;
int enemy_cnt;
int enemy_cnt2;
int ans;

void print_arr() {
	cout << "========================\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "========================\n";
}

int dist(pii a, pii b) {
	return abs(a.first - b.first) + abs(a.second - b.second);
}

int attack_archer() {
	int cnt = 0;

	set<pii> enemy_attacked;

	for (auto archer : archers) {
		int mndist = 987654321;
		pii enemy = { -1, -1 };

		for (int j = 0; j < m; j++) {
			for (int i = n - 1; i >= 0; i--) {
				int DIST = dist({ i, j }, { n, archer });

				if (arr[i][j] == 1 && DIST <= d) {
					if (mndist > DIST) {
						mndist = DIST;
						enemy = { i, j };
					}
				}
			}
		}

		if(enemy.first != -1) enemy_attacked.insert(enemy);
	}

	for (auto e : enemy_attacked) {
		arr[e.first][e.second] = 0;
		cnt++;
		enemy_cnt2--;
	}

	return cnt;
}

void move_enemy() {
	for (int i = n - 2; i >= 0; i--) {
		for (int j = 0; j < m; j++) {
			swap(arr[i][j], arr[i + 1][j]);
		}
	}

	for (int j = 0; j < m; j++) {
		if (arr[0][j] == 1) enemy_cnt2--;
		arr[0][j] = 0;
	}

	return;
}

int castle() {
	int cnt = 0;
	while (1) {
		if (enemy_cnt2 == 0) break;
		cnt += attack_archer();
		move_enemy();
	}

	return cnt;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m >> d;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1) enemy_cnt++;
		}
	}

	// 아처가 위치할 곳
	for (int i = 0; i < m; i++) {
		for (int j = i + 1; j < m; j++) {
			for (int k = j + 1; k < m; k++) {
				int tmp_arr[20][20];
				memcpy(tmp_arr, arr, sizeof(arr));

				enemy_cnt2 = enemy_cnt;

				archers.push_back(i);
				archers.push_back(j);
				archers.push_back(k);
				ans = max(ans, castle());
				archers.pop_back();
				archers.pop_back();
				archers.pop_back();

				memcpy(arr, tmp_arr, sizeof(tmp_arr));
			}
		}
	}
	
	cout << ans << "\n";

	return 0;
}
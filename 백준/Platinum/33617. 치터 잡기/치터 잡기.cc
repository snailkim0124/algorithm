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
vector<pii> ans;

void go() {
	ans.push_back({ 1,1 });

	for (int i = 1; i < n; i++) {
		if (i % 2 == 1) {
			int y = i;
			int corner = n;
			while (corner >= 1) {
				if (corner % 2 == 0) {
					// 아래로
					for (int j = 2; j <= corner; j++) {
						ans.push_back({ y, j });
					}
					y++;
					for (int j = corner; j <= n; j++) {
						ans.push_back({ y, j });
					}
				}
				else {
					// 위로
					for (int j = n - 1; j >= corner; j--) {
						ans.push_back({ y, j });
					}
					y--;
					for (int j = corner; j >= 1; j--) {
						ans.push_back({ y, j });
					}
				}
				corner--;
			}

			// 아래로 내려오기
			y = i;
			for (int j = 1; j <= n; j++) {
				ans.push_back({ y + 1, j });
			}
			
		}
		else {
			int y = i;
			int corner = 1;

			while (corner <= n) {
				if (corner % 2 == 1) {
					// 아래로
					for (int j = n - 1; j >= corner; j--) {
						ans.push_back({ y, j });
					}
					y++;
					for (int j = corner; j >= 1; j--) {
						ans.push_back({ y, j });
					}

				}
				else {
					// 위로
					for (int j = 2; j <= corner; j++) {
						ans.push_back({ y, j });
					}
					y--;
					for (int j = corner; j <= n; j++) {
						ans.push_back({ y, j });
					}
				}
				corner++;
			}

			// 아래로 내려오기
			y = i;
			for (int j = n; j >= 1; j--) {
				ans.push_back({ y + 1, j });
			}
		}

	}

	//cout << ans[0].first << " : " << ans[0].second << "\n";

	//for (int i = 0; i < ans.size(); i++) {
	//	if (i % 4 == 0) cout << "================" << i / 4 << "\n";
	//	cout << ans[i].first << " : " << ans[i].second << "\n";
	//}

}

void go2() {
	ans.push_back({ 1,1 });
	
	for (int i = 1; i < n; i++) {
		if (i % 2 == 1) {
			int y = i;
			int corner = n;
			while (corner >= 1) {
				if (corner % 2 == 1) {
					// 아래로
					for (int j = 2; j <= corner; j++) {
						ans.push_back({ y, j });
					}
					y++;
					for (int j = corner; j <= n; j++) {
						ans.push_back({ y, j });
					}
				}
				else {
					// 위로
					for (int j = n - 1; j >= corner; j--) {
						ans.push_back({ y, j });
					}
					y--;
					for (int j = corner; j >= 1; j--) {
						ans.push_back({ y, j });
					}
				}
				corner--;
			}

		}
		else {
			int y = i;
			int corner = 1;

			while (corner <= n) {
				if (corner % 2 == 1) {
					// 아래로
					for (int j = n - 1; j >= corner; j--) {
						ans.push_back({ y, j });
					}
					y++;
					for (int j = corner; j >= 1; j--) {
						ans.push_back({ y, j });
					}

				}
				else {
					// 위로
					for (int j = 2; j <= corner; j++) {
						ans.push_back({ y, j });
					}
					y--;
					for (int j = corner; j <= n; j++) {
						ans.push_back({ y, j });
					}
				}
				corner++;
			}
		}

	}

	//for (int i = 0; i < ans.size(); i++) {
	//	if (i % 4 == 0) cout << "================" << i / 4 << "\n";
	//	cout << ans[i].first << " : " << ans[i].second << "\n";
	//}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	// 2줄씩 체크
	if (n % 2 == 0) go();
	else go2();

	int total = ans.size() - 1;
	int t = ceil(total / (double)n);

	cout << t << "\n";

	cout << ans[0].first << " " << ans[0].second << "\n";

	int idx = 1;

	for (int i = 0; i < t; i++) {
		int tmp = min(n, total - i * n);
		cout << tmp;

		for (int j = 0; j < tmp; j++) {
			cout << " " << ans[idx].first << " " << ans[idx].second;
			idx++;
		}

		cout << "\n";
	}


	return 0;
}
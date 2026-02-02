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
vector<int> adj[100005];
int visited[100005]; // 정상인
int ans[100005], check[100005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int k;
		cin >> k;
		while (k--) {
			int num;
			cin >> num;
			adj[i].push_back(num);
		}
	}

	for (int i = 1; i <= n; i++) {
		cin >> visited[i];
		ans[i] = visited[i];
	}

	// 역추적
	for (int i = m - 1; i >= 0; i--) {
		vector<int> candi;
		bool normal = false;

		for (auto now : adj[i]) {
			candi.push_back(now);
			if (ans[now] == 0) {
				normal = true;
			}
		}

		if (normal) {
			// 정상인이 있으면 전부 정상인
			for (auto it : candi) {
				ans[it] = 0;
			}
		}
		
	}

	memcpy(check, ans, sizeof(ans));

	// 다시 돌려보기
	for (int i = 0; i < m; i++) {
		vector<int> candi;
		bool infect = false;

		for (auto now : adj[i]) {
			candi.push_back(now);
			if (check[now] == 1) {
				infect = true;
			}
		}

		if (infect) {
			// 감염자 있으면 전부 감염자
			for (auto it : candi) {
				check[it] = 1;
			}
		}
	}

	// 마지막이랑 같은지?
	for (int i = 1; i <= n; i++) {
		if (check[i] != visited[i]) {
			cout << "NO\n";
			exit(0);
		}
	}

	cout << "YES\n";
	for (int i = 1; i <= n; i++) {
		cout << ans[i] << " ";
	}
	cout << "\n";

	return 0;
}
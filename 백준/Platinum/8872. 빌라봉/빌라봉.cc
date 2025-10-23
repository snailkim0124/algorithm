#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int n, m, l;
vector<pii> adj[100005];
int visited[100005], visited2[100005];
int down1[100005], down2[100005]; // 긴 경로, 두번째로 긴 경로
int up[100005];
int mxdia;
vector<int> v, radiv;
const int INF = 987654321;

void dfs1(int now, int prev) {
	visited[now] = 1;
	v.push_back(now);

	down1[now] = 0;
	down2[now] = 0;

	for (auto next : adj[now]) {
		if (next.first != prev) {
			dfs1(next.first, now);

			int newdist = down1[next.first] + next.second;

			if (down1[now] < newdist) {
				down2[now] = down1[now];
				down1[now] = newdist;
			}
			else if (down2[now] < newdist) {
				down2[now] = newdist;
			}
		}
	}
}

void dfs2(int now, int prev) {
	for (auto next : adj[now]) {
		if (next.first != prev) {

			int uptmp = up[now] + next.second;

			int downtmp;
			if (down1[now] == down1[next.first] + next.second) {
				downtmp = down2[now] + next.second;
			}
			else {
				downtmp = down1[now] + next.second;
			}

			up[next.first] = max(uptmp, downtmp);

			dfs2(next.first, now);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m >> l;
	for (int i = 0; i < m; i++) {
		int a, b, t;
		cin >> a >> b >> t;
		adj[a].push_back({ b, t });
		adj[b].push_back({ a, t });
	}
	

	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			v.clear();
			dfs1(i, -1);

			up[i] = 0;
			dfs2(i, -1);

			int radi = INF;
			int dia = 0;

			for (auto it : v) {
				int dist = max(down1[it], up[it]);
				radi = min(radi, dist);
				dia = max(dia, dist);
			}


			radiv.push_back(radi);
			mxdia = max(mxdia, dia);
		}
	}

	sort(all(radiv), greater<>());
	int ans = mxdia;
	// 반지름이 큰 거끼리 연결
	if (radiv.size() >= 2) {
		ans = max(ans, radiv[0] + radiv[1] + l);
	}
	if (radiv.size() >= 3) {
		ans = max(ans, radiv[1] + radiv[2] + 2 * l);
	}

	cout << ans << "\n";

	return 0;
}
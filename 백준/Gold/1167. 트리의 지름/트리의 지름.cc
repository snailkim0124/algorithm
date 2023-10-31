#include <bits/stdc++.h>

using namespace std;
int v;
vector<pair<int, int>> adj[100005];
int mx, mxidx;

void dfs(int cur, int prev, int dist) {
	if (mx < dist) { // 초기화
		mx = dist;
		mxidx = cur;
	}
	for (auto there : adj[cur]) {
		if (there.first != prev) { // 이전에 방문한 곳이 아니라면
			int newdist = dist + there.second;
			dfs(there.first, cur, newdist); 
		}
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> v;
	for (int i = 0; i < v; i++) {
		int a, b, c;
		cin >> a;
		while (1) {
			cin >> b;
			if (b == -1) break;
			cin >> c;
			adj[a].push_back({ b,c });
		}
	}

	dfs(1, 0, 0); // mxidx 구하기
	mx = 0;
	dfs(mxidx, 0, 0); 
	cout << mx;
	
	return 0;
}
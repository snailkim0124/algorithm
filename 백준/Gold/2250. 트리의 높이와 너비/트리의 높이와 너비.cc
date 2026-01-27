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
vector<int> adj[10005];
int parent[10005];
vector<pii> levelc; // 레벨 별 최소 열, 최대 열
int h = 0;
int idx = 1;

// 높이 구하기
void dfs(int now, int level) {
	h = max(h, level);
	if (adj[now][0] != -1) {
		dfs(adj[now][0], level + 1);
	}
	if (adj[now][1] != -1) {
		dfs(adj[now][1], level + 1);
	}
}

void inorder(int now, int level) {
	// 왼쪽
	if (adj[now][0] != -1) {
		inorder(adj[now][0], level + 1);
	}
	// 루트
	levelc[level].first = min(levelc[level].first, idx);
	levelc[level].second = max(levelc[level].second, idx);
	idx++;

	// 오른쪽
	if (adj[now][1] != -1) {
		inorder(adj[now][1], level + 1);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back(b);
		adj[a].push_back(c);
		parent[b]++;
		parent[c]++;
	}

	int root = -1;
	for (int i = 1; i <= n; i++) {
		if (!parent[i]) root = i;
	}

	dfs(root, 1);

	levelc.resize(h + 1);

	// 초기화
	for (int i = 0; i <= h; i++) {
		levelc[i].first = 987654321;
		levelc[i].second = -1;
	}

	inorder(root, 1);

	int mxl = 0;
	int mxw = 0;
	for (int i = 1; i <= h; i++) {
		int w = levelc[i].second - levelc[i].first + 1;
		if (mxw < w) {
			mxw = w;
			mxl = i;
		}
	}

	cout << mxl << " " << mxw << "\n";

	
	
	return 0;
}
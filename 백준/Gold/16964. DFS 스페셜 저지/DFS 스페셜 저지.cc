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
vector<int> adj[100005];
vector<int> v, ans;
int vdepth[100005], visited[100005];
int mx;

void dfs(int now, int depth) {
	vdepth[now] = depth;
	mx = max(mx, depth);
	visited[now] = 1;

	for (auto next : adj[now]) {
		if (!visited[next]) {
			dfs(next, depth + 1);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}

	dfs(1, 0);

	if (v[0] != 1) {
		cout << 0 << "\n";
		exit(0);
	}

	for (int i = 1; i < n; i++) {
		int prev = v[i - 1];
		int now = v[i];
		if (vdepth[now] != 0 && vdepth[now] != vdepth[prev] + 1) {
			for (auto next : adj[prev]) {
				if (vdepth[next] == vdepth[prev] + 1) {
					cout << 0 << "\n";
					exit(0);
				}
			}
		}
	}

	cout << 1 << "\n";
	
	
	return 0;
}

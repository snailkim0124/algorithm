#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int n, x, y;
string s;
stack<int> st;
int arr[4005];
int parent[2005], depth[2005];
pii range[2005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	cin >> s;
	cin >> x >> y;
	x--; y--;

	int idx = 0;
	for (int i = 0; i < 2 * n; i++) {
		int num = s[i] - '0';
		if (num == 0) {
			if (!st.empty()) {
				parent[idx + 1] = st.top();
				depth[idx + 1] = depth[st.top()] + 1;
			}

			st.push(++idx);
			arr[i] = idx;
			range[idx].first = i + 1;
		}
		else if (num == 1) {
			if (!st.empty()) {
				arr[i] = st.top();
				range[st.top()].second = i + 1;
				st.pop();
			}
		}
	}

	int u = arr[x];
	int v = arr[y];

	if (depth[u] < depth[v]) swap(u, v);

	while (depth[u] != depth[v]) {
		u = parent[u];
	}

	while (u != v) {
		u = parent[u];
		v = parent[v];
	}

	cout << range[u].first << " " << range[u].second << "\n";



	return 0;
}
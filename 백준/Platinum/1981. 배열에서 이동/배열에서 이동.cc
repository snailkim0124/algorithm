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
int arr[105][105];
int visited[105][105];
const int dy[4] = { -1,0,1,0 };
const int dx[4] = { 0,1,0,-1 };
set<int> s;

bool bfs(int mn, int mx) {
	if (arr[0][0] < mn || arr[0][0] > mx) return false;

	memset(visited, 0, sizeof(visited));

	queue<pii> q;
	q.push({ 0,0 });
	visited[0][0] = 1;

	while (!q.empty()) {
		auto [y, x] = q.front();
		q.pop();

		if (y == n - 1 && x == n - 1) {
			return true;
		}

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
			if (!visited[ny][nx] && mn <= arr[ny][nx] && arr[ny][nx] <= mx) {
				q.push({ ny, nx });
				visited[ny][nx] = 1;
			}

		}
	}

	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			s.insert(arr[i][j]);
		}
	}

	int left = 0;
	int right = 0;
	int res = INT_MAX;

	vector<int> v(all(s));

	while (left < v.size() && right < v.size()) {
		if (bfs(v[left], v[right])) {
			res = min(res, v[right] - v[left]);
			left++;
		}
		else right++;
	}

	cout << res << "\n";


	
	return 0;
}
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
int visited[25][25];
int cnt;

bool check(int y, int x) {
	if (x == 0 || y == 0) return true;
	if (visited[y][x] && visited[y - 1][x] && visited[y][x - 1] && visited[y - 1][x - 1]) return false;

	return true;
}


void dfs(int pos) {
	if (pos == n * m) {
		cnt++;
		return;
	}

	int y = pos / m;
	int x = pos % m;

	dfs(pos + 1);

	visited[y][x] = 1;
	if (check(y, x)) dfs(pos + 1);
	visited[y][x] = 0;
	
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	dfs(0);
	
	cout << cnt << "\n";

	return 0;
}
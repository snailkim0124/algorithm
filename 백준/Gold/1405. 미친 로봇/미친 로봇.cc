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
int visited[35][35];
const int dy[4] = { 0,0,1,-1 };
const int dx[4] = { 1,-1,0,0 };
double res;
double dir[4];

void go(int depth, int y, int x, double per) {
	if (depth == n) {
		res += per;
		return;
	}

	visited[y][x] = 1;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (visited[ny][nx]) continue;

		visited[ny][nx] = 1;
		go(depth + 1, ny, nx, per * dir[i]);
		visited[ny][nx] = 0;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	for (int i = 0; i < 4; i++) {
		cin >> dir[i];
		dir[i] /= 100.0;
	}

	go(0, 15, 15, 1.0);
	
	cout << fixed;
	cout.precision(9);

	cout << res << "\n";

	return 0;
}
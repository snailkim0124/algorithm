#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int n;
int arr[105][105];
const int dy[4] = { 0,-1,0,1 };
const int dx[4] = { 1,0,-1,0 };
vector<int> v;
int cnt;

void go(int x, int y, int d, int g) {
	int ny = y + dy[d];
	int nx = x + dx[d];
	v.push_back(d);
	arr[nx][ny] = 1;

	while (g--) {
		int sz = v.size();
		for (int i = sz - 1; i >= 0; i--) {
			int nd = (v[i] + 1) % 4;
			ny += dy[nd];
			nx += dx[nd];
			v.push_back(nd);
			arr[nx][ny] = 1;
		}
	}

	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y, d, g;
		cin >> x >> y >> d >> g;

		v.clear();
		arr[x][y] = 1;
		go(x, y, d, g);
	}

	for (int i = 0; i <= 100; i++) {
		for (int j = 0; j <= 100; j++) {
			if (i + 1 > 100 || j + 1 > 100) continue;
			if (arr[i][j] && arr[i + 1][j] && arr[i][j + 1] && arr[i + 1][j + 1]) cnt++;
		}
	}

	cout << cnt;

	return 0;
}
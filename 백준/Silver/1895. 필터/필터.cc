#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int r, c, t;
int arr[45][45];
const int dy[9] = { -1,-1,-1,0,0,0,1,1,1 };
const int dx[9] = { -1,0,1,-1,0,1,-1,0,1 };
int res = 0;

int go(int y, int x) {
	vector<int> v;

	for (int i = 0; i < 9; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		v.push_back(arr[ny][nx]);
	}
	
	sort(all(v));

	// cout << v[v.size() / 2] << "\n";

	return v[v.size() / 2];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> arr[i][j];
		}
	}
	cin >> t;

	for (int i = 1; i < r - 1; i++) {
		for (int j = 1; j < c - 1; j++) {
			if (go(i, j) >= t) res++;
		}
	}

	cout << res << "\n";
	
	return 0;
}
#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

struct Point {
	int x, y;
};

int tt, n;
double res;
vector<Point> v;
int visited[25];
double sumx, sumy;

void go(int idx, int depth, int x, int y) {
	if (depth == n / 2) {
		double tmpx = sumx - x;
		double tmpy = sumy - y;

		double dx = x - tmpx;
		double dy = y - tmpy;

		res = min(res, sqrt(dx * dx + dy * dy));
		return;
	}


	for (int i = idx + 1; i < n; i++) {
		if (!visited[i]) {
			visited[i] = 1;
			go(i, depth + 1, x + v[i].x, y + v[i].y);
			visited[i] = 0;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cout << fixed;
	cout.precision(6);

	cin >> tt;
	while (tt--) {
		cin >> n;
		v.resize(n);
		memset(visited, 0, sizeof(visited));
		sumx = sumy = 0;

		for (int i = 0; i < n; i++) {
			cin >> v[i].x >> v[i].y;
			sumx += v[i].x;
			sumy += v[i].y;
		}

		res = 1e30;

		for (int i = 0; i < n / 2; i++) {
			visited[i] = 1;
			go(i, 1, v[i].x, v[i].y);
			visited[i] = 0;
		}

		cout << res << "\n";

	}
	

	return 0;
}
#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

double H, V, h, v;
int n;

void solve() {

	cin >> n;
	//cout << r << " :" << c << "\n";
	for (int i = 0; i < n; i++) {
		double x, y;
		cin >> x >> y;

		x /= H;
		y /= V;

		bool flag = false;
		while (1) {
			if (x < h && y >= v) {
				break;
			}
			else if (x >= h && y < v) {
				break;
			}
			else if (x < h && y < v) {
				flag = !flag;
				x /= h;
				y /= v;
			}
			else {
				flag = !flag;
				x = (x - h) / (1 - h);
				y = (y - v) / (1 - v);
			}

		}

		if (!flag) cout << "black\n";
		else cout << "white\n";
	}


}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	for (int T = 1; ; T++) {
		cin >> H >> V >> h >> v;
		if (!H && !V && !h && !v) break;


		cout << "Case " << T << ":\n";
		solve();
	}

	return 0;
}

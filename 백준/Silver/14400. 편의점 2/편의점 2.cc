#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

ll n;
vector<int> vx, vy;
ll sumx, sumy;
ll mx, my;
ll dist = 0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		vx.push_back(x);
		vy.push_back(y);
	}

	sort(all(vx));
	sort(all(vy));

	mx = vx[n / 2];
	my = vy[n / 2];

	for (int i = 0; i < n; i++) {
		dist += abs(vx[i] - mx) + abs(vy[i] - my);
	}

	cout << dist << "\n";

	return 0;
}
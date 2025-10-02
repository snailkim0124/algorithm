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
	ll x, y;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cout << fixed;
	cout.precision(9);

	int n;
	cin >> n;
	vector<Point> v(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i].x >> v[i].y;
	}

	double mx = 0; // 가장 큰 삼각형 넓이
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			for (int k = j + 1; k < n; k++) {
				double tarea = (v[i].x * v[j].y + v[j].x * v[k].y + v[k].x * v[i].y);
				tarea -= (v[i].y * v[j].x + v[j].y * v[k].x + v[k].y * v[i].x);
				tarea = abs(tarea) / 2.0;

				mx = max(mx, tarea);
			}
		}
	}

	cout << mx << "\n";

	
	return 0;
}
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
	double x, y;
};

ll n;
Point a, b, c, d;

double dist(Point A, Point B) {
	return sqrt((A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y));
}

double f(double p) {
	Point A, B;
	A.x = a.x + (b.x - a.x) * p;
	A.y = a.y + (b.y - a.y) * p;

	B.x = c.x + (d.x - c.x) * p;
	B.y = c.y + (d.y - c.y) * p;

	return dist(A, B);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y >> d.x >> d.y;

	double left = 0;
	double right = 1;

	// 삼분 탐색 (최솟값 찾기)
	for (int i = 0; i < 100; i++) {
		double p1 = (left * 2 + right) / 3;
		double p2 = (left + right * 2) / 3;

		if (f(p1) <= f(p2)) right = p2;
		else left = p1;
	}

	//cout << left << " : " << right << "\n";

	cout << fixed;
	cout.precision(6);

	cout << f(left) << "\n";

	return 0;
}
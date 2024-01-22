#include <bits/stdc++.h>
#define y1 aaa
using namespace std;
typedef long long ll;

int t = 4;
int x1, y1, p1, q1, x2, y2, p2, q2;
int maxx, minx, maxy, miny;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	while (t--) {
		cin >> x1 >> y1 >> p1 >> q1 >> x2 >> y2 >> p2 >> q2;
		maxx = max(x1, x2);
		minx = min(p1, p2);
		maxy = max(y1, y2);
		miny = min(q1, q2);

		if (maxx < minx && maxy < miny) cout << "a\n";
		else if (maxx == minx && maxy == miny) cout << "c\n";
		else if (maxx > minx || maxy > miny) cout << "d\n";
		else cout << "b\n";
	}
	
	return 0;
}
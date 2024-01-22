#include <bits/stdc++.h>
#define y1 aaa
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int t;

int dist(pii a, pii b) {
	return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> t;
	while (t--) {
		bool check = true;
		vector<pii> v(4);
		int dlist[8] = { 0 };
		cin >> v[0].first >> v[0].second;
		cin >> v[1].first >> v[1].second;
		cin >> v[2].first >> v[2].second;
		cin >> v[3].first >> v[3].second;

		dlist[0] = dist(v[0], v[1]);
		dlist[1] = dist(v[0], v[2]);
		dlist[2] = dist(v[0], v[3]);
		dlist[3] = dist(v[1], v[2]);
		dlist[4] = dist(v[1], v[3]);
		dlist[5] = dist(v[2], v[3]);

		sort(dlist, dlist + 6);

		for (int i = 0; i < 3; i++) {
			if (dlist[i] != dlist[i + 1]) {
				check = false;
			}
		}

		if (dlist[4] != dlist[5]) {
			check = false;
		}

		if (check) cout << 1 << "\n";
		else cout << 0 << "\n";
		
	}
	
	return 0;
}
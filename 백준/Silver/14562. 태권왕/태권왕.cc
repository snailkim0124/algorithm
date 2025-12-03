#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int c;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> c;
	while (c--) {
		int s, t;
		cin >> s >> t;


		queue<tii> q;
		set<pii> ss;

		q.push({ s, t, 0 });
		ss.insert({ s, t });

		while (!q.empty()) {
			auto [s, t, cnt] = q.front();
			q.pop();

			if (s > t) continue;

			if (s == t) {
				cout << cnt << "\n";
				break;
			}

			if (!ss.count({ s * 2, t + 3 })) {
				ss.insert({ s * 2, t + 3 });
				q.push({ s * 2 , t + 3, cnt + 1 });
			}

			if (!ss.count({ s + 1, t })) {
				ss.insert({ s + 1, t });
				q.push({ s + 1, t, cnt + 1 });
			}
		}
	}
	
	
	return 0;
}
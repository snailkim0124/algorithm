#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int n, t, g;
int visited[100000];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> t >> g;
	queue<pii> q;
	q.push({n, 0});
	visited[n] = 1;

	while (!q.empty()) {
		auto [nn, cnt] = q.front();
		q.pop();

		if (nn > 99999 || cnt > t) continue;
		if (nn == g) {
			cout << cnt << "\n";
			exit(0);
		}

		if (nn + 1 <= 99999 && !visited[nn + 1]) {
			visited[nn + 1] = 1;
			q.push({ nn + 1, cnt + 1 });
		}
		
		int nn2 = nn * 2;
		if (nn2 <= 99999) {
			string s_nn = to_string(nn2);
			if (s_nn[0] > '0') {
				s_nn[0] = s_nn[0] - 1;
				int tmp = stoi(s_nn);

				if (tmp <= 99999 && !visited[tmp]) {
					visited[tmp] = 1;
					q.push({ tmp, cnt + 1 });
				}
			}

		}

	}
	
	cout << "ANG";
	
	return 0;
}
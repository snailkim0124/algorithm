#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int prime[10005];

void solve() {
	vector<int> visited(10005, 0);

	string a, b;
	cin >> a >> b;
	
	queue<pii> q;
	q.push({ stoi(a), 0 });
	visited[stoi(a)] = 1;

	while (!q.empty()) {
		auto [now, cnt] = q.front();
		q.pop();

		if (now == stoi(b)) {
			cout << cnt << "\n";
			return;
		}

		string tmp = to_string(now);
		for (int i = 0; i < tmp.size(); i++) {
			if (i == 0) {
				for (int j = 1; j < 10; j++) {
					string s = tmp;
					s[i] = j + '0';
					int ns = stoi(s);

					if (!visited[ns] && prime[ns]) {
						visited[ns] = 1;
						q.push({ ns, cnt + 1 });
					}

				}
			}
			else {
				for (int j = 0; j < 10; j++) {
					string s = tmp;
					s[i] = j + '0';
					int ns = stoi(s);

					if (!visited[ns] && prime[ns]) {
						visited[ns] = 1;
						q.push({ ns, cnt + 1 });
					}
				}
			}

		}
	}

	cout << "Impossible\n";

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	memset(prime, 1, sizeof(prime));
	prime[0] = prime[1] = 0;
	for (int i = 2; i <= 10000; i++) {
		if (prime[i]) {
			for (int j = i + i; j <= 10000; j+= i) {
				prime[j] = 0;
			}
		}
	}

	int tt;
	cin >> tt;
	while (tt--) {
		solve();
	}
	

	return 0;
}
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
string s;
ll mx = 0;
int visited[1505][1505];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	cin >> s;
	
	n *= 3;
	string target = "BLD";

	queue<tll> q;
	q.push({ 0, 0, 0 });
	visited[0][0] = 1;

	while (!q.empty()) {
		auto [l, r, cnt] = q.front();
		q.pop();

		mx = max(mx, cnt);

		char nxt = target[cnt % 3];

		if (l + r < n && s[l] == nxt) {
			if (!visited[l + 1][r]) {
				visited[l + 1][r] = 1;
				q.push({ l + 1, r, cnt + 1 });
			}
		}

		int idx = n - r - 1;
		if (l + r < n && s[idx] == nxt) {
			if (!visited[l][r + 1]) {
				visited[l][r + 1] = 1;
				q.push({ l, r + 1, cnt + 1 });
			}

		}
	}

	cout << mx << "\n";

	
	return 0;
}
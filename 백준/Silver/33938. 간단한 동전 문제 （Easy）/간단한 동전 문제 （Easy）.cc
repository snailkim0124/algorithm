#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int n, m;
vector<int> p;
int visited[20005];

int calc(int num) {
	return num + 10000;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		if (num != 0) p.push_back(num);
	}

	sort(all(p));
	p.erase(unique(all(p)), p.end());

	//for (auto it : p) {
	//	cout << it << " ";
	//}
	//cout << "\n";

	queue<pii> q;
	q.push({ 0, 0 });
	visited[0] = 1;

	while (!q.empty()) {
		auto [now, cnt] = q.front();
		q.pop();

		if (calc(m) == calc(now)) {
			cout << cnt << "\n";
			exit(0);
		}

		for (int i = 0; i < p.size(); i++) {
			if (0 <= calc(now + p[i]) && calc(now + p[i]) <= 20000 && !visited[calc(now + p[i])]) {
				visited[calc(now + p[i])] = 1;
				q.push({ now + p[i], cnt + 1 });
			}
		}
	}

	cout << -1 << "\n";

	return 0;
}
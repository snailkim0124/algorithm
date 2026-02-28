#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

ll n, k;
struct Point {
	ll x, y;
};
vector<Point> v;
int visited[1005];
vector<pair<int, double>> adj[1005];

double fdist(Point A, Point B) {
	return sqrt((A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y));
}

bool check(ll mid) {
	queue<int> q;
	memset(visited, 0, sizeof(visited));
	q.push(0);
	visited[0] = 1;

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		if (now == n + 1) {
			return true;
		}

		if (visited[now] == k + 2) continue;


		for (auto [next, cost] : adj[now]) {
			if (!visited[next] && cost <= mid) {
				q.push(next);
				visited[next] = visited[now] + 1;
			}
		}
	}

	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> k;
	
	v.push_back({ 0, 0 });
	for (int i = 1; i <= n; i++) {
		int x, y;
		cin >> x >> y;
		v.push_back({ x, y });
	}
	v.push_back({ 10000, 10000 });

	
	for (int i = 0; i < v.size(); i++) {
		for (int j = i + 1; j < v.size(); j++) {
			double d = fdist(v[i], v[j]);
			adj[i].push_back({ j, ceil(d / 10.0) });
			adj[j].push_back({ i, ceil(d / 10.0) });
		}
	}

	ll left = 0;
	ll right = ceil(sqrt(2) * 10000 / 10.0);
	ll res = 0;
	while (left <= right) {
		ll mid = (left + right) / 2;

		if (check(mid)) {
			res = mid;
			right = mid - 1;
		}
		else left = mid + 1;
	}


	cout << res << "\n";


	return 0;
}
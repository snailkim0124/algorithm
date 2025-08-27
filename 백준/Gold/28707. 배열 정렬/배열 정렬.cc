#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int n, m;
vector<int> arr;
vector<tii> v;
map<vector<int>, int> dist; // 가중치
priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>, greater<pair<int, vector<int>>>> pq;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		arr.push_back(num);
	}

	cin >> m;
	for (int i = 0; i < m; i++) {
		int l, r, c;
		cin >> l >> r >> c;
		l--; r--;
		v.push_back({ l, r, c });
	}

	pq.push(make_pair(0, arr)); // 가중치, 시작 위치
	dist[arr] = 0;
	while (!pq.empty()) {
		vector<int> here = pq.top().second;
		int here_dist = pq.top().first;
		pq.pop();
		if (dist[here] != here_dist) continue; // 마지막 정점인가

		for (auto [l, r, c] : v) {
			swap(here[l], here[r]);
			if (dist.find(here) == dist.end() || dist[here] > here_dist + c) { // 더 작으면 갱신
				dist[here] = here_dist + c;
				pq.push(make_pair(dist[here], here));
			}
			swap(here[l], here[r]);
		}
	}

	sort(arr.begin(), arr.end());
	if (dist.find(arr) != dist.end()) cout << dist[arr] << "\n";
	else cout << -1 << "\n";

	return 0;
}
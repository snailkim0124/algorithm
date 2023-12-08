#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n;
priority_queue<ll, vector<ll>, greater<ll>> pq;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	vector<pair<ll, ll>> v(n);
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num >> v[i].first >> v[i].second;
	}

	sort(v.begin(), v.end());

	pq.push(v[0].second);

	for (int i = 1; i < n; i++) {
		pq.push(v[i].second);
		if (pq.top() <= v[i].first) {
			pq.pop();
		}
	}

	cout << pq.size();

	return 0;
}
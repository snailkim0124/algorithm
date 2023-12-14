#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n;
priority_queue<int> pq;
int l, p;
int fuel;
int cnt;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	vector<pair<int, int>> v(n + 1);

	for (int i = 0; i < n; i++) {
		cin >> v[i].first >> v[i].second; // 주유소 거리, 연료 양
	}
	cin >> l >> p; // 마을까지 거리, 원래 연료

	v[n].first = l; // 마지막까지 추가

	sort(v.begin(), v.end());

	fuel = p;

	for (int i = 0; i <= n && l > fuel; i++) {
		while (v[i].first > fuel) {
			if (pq.empty()) {
				cout << -1;
				exit(0);
			}
			cnt++;
			fuel += pq.top();
			pq.pop();
		}
		pq.push(v[i].second); // 연료 넣기
	}

	cout << cnt;


	return 0;
}
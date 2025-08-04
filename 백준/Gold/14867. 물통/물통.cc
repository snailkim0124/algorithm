#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


ll a, b, c, d;
set<pll> s;
queue<pair<pll, ll>> q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> a >> b >> c >> d;

	q.push({{ 0, 0 }, 0 });
	s.insert({ 0, 0 });

	while (!q.empty()) {
		pll now = q.front().first;
		ll now_cnt = q.front().second;
		q.pop();

		if (now == make_pair(c, d)) {
			cout << now_cnt << "\n";
			exit(0);
		}

		// a 가득
		if (s.find({ a, now.second }) == s.end()) {
			q.push({ { a, now.second }, now_cnt + 1 });
			s.insert({ a, now.second });
		}
		// b 가득
		if (s.find({ now.first, b }) == s.end()) {
			q.push({ { now.first, b }, now_cnt + 1 });
			s.insert({ now.first, b });
		}
		// a 버리기
		if (s.find({ 0, now.second }) == s.end()) {
			q.push({ { 0, now.second }, now_cnt + 1 });
			s.insert({ 0, now.second });
		}
		// b 버리기
		if (s.find({ now.first, 0 }) == s.end()) {
			q.push({ { now.first, 0 }, now_cnt + 1 });
			s.insert({ now.first, 0 });
		}
		// a -> b로 
		ll water = min(now.first, b - now.second);
		ll tmp_a = now.first - water;
		ll tmp_b = now.second + water;
		if (s.find({ tmp_a, tmp_b }) == s.end()) {
			q.push({ { tmp_a, tmp_b }, now_cnt + 1 });
			s.insert({ tmp_a, tmp_b });
		}

		// b -> a로
		water = min(now.second, a - now.first);
		tmp_a = now.first + water;
		tmp_b = now.second - water;

		if (s.find({ tmp_a, tmp_b }) == s.end()) {
			q.push({ { tmp_a, tmp_b }, now_cnt + 1 });
			s.insert({ tmp_a, tmp_b });
		}
	}

	cout << -1 << "\n";


	return 0;
}
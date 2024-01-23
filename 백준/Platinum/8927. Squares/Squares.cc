#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int t, n;
vector<pll> v;
stack<pll> st;
vector<pll> v2;

pll operator-(pll a, pll b) {
	pll c;
	c.first = a.first - b.first;
	c.second = a.second - b.second;
	return c;
};


ll dist(pll a, pll b) {
	return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

ll ccw(pll p1, pll p2, pll p3) {
	ll s = p1.first * p2.second + p2.first * p3.second + p3.first * p1.second;
	s -= (p1.second * p2.first + p2.second * p3.first + p3.second * p1.first);

	if (s > 0) return 1;
	else if (s == 0) return 0;
	else return -1;
}

bool cmp(pll a, pll b) {
	ll cc = ccw(v[0], a, b);

	// 각도, y, x 작은 순
	if (cc) {
		return cc > 0;
	}
	else if (a.second != b.second) {
		return a.second < b.second;
	}
	else {
		return a.first < b.first;
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		v.clear();
		v2.clear();
		st = stack<pll>();

		cin >> n;
		for (int i = 0; i < n; i++) {
			ll x, y, w;
			cin >> x >> y >> w;
			v.push_back({ x, y });
			v.push_back({ x + w, y });
			v.push_back({ x, y + w });
			v.push_back({ x + w, y + w });
		}

		for (int i = 1; i < v.size(); i++) {
			if (v[i].second < v[0].second || (v[i].second == v[0].second && v[i].first < v[0].first)) {
				swap(v[0].first, v[i].first);
				swap(v[0].second, v[i].second);
			}
		}

		sort(v.begin() + 1, v.end(), cmp);

		st.push(v[0]);
		st.push(v[1]);

		for (int i = 2; i < v.size(); i++) {
			while (st.size() >= 2) {
				pll top2 = st.top();
				st.pop();

				pll top1 = st.top();
				if (ccw(top1, top2, v[i]) > 0) {
					st.push(top2);
					break;
				}
			}
			st.push(v[i]);
		}

		//cout << st.size();
		ll size = st.size();
		//cout << size << "\n";
		v2.resize(size);
		for (int i = 0; i < size; i++) {
			v2[i] = st.top();
			st.pop();
		}
		reverse(v2.begin(), v2.end());

		ll left = 0;
		ll right = 0;
		pll origin;
		origin.first = 0;
		origin.second = 0;

		for (int i = 0; i < size; i++) {
			if (v2[i].first < v2[left].first) left = i;
			if (v2[i].first > v2[right].first) right = i;
		}

		ll DIST = dist(v2[left], v2[right]);

		for (int i = 0; i < size; i++) {
			if (ccw(origin, v2[(left + 1) % size] - v2[left], v2[right] - v2[(right + 1) % size]) > 0) {
				left = (left + 1) % size;
			}
			else right = (right + 1) % size;

			DIST = max(DIST, dist(v2[left], v2[right]));
		}

		cout << DIST << "\n";
	}
	

	return 0;
}
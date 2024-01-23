#include <bits/stdc++.h>
#define PI 3.1415926535
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll n, r;
vector<pll> v;
stack<pll> st;
vector<pll> v2;
double sum;

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

	cout << fixed;
	cout.precision(2);

	cin >> n;
	v.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i].first >> v[i].second;
	}

	for (int i = 1; i < n; i++) {
		if (v[i].second < v[0].second || (v[i].second == v[0].second && v[i].first < v[0].first)) {
			swap(v[0].first, v[i].first);
			swap(v[0].second, v[i].second);
		}
	}

	sort(v.begin() + 1, v.end(), cmp);

	st.push(v[0]);
	st.push(v[1]);

	for (int i = 2; i < n; i++) {
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

	ll size = st.size();
	v2.resize(size);
	for (int i = 0; i < size; i++) {
		v2[i] = st.top();
		st.pop();
	}
	reverse(v2.begin(), v2.end());

	for (int i = 0; i < size; i++) {
		// 각 껍질 길이 더하기
		sum += sqrt(dist(v2[i], v2[(i + 1) % size]));
	}

	cout << sum;

	return 0;
}
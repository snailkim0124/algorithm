#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int k, n;
vector<string> v;

bool cmp(const string& a, const string& b) {
	return a + b > b + a;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> k >> n;
	v.resize(k);
	for (int i = 0; i < k; i++) {
		cin >> v[i];
	}
	
	// 자릿수 많은걸 최대한 써야됨
	int sz = -1;
	string mx = "";
	for (int i = 0; i < k; i++) {
		if (sz < (int)v[i].size()) {
			sz = (int)v[i].size();
			mx = v[i];
		}
		else if (sz == (int)v[i].size()) {
			if (mx < v[i]) {
				mx = v[i];
			}
		}
	}

	// mx 추가
	for (int i = 0; i < n - k; i++) {
		v.push_back(mx);
	}

	sort(all(v), cmp);

	for (auto it : v) {
		cout << it;
	}
	cout << "\n";
	
	return 0;
}
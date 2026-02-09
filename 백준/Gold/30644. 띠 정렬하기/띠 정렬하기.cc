#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int n;
map<int, int> mp;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	vector<int> a(n);
	int idx = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	vector<int> tmp = a;
	sort(all(tmp));

	for (int i = 0; i < n; i++) {
		mp[tmp[i]] = ++idx;
	}

	for (int i = 0; i < n; i++) {
		a[i] = mp[a[i]];
	}

	int cnt = 0;
	for (int i = 0; i < n - 1; i++) {
		if (abs(a[i] - a[i + 1]) > 1) cnt++;
	}

	cout << cnt << "\n";


	//for (auto it : a) {
	//	cout << it << " ";
	//}
	//cout << "\n";



	return 0;
}
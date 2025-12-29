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
map<string, int> mp;

bool cmp(pair<string, int> a, pair<string, int> b) {
	if (a.second != b.second) return a.second > b.second;
	else return a.first < b.first;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		mp.insert({ s, 0 });
	}

	string s;
	while (cin >> s) {
		mp[s]++;
	}

	vector<pair<string, int>> v(all(mp));
	
	sort(all(v), cmp);

	for (auto it : v) {
		cout << it.first << " " << it.second << "\n";
	}
	
	return 0;
}
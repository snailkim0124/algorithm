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
vector<string> v;

bool cmp(const string& a, const string& b) {
	if (a.size() != b.size()) return a.size() < b.size();
	else return a < b;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		v.push_back(s);
	}

	sort(all(v), cmp);
	v.erase(unique(all(v)), v.end());

	for (auto it : v) {
		cout << it << "\n";
	}
	
	return 0;
}
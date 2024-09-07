#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n;
vector<pair<int, string>> v;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		int a;
		cin >> s >> a;
		v.push_back({ a, s });
	}

	sort(v.begin(), v.end());

	cout << v[0].second;

	return 0;
}
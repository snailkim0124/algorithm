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

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	while (n--) {
		string s;
		cin >> s;
		string ext = s.substr(s.find('.') + 1);

		mp[ext]++;
	}

	for (auto it : mp) {
		cout << it.first << " " << it.second << "\n";
	}
	

	return 0;
}
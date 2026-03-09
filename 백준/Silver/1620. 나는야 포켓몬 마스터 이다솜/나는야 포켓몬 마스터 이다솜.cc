#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int n, m;
map<int, string> mp1;
map<string, int> mp2;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		mp1[i] = s;
		mp2[s] = i;
	}

	while (m--) {
		string s;
		cin >> s;

		// 알파벳
		if (isalpha(s[0])) {
			cout << mp2[s] << "\n";
		}
		// 숫자
		else {
			cout << mp1[stoi(s)] << "\n";
		}

	}
	
	
	return 0;
}
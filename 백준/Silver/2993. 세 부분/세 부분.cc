#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

string s;
string ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> s;
	
	ans = s;
	string tmp = s;

	for (int i = 0; i < s.size() - 2; i++) {
		for (int j = i + 1; j < s.size() - 1; j++) {
			s = tmp;
			reverse(s.begin(), s.begin() + i + 1);
			reverse(s.begin() + i + 1, s.begin() + j + 1);
			reverse(s.begin() + j + 1, s.end());
			
			// cout << s << "\n";
			if (ans > s) {
				ans = s;
			}
		}
	}

	cout <<  ans << "\n";

	return 0;
}
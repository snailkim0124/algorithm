#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;



int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	while (1) {
		string s;
		int a, b;
		cin >> s >> a >> b;
		if (s == "#" && !a && !b) break;

		string ans = "";
		if (a > 17 || b >= 80) ans = "Senior";
		else ans = "Junior";

		cout << s << " " << ans << "\n";
	}
	

	return 0;
}
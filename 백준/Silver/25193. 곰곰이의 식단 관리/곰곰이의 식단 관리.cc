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
string s;
int c, o;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	cin >> s;
	
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'C') c++;
		else o++;
	}

	if (c % (o + 1) == 0) cout << c / (o + 1) << "\n";
	else cout << c / (o + 1) + 1 << "\n";

	return 0;
}
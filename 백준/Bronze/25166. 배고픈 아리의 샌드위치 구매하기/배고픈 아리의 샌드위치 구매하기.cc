#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int s, m;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> s >> m;
	if (s < 1024) cout << "No thanks";
	else {
		s -= 1023;
		if ((s & m) == s) cout << "Thanks";
		else cout << "Impossible";
	}


	
	
	return 0;
}
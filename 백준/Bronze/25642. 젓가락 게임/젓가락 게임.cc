#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int a, b;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> a >> b;
	while (1) {
		if (a >= 5 || b >= 5) break;
		b += a;
		if (a >= 5 || b >= 5) break;
		a += b;
	}
	
	if (b >= 5) cout << "yt";
	else cout << "yj";
	
	return 0;
}
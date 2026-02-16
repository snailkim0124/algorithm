#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int x1, x2;
int a, b, c, d, e;
int ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> x1 >> x2;
	cin >> a >> b >> c >> d >> e;

	ans = (a / 3) * ((x2 * x2 * x2) - (x1 * x1 * x1)) + (b - d) / 2 * ((x2 * x2) - (x1 * x1)) + (c - e) * (x2 - x1);
	

	cout << ans << "\n";
	
	return 0;
}
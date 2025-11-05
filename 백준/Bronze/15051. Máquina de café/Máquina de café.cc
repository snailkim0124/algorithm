#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int a, b, c;
int ans = 987654321;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> a >> b >> c;
	ans = min(ans, b * 2 + c * 4);
	ans = min(ans, a * 2 + c * 2);
	ans = min(ans, b * 2 + a * 4);

	cout << ans << "\n";

	return 0;
}
#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

ll m;
map<ll, double> mp[55]; // n, k dp

double go(ll n, ll k) {
	if (n <= 0) return 0; // 패배
	if (k == 0) return 1;
	if (mp[k].count(n)) return mp[k][n];

	ll q = n / m;
	ll r = n % m;

	double tmp1 = (double)r / m * go(n - (q + 1), k - 1);
	double tmp2 = (double)(m - r) / m * go(n - q, k - 1);

	return mp[k][n] = tmp1 + tmp2;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	ll n, k;
	cin >> n >> m >> k;

	cout << fixed;
	cout.precision(3);

	cout << go(n, k) << "\n";

	return 0;
}
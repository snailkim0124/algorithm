#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int n;
double res;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (double i = 1; i < n + 1; i++) {
		res += 1 / i;
	}
	res *= n;

	cout << fixed;
	cout.precision(4);
	
	cout << res;

	return 0;
}
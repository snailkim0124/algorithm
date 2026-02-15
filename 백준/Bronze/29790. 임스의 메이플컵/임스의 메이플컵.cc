#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int n, u, l;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> u >> l;
	if (n >= 1000 && (u >= 8000 || l >= 260)) cout << "Very Good\n";
	else if (n >= 1000) cout << "Good\n";
	else cout << "Bad\n";
	


	return 0;
}
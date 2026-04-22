#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int n, a, b;
int suma = 1, sumb = 1;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> a >> b;
	for (int i = 1; i <= n; i++) {
		suma += a;
		sumb += b;

		if (suma < sumb) swap(suma, sumb);
		else if (suma == sumb) sumb--;
	}

	cout << suma << " " << sumb << "\n";
	
	return 0;
}
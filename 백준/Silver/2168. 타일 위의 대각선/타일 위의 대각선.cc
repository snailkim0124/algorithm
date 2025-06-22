#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int x, y;

int gcd(int a, int b) {
	if (b == 0) return a;
	else {
		return gcd(b, a % b);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> x >> y;
	if (x < y) swap(x, y);

	cout << x + y - gcd(x, y);
	
	return 0;
}

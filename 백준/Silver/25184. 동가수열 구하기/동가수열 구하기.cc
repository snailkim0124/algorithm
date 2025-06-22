#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll n;
vector<ll> v;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = n / 2; i >= 1; i--) {
		cout << i << " " << i + n / 2 << " ";
	}
	if (n % 2 == 1) cout << n;

	return 0;
}

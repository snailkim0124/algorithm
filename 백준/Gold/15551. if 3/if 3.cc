#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n - 2; i++) cout << "@";
	cout << "Ab\n";

	for (int i = 0; i < n - 2; i++) cout << "@";
	cout << "BC\n";

	return 0;
}

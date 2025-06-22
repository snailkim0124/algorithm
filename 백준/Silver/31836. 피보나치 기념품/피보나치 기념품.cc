#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n;
vector<int> a, b;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	while (1) {
		if (n == 2) {
			a.push_back(2);
			b.push_back(1);
		}
		if (n < 3) break;
		a.push_back(n);
		b.push_back(n - 1);
		b.push_back(n - 2);
		n -= 3;
	}

	cout << a.size() << "\n";
	for (auto it : a) {
		cout << it << " ";
	}
	cout << "\n";

	cout << b.size() << "\n";
	for (auto it : b) {
		cout << it << " ";
	}
	
	return 0;
}

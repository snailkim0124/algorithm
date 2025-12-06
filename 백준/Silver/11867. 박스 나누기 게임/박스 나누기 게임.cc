#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int n, m;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	if (n % 2 == 0 && m % 2 == 0) {
		cout << "A" << "\n";
	}
	else if (n % 2 == 1 && m % 2 == 1) {
		cout << "B" << "\n";
	}
	else {
		cout << "A" << "\n";
	}
	
	
	return 0;
}
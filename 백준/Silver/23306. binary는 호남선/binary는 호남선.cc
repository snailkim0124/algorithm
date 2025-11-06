#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int n;
int a, b;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	cout << "? 1" << endl;
	cin >> a;
	cout << "? " << n << endl;
	cin >> b;

	cout << "! ";
	if (a == 0 && b == 1) cout << 1 << endl;
	else if (a == b) cout << 0 << endl;
	else cout << -1 << endl;


	return 0;
}
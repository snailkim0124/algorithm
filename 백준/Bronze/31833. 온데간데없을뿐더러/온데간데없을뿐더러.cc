#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n;
string a, b;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		string num;
		cin >> num;
		a += num;
	}

	for (int i = 0; i < n; i++) {
		string num;
		cin >> num;
		b += num;
	}

	cout << (stoll(a) > stoll(b) ? b : a);
	
	return 0;
}

#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

string a, b;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> a >> b;

	int n = a.size();
	string and_res = "";
	for (int i = 0; i < n; i++) {
		if (a[i] == '1' && b[i] == '1') and_res += '1';
		else and_res += '0';
	}

	string or_res = "";
	for (int i = 0; i < n; i++) {
		if (a[i] == '1' || b[i] == '1') or_res += '1';
		else or_res += '0';
	}

	string xor_res = "";
	for (int i = 0; i < n; i++) {
		if (a[i] == b[i]) xor_res += '0';
		else xor_res += '1';
	}

	string not_a = "";
	for (int i = 0; i < n; i++) {
		if (a[i] == '1') not_a += '0';
		else not_a += '1';
	}

	string not_b = "";
	for (int i = 0; i < n; i++) {
		if (b[i] == '1') not_b += '0';
		else not_b += '1';
	}

	cout << and_res << "\n";
	cout << or_res << "\n";
	cout << xor_res << "\n";
	cout << not_a << "\n";
	cout << not_b << "\n";

	return 0;
}
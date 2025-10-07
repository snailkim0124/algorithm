#include <bits/stdc++.h>
#include <limits.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int n;
string s[105];
int kbs1, kbs2;
string ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
		if (s[i] == "KBS1") kbs1 = i;
		else if (s[i] == "KBS2") kbs2 = i;
	}

	for (int i = 0; i < kbs1; i++) {
		ans += "1";
	}

	for (int i = 0; i < kbs1; i++) {
		ans += "4";
	}

	if (kbs1 > kbs2) kbs2++;

	for (int i = 0; i < kbs2; i++) {
		ans += "1";
	}

	for (int i = 0; i < kbs2 - 1; i++) {
		ans += "4";
	}
	
	cout << ans << "\n";

	return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n;
vector<string> v;

bool cmp(string& a, string& b) {
	return a + b > b + a;
}

bool isZero(string a) {
	for (auto c : a) {
		if (c != '0') return false;
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		string num;
		cin >> num;
		v.push_back(num);
	}

	sort(v.begin(), v.end(), cmp);

	string ans = "";
	for (auto it : v) {
		ans += it;
	}

	if (isZero(ans)) cout << 0;
	else cout << ans;
	
	return 0;
}
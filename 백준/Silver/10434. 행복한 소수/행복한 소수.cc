#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int p;
bool isprime[10005];

int go(int num) {
	int res = 0;
	string s = to_string(num);
	for (char it : s) {
		res += (it - '0') * (it - '0');
	}

	return res;
}


bool check(int num) {
	set<int> s;
	int tmp = num;
	s.insert(tmp);

	while (1) { 
		tmp = go(tmp);
		// cout << tmp << "\n";
		if (tmp == 1) return true;
		if (s.count(tmp)) return false;
		s.insert(tmp);
	}

	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	memset(isprime, true, sizeof(isprime));

	isprime[1] = false;
	for (int i = 2; i < 10005; i++) {
		for (int j = i + i; j < 10005; j += i) {
			isprime[j] = false;
		}
	}

	//for (int i = 1; i <= 30; i++) {
	//	if (isprime[i]) cout << i << "\n";
	//}

	cin >> p;
	while (p--) {
		int t, m;
		cin >> t >> m;
		string ans = "";

		if (isprime[m] && check(m)) {
			ans = "YES";
		}
		else {
			ans = "NO";
		}

		cout << t << " " << m << " " << ans << "\n";
	}
	
	
	return 0;
}
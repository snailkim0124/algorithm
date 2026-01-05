#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

string s;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> s;
	string tmp = s;
	reverse(all(tmp));

	// 팰린드롬이면 -1
	if (s == tmp) {
		bool flag = false;
		for (int i = 0; i < s.size() - 1; i++) {
			if (s[i] != s[i + 1]) {
				flag = true;
				break;
			}
		}

		// 알파벳이 모두 같으면 안됨
		if (!flag) {
			cout << -1 << "\n";
		}
		else cout << s.size() - 1 << "\n";
	}
	else {
		cout << s.size() << "\n";
	}
	

	return 0;
}
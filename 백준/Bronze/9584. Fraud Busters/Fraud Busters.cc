#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

string scanner;
int n;
vector<string> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> scanner;
	cin >> n;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;

		bool flag = true;
		for (int j = 0; j < scanner.size(); j++) {
			if (scanner[j] == '*') continue;
			if (scanner[j] != s[j]) {
				flag = false;
				break;
			}
		}

		if (flag) v.push_back(s);
	}

	cout << v.size() << "\n";
	for (auto it : v) {
		cout << it << "\n";
	}
	
	return 0;
}
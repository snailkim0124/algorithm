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
int a, b;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> s;
	for (int i = 0; i < s.size(); i += 2) {
		if (s[i] == 'A') {
			a += s[i + 1] - '0';
		}
		else if (s[i] == 'B') {
			b += s[i + 1] - '0';
		}

		if (a == 10 && b == 10) {
			int tmpa = 0;
			int tmpb = 0;
			for (int j = i + 2; j < s.size(); j += 2) {
				if (s[j] == 'A') {
					tmpa += s[j + 1] - '0';
				}
				else if (s[j] == 'B') {
					tmpb += s[j + 1] - '0';
				}
			}

			if (tmpa >= 2) {
				cout << "A\n";
				exit(0);
			}
			if (tmpb >= 2) {
				cout << "B\n";
				exit(0);
			}
		}

		if (a >= 11) {
			cout << "A\n";
			break;
		}
		if (b >= 11) {
			cout << "B\n";
			break;
		}
	}


	

	return 0;
}
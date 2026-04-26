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
int cnt;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	getline(cin, s);
	for (auto c : s) {
		if (isalpha(c)) {
			if (tolower(c) == 'a') cnt++;
			else if (c == 'B') cnt += 2;
			else if (c == 'b') cnt++;
			else if (tolower(c) == 'd') cnt++;
			else if (c == 'e') cnt++;
			else if (c == 'g') cnt++;
			else if (tolower(c) == 'o') cnt++;
			else if (tolower(c) == 'p') cnt++;
			else if (tolower(c) == 'q') cnt++;
			else if (c == 'R') cnt++;
		}
		else if (c == '@') {
			cnt++;
		}
	}

	cout << cnt << "\n";
	
	
	return 0;
}
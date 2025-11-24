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
string s;
int a, b;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> s;
	for (auto c : s) {
		if (c == 's') a++;
		else if (c == 'b') b++;
	}

	if (a > b) cout << "security!";
	else if (a < b) cout << "bigdata?";
	else cout << "bigdata? security!";

	return 0;
}
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

string a, b, c, d;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> a >> b >> c >> d;
	string tmp = a + b;
	string tmp2 = c + d;
	cout << stoll(tmp) + stoll(tmp2);

	return 0;
}
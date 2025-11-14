#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

vector<pair<string, char>> v;
int red, blue;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	for (int i = 0; i < 8; i++) {
		string m;
		char c;
		cin >> m >> c;
		v.push_back({ m, c });
	}

	sort(all(v));

	if (v[0].second == 'B') blue += 10;
	else red += 10;
	if (v[1].second == 'B') blue += 8;
	else red += 8;
	if (v[2].second == 'B') blue += 6;
	else red += 6;
	if (v[3].second == 'B') blue += 5;
	else red += 5;
	if (v[4].second == 'B') blue += 4;
	else red += 4;
	if (v[5].second == 'B') blue += 3;
	else red += 3;
	if (v[6].second == 'B') blue += 2;
	else red += 2;
	if (v[7].second == 'B') blue += 1;
	else red += 1;

	if (red > blue) cout << "Red\n";
	else cout << "Blue\n";


	/*cout << "=============\n";
	
	for (auto [m, c] : v) {
		cout << m << " " << c << "\n";
	}*/


	return 0;
}
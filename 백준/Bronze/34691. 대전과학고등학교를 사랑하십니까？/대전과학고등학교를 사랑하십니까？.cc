#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;



int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	while (1) {
		string s;
		cin >> s;
		if (s == "end") break;

		if (s == "animal") {
			cout << "Panthera tigris\n";
		}
		else if (s == "flower") {
			cout << "Forsythia koreana\n";
		}
		else if (s == "tree") {
			cout << "Pinus densiflora\n";
		}
	}

	return 0;
}
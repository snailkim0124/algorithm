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
int s, g, p, d;
string mvp;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	cin >> s >> g >> p >> d;
	cin >> mvp;

	int sum = 0;
	int prev = 0;

	for (int i = 0; i < mvp.size(); i++) {
		if (mvp[i] == 'B') {
			prev = s - 1 - prev;
			sum += prev;
		}
		else if (mvp[i] == 'S') {
			prev = g - 1 - prev;
			sum += prev;
		}
		else if (mvp[i] == 'G') {
			prev = p - 1 - prev;
			sum += prev;
		}
		else if (mvp[i] == 'P') {
			prev = d - 1 - prev;
			sum += prev;
		}
		else if (mvp[i] == 'D') {
			sum += d;
		}
	}

	cout << sum << "\n";
	
	return 0;
}
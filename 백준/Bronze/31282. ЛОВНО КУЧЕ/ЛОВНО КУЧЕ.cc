#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int n, m, k;
int cnt;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m >> k;
	int dog = 0;
	int rabbit = n;

	while (1) {
		if (dog >= rabbit) break;
		rabbit += m;
		dog += k;
		cnt++;
	}

	cout << cnt << "\n";


	return 0;
}
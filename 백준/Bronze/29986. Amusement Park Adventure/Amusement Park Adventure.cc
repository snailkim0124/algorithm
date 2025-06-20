#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n, h;
int cnt;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> h;
	while (n--) {
		int num;
		cin >> num;
		if (num <= h) cnt++;
	}
	
	cout << cnt;

	return 0;
}

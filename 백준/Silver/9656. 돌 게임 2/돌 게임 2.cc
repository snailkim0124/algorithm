#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n;
int cnt;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	while (1) {
		if (n == 1) {
			cnt++;
			break;
		}
		else if (n > 3) {
			n -= 3;
			cnt++;
		}
		else {
			n--;
			cnt++;
		}
	}

	if (cnt % 2 == 0) {
		cout << "SK"; // 상근이 먼저
	}
	else {
		cout << "CY"; // 창영이
	}

	return 0;
}
#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

ll n, k;
ll arr[25];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> k;
	for (int i = 0; i < k; i++) {
		cin >> arr[i];
	}

	ll sum = 0;
	for (int mask = 1; mask < (1 << k); mask++) {
		ll cnt = 0;
		ll LCM = 1;
		for (int i = 0; i < k; i++) {
			if (mask & (1 << i)) {
				LCM = lcm(LCM, arr[i]);
				// 오버플로 방지
				if (LCM > n) {
					LCM = 0;
					break;
				}
				cnt++;
			}
		}

		if (LCM == 0) continue;
		
		// 홀수는 더하고 짝수는 빼기 (포함 배제)
		if (cnt % 2 == 1) {
			sum += n / LCM;
		}
		else {
			sum -= n / LCM;
		}
	}
	
	cout << sum << "\n";
	
	return 0;
}
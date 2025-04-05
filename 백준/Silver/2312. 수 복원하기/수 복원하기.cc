#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int t;
int prime[100005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
	for (int i = 2; i < 100005; i++) {
		prime[i] = i;
	}

	for (int i = 2; i * i <= 100005; i++) {
		if (prime[i] != 0) {
			for (int j = i + i; j < 100005; j += i) {
				prime[j] = 0;
			}
		}
	}


    cin >> t;
	while (t--) {
		int n;
		int cnt[100005] = { 0 };
		cin >> n;

		int tmp = n;
		for(int i = 2; i <= tmp; i++) {
			while (tmp % i == 0) {
				tmp /= i;
				cnt[i]++;
			}
		}

		for (int i = 2; i <= n; i++) {
			if (cnt[i]) cout << i << " " << cnt[i] << "\n";
		}
		

	}
    
    return 0;
}
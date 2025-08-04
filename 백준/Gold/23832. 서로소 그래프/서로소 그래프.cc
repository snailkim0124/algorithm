#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n;
int arr[50005];
int prime[50005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 1; i <= n; i++) {
		prime[i] = i;
	}

	for (int i = 2; i <= n; i++) {
		if (prime[i] == i) {
			prime[i] = i - 1;
			for (int j = 2 * i; j <= n; j += i) {
				prime[j] -= prime[j] / i;
			}
		}
	}

	for (int i = 2; i <= n; i++) {
		prime[i] += prime[i - 1];
	}

	cout << prime[n] - 1;

	return 0;
}
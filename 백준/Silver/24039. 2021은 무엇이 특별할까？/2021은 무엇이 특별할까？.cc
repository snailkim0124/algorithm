#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int prime[100005];
vector<int> seq_prime;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	fill(prime, prime + 100005, 1);
	prime[1] = 0;
	for (int i = 2; i * i <= 100005; i++) {
		if (!prime[i]) continue;
		for (int j = i + i; j <= 100005; j += i) {
			prime[j] = 0;
		}
	}

	for (int i = 2; i <= 120; i++) {
		for (int j = i + 1; j <= 120; j++) {
			if (prime[i] && prime[j]) {
				seq_prime.push_back(i * j);
				break;
			}
		}
	}

	int n;
	cin >> n;
	for (auto it : seq_prime) {
		if (it > n) {
			cout << it << "\n";
			break;
		}
	}
	
	
	return 0;
}
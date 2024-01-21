#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n;
vector<tuple<ll, ll, ll>> v[15];
ll visited[15];
ll LCM = 1;
ll arr[15];

ll gcd(ll a, ll b) {
	if (b == 0) {
		return a;
	}
	return gcd(b, a % b);
}

void dfs(ll here) {
	visited[here] = 1;
	for (auto there : v[here]) {
		if (!visited[get<0>(there)]) {
			arr[get<0>(there)] = arr[here] * get<2>(there) / get<1>(there);
			dfs(get<0>(there));
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		ll a, b, p, q;
		cin >> a >> b >> p >> q;
		v[a].push_back({ b,p,q });
		v[b].push_back({ a,q,p });
		LCM *= (p * q / gcd(p, q));
	}

	arr[0] = LCM;

	dfs(0);

	ll gcdd = arr[0];
	for (int i = 1; i < n; i++) {
		gcdd = gcd(gcdd, arr[i]);
	}

	for (int i = 0; i < n; i++) {
		cout << arr[i] / gcdd << " ";
	}


	return 0;
}
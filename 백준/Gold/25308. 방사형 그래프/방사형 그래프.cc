#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

ll arr[10];
int visited[10];
vector<ll> v;
ll res;

bool check() {
	for (int i = 0; i < 8; i++) {
		ll a = v[i % 8];
		ll b = v[(i + 1) % 8];
		ll c = v[(i + 2) % 8];

		if ((a + c) * (a + c) * b * b < 2 * a * a * c * c) return false;
	}

	return true;
}

void go(int depth) {
	if (depth == 8) {
		if (check()) res++;
		return;
	}

	for (int i = 0; i < 8; i++) {
		if (!visited[i]) {
			visited[i] = 1;
			v.push_back(arr[i]);
			go(depth + 1);
			v.pop_back();
			visited[i] = 0;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	for (int i = 0; i < 8; i++) {
		cin >> arr[i];
	}

	go(0);
	
	cout << res;

	return 0;
}
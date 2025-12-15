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
vector<int> v;
int cnt[1005];

bool check() {
	for (int i = 0; i < v.size(); i++) {
		if (v[i]) return false;
	}

	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	v.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	queue<pii> q;
	for (int i = 0; i < n; i++) {
		q.push({ i, v[i] });
	}

	int tmp = 0;
	while (!q.empty()) {
		auto [idx, now] = q.front();
		q.pop();

		tmp++;
		now--;

		if (now == 0) {
			cnt[idx] = tmp;
		}
		else {
			q.push({ idx, now });
		}
	}


	for (int i = 0; i < n; i++) {
		cout << cnt[i] << " ";
	}
	cout << "\n";
	

	return 0;
}
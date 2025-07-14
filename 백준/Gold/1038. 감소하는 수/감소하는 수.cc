#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll n;
vector<ll> v;
queue<ll> q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < 10; i++) {
		v.push_back(i);
		q.push(i);
	}

	while (!q.empty()) {
		string num = to_string(q.front());
		q.pop();

		for (ll i = 0; i < num[num.size() - 1] - '0'; i++) {
			string tmp = num;
			tmp.push_back(i + '0');

			q.push(stoll(tmp));
			v.push_back(stoll(tmp));
		}
	}

	sort(v.begin(), v.end());
	if (n >= v.size()) cout << -1;
	else cout << v[n];

	return 0;
}
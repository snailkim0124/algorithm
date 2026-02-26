#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int n, m;
int arr[100005];
priority_queue<pll, vector<pll>, greater<pll>> pq;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		pq.push({ arr[i], i });
	}

	cin >> m;
	while (m--) {
		int cmd, i, v;
		cin >> cmd;
		//cout << pq.top().first << " : " << pq.top().second << "\n";

		if (cmd == 1) {
			cin >> i >> v;
			arr[i] = v;
			pq.push({ v, i });
		}
		else if (cmd == 2) {
			while (!pq.empty() && pq.top().first != arr[pq.top().second]) {
				pq.pop();
			}
			cout << pq.top().second << "\n";
		}
	}
	
	
	return 0;
}
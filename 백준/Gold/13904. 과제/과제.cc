#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


int n;
priority_queue<pii, vector<pii>> pq;
int visited[1005];
int res;
int mx;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	while (n--) {
		int d, w;
		cin >> d >> w;
		pq.push({ w, d });
		mx = max(mx, d);
	}

	while (!pq.empty()) {
		pii now = pq.top();
		pq.pop();

		for (int i = now.second; i > 0; i--) {
			if (!visited[i]) {
				visited[i] = now.first;
				break;
			}
		}
	}

	for (int i = 1; i <= mx; i++) {
		res += visited[i];
	}
	cout << res;
	
	return 0;
}
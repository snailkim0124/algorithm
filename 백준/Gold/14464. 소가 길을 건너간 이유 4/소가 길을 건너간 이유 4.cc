#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

struct cmp {
	bool operator()(pii a, pii b) {
		if (a.second != b.second) return a.second > b.second;
		return a.first > b.first;
	}
};

int c, n;
int t[20005];
int visited[20005];
pii cow[20005];
priority_queue<pii, vector<pii>, cmp> pq; // 끝나는 시간 정렬 -> 시작 시간으로 정렬
int cnt;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> c >> n;
	for (int i = 0; i < c; i++) {
		cin >> t[i];
	}

	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		pq.push({ a, b });
	}

	sort(t, t + c);

	while (!pq.empty()) {
		for (int i = 0; i < c; i++) {
			if (pq.top().first <= t[i] && t[i] <= pq.top().second && !visited[i]) {
				visited[i] = 1;
				cnt++;
				break;
			}
		}
		pq.pop();
	}

	cout << cnt;
	
	return 0;
}
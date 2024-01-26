#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
int n, l;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	priority_queue<pii, vector<pii>, greater<pii>> pq;

	cin >> n >> l;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		pq.push({ num, i }); // 값, 인덱스 : 메모리 효율

		while (pq.top().second <= i - l) {
			pq.pop();
		}
		cout << pq.top().first << " ";
	}
	
	return 0;
}
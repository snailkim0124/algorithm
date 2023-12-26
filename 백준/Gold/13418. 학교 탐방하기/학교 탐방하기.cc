#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

typedef struct EDGE1 {
	int s, e, v;
	bool operator > (const EDGE1& temp) const {
		return v < temp.v;
	}
}EDGE1;

typedef struct EDGE2 {
	int s, e, v;
	bool operator > (const EDGE2& temp) const {
		return v > temp.v;
	}
}EDGE2;

int n, m;
int parent[1005];
priority_queue<EDGE1, vector<EDGE1>, greater<EDGE1>> mn_pq; // 오름차순
priority_queue<EDGE2, vector<EDGE2>, greater<EDGE2>> mx_pq;

int findParent(int a) {
	if (a == parent[a]) {
		return a;
	}
	else {
		return parent[a] = findParent(parent[a]);
	}
}

void unionParent(int a, int b) {
	a = findParent(a);
	b = findParent(b);

	if (a != b) {
		parent[b] = a;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i <= n; i++) { // 부모 초기화
		parent[i] = i;
	}

	for (int i = 0; i < m + 1; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		mn_pq.push({ a,b,c });
		mx_pq.push({ a,b,c });
	}

	int mn_res = 0;

	while (!mn_pq.empty()) {
		EDGE1 now = mn_pq.top();
		mn_pq.pop();

		if (findParent(now.s) != findParent(now.e)) { // 연결핻도 사이클이 생기지 않는다면
			unionParent(now.s, now.e);
			if (now.v == 0) mn_res++;
		}
	}

	for (int i = 0; i <= n; i++) { // 부모 초기화
		parent[i] = i;
	}

	int mx_res = 0;

	while (!mx_pq.empty()) {
		EDGE2 now = mx_pq.top();
		mx_pq.pop();

		if (findParent(now.s) != findParent(now.e)) { // 연결핻도 사이클이 생기지 않는다면
			unionParent(now.s, now.e);
			if (now.v == 0) mx_res++;
		}
	}

	cout << mx_res * mx_res - mn_res * mn_res;
	return 0;
}
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int g, p;
int parent[100005];
int res;

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

	if (a > b) {
		parent[a] = b;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> g;
	cin >> p;
	for (int i = 1; i <= g; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < p; i++) {
		int num, tmp;
		cin >> num;
		tmp = findParent(num);
		if (!findParent(num)) break;
		unionParent(tmp, tmp - 1); // 이전 거와 연결하기
		res++;
	}

	cout << res;

	return 0;
}
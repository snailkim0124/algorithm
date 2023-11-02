#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int k;
int tree[20000];
int idx;
vector<int> v[15];

void buildtree(int start, int end, int depth) {
	if (start >= end) return;

	int mid = (start + end) / 2;
	v[depth].push_back(tree[mid]);
	buildtree(start, mid, depth + 1);
	buildtree(mid + 1, end, depth + 1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> k;
	int n;
	while (!cin.eof()) {
		cin >> n;
		tree[idx++] = n;
	}

	buildtree(0, idx -1, 0);

	for (int i = 0; i < k; i++) {
		for (auto it : v[i]) {
			cout << it << " ";
		}
		cout << "\n";
	}

	return 0;
}
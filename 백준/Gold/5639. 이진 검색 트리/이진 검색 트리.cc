#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int tree[10005];
int idx = 0;

void postorder(int start, int end) {
	if (start >= end) return;
	if (start == end - 1) {
		cout << tree[start] << "\n";
		return;
	}

	int tmp = start + 1;
	while (tmp < end) {
		if (tree[start] < tree[tmp]) {
			break;
		}
		tmp++;
	}

	postorder(start + 1, tmp);
	postorder(tmp, end);
	cout << tree[start] << "\n";
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	while (!cin.eof()) {
		cin >> n;
		tree[idx++] = n;
	}

	postorder(0, idx-1);
	return 0;
}
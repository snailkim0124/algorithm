#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}

	if (!next_permutation(v.begin(), v.end())) {
		cout << -1;
		exit(0);
	}

	for (auto it : v) {
		cout << it << " ";
	}


	return 0;
}
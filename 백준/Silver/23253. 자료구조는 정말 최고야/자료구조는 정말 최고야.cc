#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

bool check;
int n, m;
int arr[200005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	while (m--) {
		int k;
		cin >> k;
		cin >> arr[0];
		for (int i = 1; i < k; i++) {
			cin >> arr[i];
			if (arr[i - 1] < arr[i]) {
				check = true;
				cout << "No";
				exit(0);
			}
		}
	}

	if (!check) cout << "Yes";

	return 0;
}
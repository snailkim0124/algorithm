#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n;
int sum;
int tmp;
int arr[105];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < n; i++) {
		if (arr[i] == 1) {
			tmp++;
			sum += tmp;
		}
		else if (arr[i] == 0) {
			tmp = 0;
		}
	}

	cout << sum;

	return 0;
}
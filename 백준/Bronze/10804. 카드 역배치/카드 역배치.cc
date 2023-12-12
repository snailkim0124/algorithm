#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int arr[25];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	for (int i = 1; i <= 20; i++) {
		arr[i] = i;
	}

	for (int i = 0; i < 10; i++) {
		int a, b;
		cin >> a >> b;
		reverse(arr + a, arr + b + 1);
	}

	for (int i = 1; i <= 20; i++) {
		cout << arr[i] << " ";
	}
	

	return 0;
}
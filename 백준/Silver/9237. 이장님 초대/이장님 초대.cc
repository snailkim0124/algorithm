#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n;
int arr[100005];
int mx;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		arr[i] += 1;
	}
	sort(arr, arr + n, greater<>());


	/*for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << "\n";*/
	for (int i = 0; i < n; i++) {
		arr[i] = arr[i] - (n - i);
		mx = max(mx, arr[i]);
		//cout << arr[i] << " ";
	}
	//cout << "\n";

	cout << n + mx +1;

	return 0;
}
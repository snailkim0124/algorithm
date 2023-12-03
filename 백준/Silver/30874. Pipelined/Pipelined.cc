#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n;
ll arr[200005];
ll sum;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}


	sort(arr, arr + n);

	cout << arr[n-1] + (n - 1);


	return 0;
}

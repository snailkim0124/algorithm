#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
int arr[500005];
ll res;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + n);

	for (int i = 0; i < n; i++) {
		res += abs(arr[i] - (i + 1));
	}

	cout << res;
	
	
	return 0;
}
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n, m;
int arr[200005];
int mn = 987654321;
int idx;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);


	int left = 0;
	int right = n-1;

	idx = arr[(left + right) / 2];

	cout << idx;
	return 0;
}
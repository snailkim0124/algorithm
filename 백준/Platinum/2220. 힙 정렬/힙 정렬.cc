#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int n;
int arr[100005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		arr[i] = i;
	}

	for (int i = 2; i <= n; i++) {
		swap(arr[i - 1], arr[i]);

		for (int j = i - 1; j > 1; j /= 2) {
			swap(arr[j], arr[j / 2]);
		}
	}

	for (int i = 1; i <= n; i++) {
		cout << arr[i] << " ";
	}

	cout << "\n";
	
	
	return 0;
}
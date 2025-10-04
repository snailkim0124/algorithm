#include <bits/stdc++.h>
#include <limits.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

ull m, n;
ull arr[100005];
ull sum, res;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		sum += arr[i];
	}
	sum -= m;

	sort(arr, arr + n);

	for (int i = 0; i < n; i++) {
		ull tmp = min(arr[i], sum / (n - i));
		res += tmp * tmp;
		sum -= tmp;
	}

	cout << res << "\n";
	
	

	return 0;
}
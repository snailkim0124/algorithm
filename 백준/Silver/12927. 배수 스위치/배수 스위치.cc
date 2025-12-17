#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

string s;
int arr[1005];
int n;
vector<int> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> s;
	n = s.size();

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'Y') arr[i + 1] = 1;
		else if (s[i] == 'N') arr[i + 1] = 0;
	}

	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (arr[i]) {
			cnt++;
			for (int j = i; j <= n; j += i) {
				arr[j] ^= 1;
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		if (arr[i]) {
			cout << -1 << "\n";
			exit(0);
		}
	}

	cout << cnt << "\n";
	

	return 0;
}
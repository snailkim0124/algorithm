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
int arr[15];
int mx = -1;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			for (int k = j + 1; k < n; k++) {
				//cout << i << " : " << j << " : " << k << "\n";

				int tmp1 = -1;
				for (int ii = 0; ii < i; ii++) {
					if (tmp1 == -1) tmp1 = 1;
					tmp1 *= arr[ii];
				}

				int tmp2 = -1;
				for (int jj = i; jj < j; jj++) {
					if (tmp2 == -1) tmp2 = 1;
					tmp2 *= arr[jj];
				}

				int tmp3 = -1;
				for (int kk = j; kk < k; kk++) {
					if (tmp3 == -1) tmp3 = 1;
					tmp3 *= arr[kk];
				}

				int tmp4 = -1;
				for (int pp = k; pp < n; pp++) {
					if (tmp4 == -1) tmp4 = 1;
					tmp4 *= arr[pp];
				}

				if(tmp1 != -1 && tmp2 != -1 && tmp3 != -1 && tmp4 != -1) mx = max(mx, tmp1 + tmp2 + tmp3 + tmp4);
			}
		}
	}

	cout << mx << "\n";
	

	return 0;
}

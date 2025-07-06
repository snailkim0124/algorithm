#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n;
int arr[305], brr[305];
int mxa, mxb;
int cnta, cntb;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < n; i++) {
		cin >> brr[i];
	}

	for (int i = 0; i < n; i++) {
		if (arr[i] == brr[i]) {
			if (cnta == 0) {
				cnta++;
				cntb = 0;
			}
			else if (cntb == 0) {
				cntb++;
				cnta = 0;
			}
			continue;
		}
		if (arr[i] == 1) {
			if (brr[i] == 2) {
				cntb++;
				cnta = 0;
			}
			else if (brr[i] == 3) {
				cnta++;
				cntb = 0;
			}
		}
		else if (arr[i] == 2) {
			if (brr[i] == 3) {
				cntb++;
				cnta = 0;
			}
			else if (brr[i] == 1) {
				cnta++;
				cntb = 0;
			}
		}
		else if (arr[i] == 3) {
			if (brr[i] == 1) {
				cntb++;
				cnta = 0;
			}
			else if (brr[i] == 2) {
				cnta++;
				cntb = 0;
			}
		}

		mxa = max(mxa, cnta);
		mxb = max(mxb, cntb);
	}

	cout << max(mxa, mxb);
	

	return 0;
}
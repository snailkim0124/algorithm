#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int t;
int res;
int lnov[200005] = { 0 };
int rnov[200005] = { 0 };
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> t;


	for (int i = 0; i < t; i++) {
		cin >> lnov[i] >> rnov[i];
	}

	for (int i = 0; i < t; i++) {
		if (i != 0 && lnov[i]) {
			if (lnov[i] == lnov[i - 1]) res++;
		}
		if (i != 0 && rnov[i]) {
			if (rnov[i] == rnov[i - 1]) res++;
		}
		if (lnov[i] && rnov[i] && lnov[i] == rnov[i]) {
			res++;
		}
	}

	cout << res;


	return 0;
}
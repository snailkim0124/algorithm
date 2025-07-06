#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n;
int arr[100005], tmp[100005];
int cnt[5];
int mn = 987654321;

int swapping(int a, int b, int c) {
	int cnta[5] = { 0 };
	int cntb[5] = { 0 };
	int cntc[5] = { 0 };

	int res = 0;

	for (int i = 0; i < cnt[a]; i++) {
		cnta[arr[i]]++;
	}
	for (int i = cnt[a]; i < cnt[a] + cnt[b]; i++) {
		cntb[arr[i]]++;
	}
	for (int i = cnt[a] + cnt[b]; i < n; i++) {
		cntc[arr[i]]++;
	}

	// a - b 바꾸기
	int ab = min(cnta[b], cntb[a]);
	cnta[b] -= ab;
	cntb[a] -= ab;
	res += ab;

	// a - c 바꾸기
	int ac = min(cnta[c], cntc[a]);
	cnta[c] -= ac;
	cntc[a] -= ac;
	res += ac;

	// b - c 바꾸기
	int bc = min(cntb[c], cntc[b]);
	cntb[c] -= bc;
	cntc[b] -= bc;
	res += bc;

	res += (cnta[b] + cntb[a]) * 2;

	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		cnt[arr[i]]++;
	}

	mn = min(mn, swapping(1, 2, 3));
	mn = min(mn, swapping(1, 3, 2));
	mn = min(mn, swapping(2, 1, 3));
	mn = min(mn, swapping(2, 3, 1));
	mn = min(mn, swapping(3, 1, 2));
	mn = min(mn, swapping(3, 2, 1));

	//cout << "123 : " << swapping(1, 2, 3) << "\n";
	//cout << "132 : " << swapping(1, 3, 2) << "\n";
	//cout << "213 : " << swapping(2, 1, 3) << "\n";
	//cout << "231 : " << swapping(2, 3, 1) << "\n";
	//cout << "312 : " << swapping(3, 1, 2) << "\n";
	//cout << "321 : " << swapping(3, 2, 1) << "\n";
	cout << mn;
	
	return 0;
}
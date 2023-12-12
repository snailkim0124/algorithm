#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n;
int arr[3]; // 메모리 줄이기
int mindp[3];
int maxdp[3];
int tmp0, tmp1, tmp2; 
int mn, mx;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[0] >> arr[1] >> arr[2];

		tmp0 = maxdp[0];
		tmp1 = maxdp[1];
		tmp2 = maxdp[2];
		maxdp[0] = max(tmp0, tmp1) + arr[0];
		maxdp[1] = max(max(tmp0, tmp1), tmp2) + arr[1];
		maxdp[2] = max(tmp1, tmp2) + arr[2];

		tmp0 = mindp[0];
		tmp1 = mindp[1];
		tmp2 = mindp[2];
		mindp[0] = min(tmp0, tmp1) + arr[0];
		mindp[1] = min(min(tmp0, tmp1), tmp2) + arr[1];
		mindp[2] = min(tmp1, tmp2) + arr[2];
	}

	mn = min(min(mindp[0], mindp[1]), mindp[2]);
	mx = max(max(maxdp[0], maxdp[1]), maxdp[2]);

	cout << mx << " " << mn;

	return 0;
}
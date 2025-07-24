#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n, k;
int arr[105];
int check[105];
int cnt;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> k;
	for (int i = 0; i < k; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < k; i++) {
		bool flag = false;
		// 내가 원하는 전자기기가 꽂혀있는 경우
		for (int j = 0; j < n; j++) {
			if (check[j] == arr[i]) {
				flag = true;
				break;
			}
		}
		if (flag) continue;

		// 빈 구멍 찾아서 꼽기
		for (int j = 0; j < n; j++) {
			if (!check[j]) {
				check[j] = arr[i];
				flag = true;
				break;
			}
		}
		if (flag) continue;


		// 원하는 전자기기가 없는 경우
		int pos = -1; // 뺄 거
		int last = -1;

		for (int j = 0; j < n; j++) {
			int tmp = 0;
			for (int ii = i + 1; ii < k; ii++) {
				if (arr[ii] == check[j]) break;
				tmp++;
			}

			if (tmp > last) {
				last = tmp;
				pos = j;
			}
		}

		check[pos] = arr[i];
		cnt++;
	}
	
	cout << cnt;

	return 0;
}
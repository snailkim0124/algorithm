#include <bits/stdc++.h>

using namespace std;

int money;
int arr[20];
int a;
int b;
int a_cnt;
int b_cnt;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);


	cin >> money;
	for (int i = 0; i < 14; i++) {
		cin >> arr[i];
	}

	a = money;
	b = money;

	for (int i = 0; i < 14; i++) { // 준현의 경우
		if (a >= arr[i]) {
			a_cnt += a / arr[i];
			a %= arr[i];
		}
	}

	int now = -1;
	for (int i = 0; i < 14; i++) { // 성민의 경우
		if (i > 1 && i <13 && arr[i - 2] > arr[i - 1] && arr[i - 1] > arr[i] && b >= arr[i]) {
			b_cnt += b / arr[i+1]; // 매수
			b %= arr[i+1];
			now = arr[i+1];
		}

		if (i > 1 && i < 13 && arr[i - 2] < arr[i - 1] && arr[i - 1] < arr[i] && now <= arr[i]) {
			b += b_cnt * arr[i+1]; // 매도
			b_cnt = 0;
			now = arr[i+1];
		}
	}

	a += a_cnt * arr[13];
	b += b_cnt * arr[13];

	if (a == b) cout << "SAMESAME";
	else if (a > b) cout << "BNP";
	else cout << "TIMING";
	
	return 0;
}
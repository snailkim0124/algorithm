#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <map>
#include <set>
#include <string>

using namespace std;

int arr[7][7];
bool ans[7][7];
int speak[25];
int res;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < 25; i++) {
		cin >> speak[i];
	}

	for (int k = 0; k < 25; k++) {
		int check = 0;
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				if (arr[i][j] == speak[k]) {
					ans[i][j] = true;
					break;
				}
			}
		}
		res++;

		for (int i = 0; i < 5; i++) {
			int cnt = 0;
			for(int j = 0; j < 5 ; j++) {
				if (ans[i][j]) {
					cnt++;
				}
			}
			if (cnt == 5) check++;
		}

		for (int i = 0; i < 5; i++) {
			int cnt = 0;
			for (int j = 0; j < 5; j++) {
				if (ans[j][i]) {
					cnt++;
				}
			}
			if (cnt == 5) check++;
		}

		int cnt = 0;
		for (int i = 0; i < 5; i++) {
			if (ans[i][4 - i]) {
				cnt++;
			}
		}
		if (cnt == 5) check++;

		cnt = 0;
		for (int i = 0; i < 5; i++) {
			if (ans[i][i]) {
				cnt++;
			}
		}
		if (cnt == 5) check++;

		if (check >= 3) break;
	}

	cout << res;
	return 0;
}
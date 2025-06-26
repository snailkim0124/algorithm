#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n, k;
typedef struct medal {
	int num;
	int gold, silver, bronze;
} medal;
medal arr[1005];
int cnt = 1, same = 0;

bool cmp(medal& a, medal& b) {
	if (a.gold != b.gold) return a.gold > b.gold;
	if (a.silver != b.silver) return a.silver > b.silver;
	if (a.bronze != b.bronze) return a.bronze > b.bronze;
	return a.num < b.num;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> arr[i].num >> arr[i].gold >> arr[i].silver >> arr[i].bronze;
	}

	sort(arr, arr + n, cmp);


	/*cout << "\n";
	for (int i = 0; i < n; i++) {
		cout << arr[i].num << " " << arr[i].gold << " " << arr[i].silver << " " << arr[i].bronze << "\n";
	}*/

	for (int i = 0; i < n; i++) {
		if (i > 0 && (arr[i].gold != arr[i - 1].gold || arr[i].silver != arr[i - 1].silver || arr[i].bronze != arr[i - 1].bronze)) {
			cnt += same;
			same = 0;
		}

		if (arr[i].num == k) {
			cout << cnt;
			break;
		}

		same++;
	}

	return 0;
}
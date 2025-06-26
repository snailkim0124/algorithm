#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n, k;
typedef struct medal {
	int num;
	int gold, silver, copper;
} medal;
medal arr[1005];

bool cmp(medal& a, medal& b) {
	if (a.gold != b.gold) return a.gold > b.gold;
	if (a.silver != b.silver) return a.silver > b.silver;
	if (a.copper != b.copper) return a.copper > b.copper;
	return a.num < b.num;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> arr[i].num >> arr[i].gold >> arr[i].silver >> arr[i].copper;
	}

	sort(arr, arr + n, cmp);

	for (int i = 0; i < n; i++) {
		if (arr[i].num == k) {
			cout << i + 1;
			break;
		}
	}

	return 0;
}
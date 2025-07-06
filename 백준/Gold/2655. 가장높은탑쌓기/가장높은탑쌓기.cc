#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

typedef struct BLOCK {
	int area, height, weight, num;
}BLOCK;

int n;
int dp[105]; // 역추적용 dp
BLOCK arr[105];
int mx = -1;
vector<int> v;

bool cmp(BLOCK& a, BLOCK& b) {
	return a.area < b.area;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i].area >> arr[i].height >> arr[i].weight;
		arr[i].num = i + 1;
	}

	sort(arr, arr + n, cmp);

	// 최소 높이로 초기화
	for (int i = 0; i < n; i++) {
		dp[i] = arr[i].height;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[i].weight > arr[j].weight) {
				dp[i] = max(dp[i], dp[j] + arr[i].height);
			}
		}
		mx = max(mx, dp[i]);
	}

	for (int i = n - 1; i >= 0; i--) {
		if (dp[i] == mx) {
			v.push_back(arr[i].num);
			mx -= arr[i].height;
		}
	}

	reverse(v.begin(), v.end());

	cout << v.size() << "\n";
	for (auto it : v) {
		cout << it << "\n";
	}

	
	return 0;
}
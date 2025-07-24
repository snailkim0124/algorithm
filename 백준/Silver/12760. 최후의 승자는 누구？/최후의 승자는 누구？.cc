#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n, m;
int arr[105][105];
int mx[105];
int score[105];
vector<int> ans;
int mxscore;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
		sort(arr[i], arr[i] + m, greater<>());
	}

	for (int j = 0; j < m; j++) {
		for (int i = 0; i < n; i++) {
			mx[j] = max(mx[j], arr[i][j]);
		}
	}

	for (int j = 0; j < m; j++) {
		for (int i = 0; i < n; i++) {
			if (arr[i][j] == mx[j]) {
				score[i]++;
				mxscore = max(mxscore, score[i]);
			}
		}
	}


	for (int i = 0; i < n; i++) {
		if (mxscore == score[i]) {
			cout << i + 1 << " ";
		}
	}
	

	return 0;
}
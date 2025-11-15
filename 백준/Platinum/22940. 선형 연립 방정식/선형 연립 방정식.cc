#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

// 가우스 소거법
vector<double> gauss(vector<vector<double>> a) {
	int n = a.size();

	for (int i = 0; i < n; i++) {
		// pivot 찾기 (절댓값 중 가장 큰 것)
		int pivot = i;
		for (int k = i + 1; k < n; k++) {
			if (fabs(a[k][i]) > fabs(a[pivot][i])) {
				pivot = k;
			}
		}

		// pivot행 swap
		swap(a[i], a[pivot]);

		// pivot을 1로 만들기
		double div = a[i][i];
		for (int j = i; j <= n; j++) {
			a[i][j] /= div;
		}

		// pivot 아래 행을 0으로
		for (int k = i + 1; k < n; k++) {
			double factor = a[k][i];
			for (int j = i; j <= n; j++) {
				a[k][j] -= factor * a[i][j];
			}
		}
	}

	// 역대입
	vector<double> ans(n);
	for (int i = n - 1; i >= 0; i--) {
		ans[i] = a[i][n];
		for (int j = i + 1; j < n; j++) {
			ans[i] -= a[i][j] * ans[j];
		}
	}

	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;
	vector<vector<double>> matrix(n, vector<double>(n + 1));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n + 1; j++) {
			cin >> matrix[i][j];
		}
	}
	
	vector<double> ans = gauss(matrix);

	for (auto it : ans) {
		cout << it << " ";
	}
	
	return 0;
}
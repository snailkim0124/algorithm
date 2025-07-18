#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int t;
int n;
vector<int> in;
vector<int> pre;
int idx[1005];

void go(int preleft, int preright, int inleft, int inright) {
	if (preleft > preright || inleft > inright) return;

	int ans = pre[preleft];
	int ansidx = idx[ans];
	int leftsz = ansidx - inleft;

	go(preleft + 1, preleft + leftsz, inleft, ansidx - 1); // 왼쪽
	go(preleft + leftsz + 1, preright, ansidx + 1, inright); // 오른쪽

	cout << ans << " "; // 루트
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> t;
	while (t--) {
		pre.clear();
		in.clear();
		memset(idx, 0, sizeof(idx));

		cin >> n;
		for (int i = 0; i < n; i++) {
			int num;
			cin >> num;
			pre.push_back(num);
		}

		for (int i = 0; i < n; i++) {
			int num;
			cin >> num;
			in.push_back(num);
			idx[num] = i;
		}

		go(0, n - 1, 0, n - 1);
		cout << "\n";
	}



	return 0;
}
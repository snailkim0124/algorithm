#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n;
vector<int> in;
vector<int> post;
int idx[100005];

void go(int inleft, int inright, int postleft, int postright) {
	if (inleft > inright || postleft > postright) return;

	int ans = post[postright];
	int ansidx = idx[ans];
	int leftsz = ansidx - inleft;

	cout << ans << " ";

	go(inleft, ansidx - 1, postleft, postleft + leftsz - 1);
	go(ansidx + 1, inright, postleft + leftsz, postright - 1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		in.push_back(num);
		idx[num] = i;
	}

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		post.push_back(num);
	}

	go(0, n - 1, 0, n - 1);


	return 0;
}
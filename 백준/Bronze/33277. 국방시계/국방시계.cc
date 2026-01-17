#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int n, m;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	double per = (double)m / n;
	double sum = per * (24 * 60);

	int h = sum / 60;
	int m = (int)sum % 60;

	printf("%02d:%02d", h, m);


	return 0;
}
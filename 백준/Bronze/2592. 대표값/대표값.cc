#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int avg;
int cnt[105];
int bin;
int ans;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	for (int i = 0; i < 10; i++) {
		int num;
		cin >> num;
		avg += num;
		cnt[num/10]++;
	}

	avg /= 10;
	for (int i = 0; i <= 100; i++) {
		if (cnt[i] > bin) {
			bin = cnt[i];
			ans = i;
		}
	}

	cout << avg << "\n";
	cout << ans * 10;

	return 0;
}
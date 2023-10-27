#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<pair<int, int>> v(8);
int sum;
vector<int> v2;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	for (int i = 0; i < 8; i++) {
		cin >> v[i].first;
		v[i].second = i + 1;
	}

	sort(v.begin(), v.end(), greater<>());

	for (int i = 0; i < 5; i++) {
		sum += v[i].first;
		v2.push_back(v[i].second);
	}

	cout << sum << "\n";
	sort(v2.begin(), v2.end());
	for (auto it : v2) {
		cout << it << " ";
	}

	
	return 0;
}
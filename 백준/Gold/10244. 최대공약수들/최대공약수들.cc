#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n;
int arr[100005];
int visited[105];

int gcd(int a, int b) {
	if (b == 0) return a;
	else {
		return gcd(b, a % b);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);


	while (1) {
		set<int> st;
		memset(arr, 0, sizeof(arr));
		memset(visited, 0, sizeof(visited));
		cin >> n;
		if (!n) break;

		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		
		for (int i = 1; i <= 100; i++) {
			if (visited[i]) continue;
			int tmp = arr[0];

			for (int j = 0; j < n; j++) {
				if (tmp % i) tmp = arr[j];
				else tmp = gcd(tmp, arr[j]);
				st.insert(tmp);
				visited[tmp] = 1;
			}
		}
		
		cout << st.size() << "\n";

	}
	
	return 0;
}

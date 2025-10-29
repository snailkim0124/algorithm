#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int arr[10];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	for (int i = 0; i < 9; i++) {
		cin >> arr[i];
	}

	for (int a = 0; a < 9; a++) {
		for (int b = a + 1; b < 9; b++) {
			for (int c = b + 1; c < 9; c++) {
				for (int d = c + 1; d < 9; d++) {
					for (int e = d + 1; e < 9; e++) {
						for (int f = e + 1; f < 9; f++) {
							for (int g = f + 1; g < 9; g++) {
								if (arr[a] + arr[b] + arr[c] + arr[d] + arr[e] + arr[f] + arr[g] == 100) {
									cout << arr[a] << "\n";
									cout << arr[b] << "\n";
									cout << arr[c] << "\n";
									cout << arr[d] << "\n";
									cout << arr[e] << "\n";
									cout << arr[f] << "\n";
									cout << arr[g] << "\n";
									exit(0);
								}
							} 
						}
					}
				}
			}
		}
	}
	
	
	return 0;
}
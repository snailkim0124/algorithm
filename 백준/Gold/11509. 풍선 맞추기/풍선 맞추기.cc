#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n;
int h[1000005];
int arrows[1000005]; // 화살 개수
int cnt;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }

    for (int i = 0; i < n; i++) {
        if (arrows[h[i] + 1]) {
            arrows[h[i] + 1]--;
            arrows[h[i]]++;
        }
        else {
            cnt++;
            arrows[h[i]]++;
        }
    }

    cout << cnt;

    return 0;
}
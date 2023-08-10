#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <queue>

using namespace std;

int n, m;
long long int a[1000004], pref[1000004], idx[1000004];
long long int ans;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pref[i] = pref[i - 1] + a[i];
    }

    for (int i = 1; i <= n; i++) {
        int tmp = pref[i] % m;
        if (tmp == 0) ans++;

        idx[tmp]++;
    }

    for (int i = 0; i < m; i++) {
        if (idx[i] != 0) {
            ans += idx[i] * (idx[i] - 1) / 2;
        }
    }

    cout << ans;
    return 0;
}

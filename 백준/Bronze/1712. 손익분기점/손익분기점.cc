#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll a, b, c;
ll ans;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> a >> b >> c;
    if (c - b <= 0) {
        cout << -1;
        exit(0);
    }

    ans = a / (c - b);
    cout << ans + 1;


    return 0;
}

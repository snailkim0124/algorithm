#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

ll n;
ll cnt[10];

void go(int now) {
    if (now % 7 == 4) {
        cout << "YES\n";
        exit(0);
    }

    for (int i = 1; i <= 6; i++) {
        if (cnt[i]) {
            cnt[i]--;
            go(now + i);
            cnt[i]++;
        }
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        cnt[num % 7]++;
    }

    go(0);

    cout << "NO\n";

    return 0;
}
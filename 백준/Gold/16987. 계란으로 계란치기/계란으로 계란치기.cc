#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int n;
pii arr[10]; // 내구도, 무게
int mx = 0;

void go(int idx) {
    if (idx == n) {
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i].first <= 0) cnt++;
        }
        // cout << cnt << "\n";

        mx = max(mx, cnt);
        return;
    }

    if (arr[idx].first <= 0) {
        go(idx + 1); // 손에 들고 있는 계란이 부서졌으면
        return;
    }


    bool flag = false;
    for (int i = 0; i < n; i++) {
        if (idx == i) continue;

        if (arr[i].first > 0) {
            flag = true;
            arr[idx].first -= arr[i].second;
            arr[i].first -= arr[idx].second;

            go(idx + 1);

            arr[idx].first += arr[i].second;
            arr[i].first += arr[idx].second;
        }
    }

    if (!flag) go(idx + 1); 

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i].first >> arr[i].second;
    }

    go(0);

    cout << mx << "\n";

    return 0;
}
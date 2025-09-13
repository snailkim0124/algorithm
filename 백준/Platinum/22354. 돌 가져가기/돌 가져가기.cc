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
string s;
ll arr[300005];
vector<ll> v;
ll res;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    cin >> s;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    // 처음과 끝은 없다고 보면 됨
    ll mx = 0;
    for (int i = 1; i < n; i++) {
        if (s[i - 1] != s[i]) {
            v.push_back(mx);
            mx = 0; // 초기화
        }
        mx = max(mx, arr[i]);
    }

    //for (auto it : v) {
    //    cout << it << " ";
    //}
    //cout << "\n";

    sort(all(v), greater<>());


    for (int i = 0; i < v.size() / 2; i++) {
        res += v[i];
    }

    cout << res << "\n";
    

    return 0;
}
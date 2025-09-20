#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

typedef struct OVEN {
    ll a, b, c, d, e, sum;
}OVEN;

ll t;
int visited[65];
OVEN res[65];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    queue<OVEN> q;
    q.push({ 0,0,0,0,0,0 });

    while (!q.empty()) {
        auto [a, b, c, d, e, sum] = q.front();
        q.pop();

        if (sum >= 0 && sum <= 60 && !visited[sum]) {
            visited[sum] = 1;
            res[sum] = { a,b,c,d,e,sum };
            q.push({ a,b,c,d,e + 1,sum - 1 });
            q.push({ a,b,c,d + 1,e,sum + 1 });
            q.push({ a,b,c + 1,d,e,sum - 10 });
            q.push({ a,b + 1,c,d,e,sum + 10 });
            q.push({ a + 1,b,c,d,e,sum + 60 });
        }
    }

    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        int tmp = n / 60;
        n %= 60;
        cout << tmp + res[n].a << " " << res[n].b << " " << res[n].c << " " << res[n].d << " " << res[n].e << "\n";
    }
    

    return 0;
}
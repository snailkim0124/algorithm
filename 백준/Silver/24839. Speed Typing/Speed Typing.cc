#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int X;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> X;

    for (int x = 1; x <= X; x++) {
        
        string I, P;
        int cnt = 0;
        cin >> I >> P;

        for (int i = 0; i < P.size(); i++) {
            if (P[i] == I[cnt]) {
                cnt++;
            }
        }


        cout << "Case #" << x << ": ";
        if (I.size() + (P.size() - cnt) == P.size()) cout << P.size() - cnt << "\n";
        else cout << "IMPOSSIBLE\n";
    }


    return 0;
}
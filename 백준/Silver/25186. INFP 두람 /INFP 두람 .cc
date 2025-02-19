#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


int n;
ull arr[100005];
ull sum;
ull mx;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
        mx = max(mx, arr[i]);
    }

    if (n == 1 && arr[0] == 1) cout << "Happy";
    else if (2 * mx <= sum) {
        cout << "Happy";
    }
    else cout << "Unhappy";

    
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n, a, b;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n >> a >> b;
    if (a < b) cout << "Bus";
    else if (a > b) cout << "Subway";
    else cout << "Anything";
    
    return 0;
}
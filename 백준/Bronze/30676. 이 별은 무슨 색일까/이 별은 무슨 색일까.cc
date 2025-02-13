#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    if (n >= 620) cout << "Red";
    else if (n >= 590) cout << "Orange";
    else if (n >= 570) cout << "Yellow";
    else if (n >= 495) cout << "Green";
    else if (n >= 450) cout << "Blue";
    else if (n >= 425) cout << "Indigo";
    else cout << "Violet";
    
    return 0;
}
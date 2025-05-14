#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int a, b;
bool win1, win2;

bool draw(int num) {
    return (num == 0 || num == 2 || num == 5);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> a >> b;
    win1 = draw(a);
    win2 = draw(b);

    if (win1 && win2) {
        if (a == b) cout << "=";
        else if (a == 0 && b == 2) cout << ">";
        else if (a == 0 && b == 5) cout << "<";
        else if (a == 2 && b == 5) cout << ">";
        else if (a == 2 && b == 0) cout << "<";
        else if (a == 5 && b == 0) cout << ">";
        else if (a == 5 && b == 2) cout << "<";
    }
    else if (!win1 && !win2) cout << "=";
    else cout << (win1 ? ">" : "<");
    
    
    return 0;
}
#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int n, origin;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    origin = n;

    while (1) {
        if (n == 1) {
            cout << n << " bottle of beer on the wall, " << n << " bottle of beer.\n";
        }
        else if (n == 0) {
            cout << "No more" << " bottles of beer on the wall, " << "no more" << " bottles of beer.\n";
        }
        else {
            cout << n << " bottles of beer on the wall, " << n << " bottles of beer.\n";
        }

        if (n == 1) {
            cout << "Take one down and pass it around, " << "no more" << " bottles of beer on the wall.\n";
        }
        else if (n == 0) {
            if (origin == 1) {
                cout << "Go to the store and buy some more, " << origin << " bottle of beer on the wall.\n";
            }
            else {
                cout << "Go to the store and buy some more, " << origin << " bottles of beer on the wall.\n";
            }
            break;
        }
        else if (n == 2) {
            cout << "Take one down and pass it around, " << n - 1 << " bottle of beer on the wall.\n";
        }
        else {
            cout << "Take one down and pass it around, " << n - 1 << " bottles of beer on the wall.\n";
        }
        
        cout << "\n";

        n--;
    }
    

    return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    while (1) {
        double speed;
        int weight, strength;
        bool flag = false;
        cin >> speed >> weight >> strength;
        if (!speed && !weight && !strength) break;

        if (speed <= 4.5 && weight >= 150 && strength >= 200) {
            cout << "Wide Receiver ";
            flag = true;
        }

        if (speed <= 6.0 && weight >= 300 && strength >= 500) {
            cout << "Lineman ";
            flag = true;
        }

        if (speed <= 5.0 && weight >= 200 && strength >= 300) {
            cout << "Quarterback ";
            flag = true;
        }
        
        if(!flag) cout << "No positions";
        cout << "\n";
    }
    return 0;
}
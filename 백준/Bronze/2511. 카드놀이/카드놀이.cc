#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int arr[15];
int brr[15];
int a, b;
char lst = 'D';

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    for (int i = 0; i < 10; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < 10; i++) {
        cin >> brr[i];
    }

    for (int i = 0; i < 10; i++) {
        if (arr[i] > brr[i]) {
            a += 3; lst = 'A';
        }
        else if (arr[i] < brr[i]) {
            b += 3; lst = 'B';
        }
        else {
            a++; b++;
        }
    }

    cout << a << " " << b << "\n";
    if (a > b) cout << "A";
    else if (a == b) cout << lst;
    else cout << "B";
    
    
    return 0;
}
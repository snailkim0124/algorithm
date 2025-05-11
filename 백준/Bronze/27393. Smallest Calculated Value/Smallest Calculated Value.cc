#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int arr[5];
vector<int> v, tmp, tmp2;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    for (int i = 0; i < 3; i++) {
        int num;
        cin >> num;
        v.push_back(num);
    }
    
    tmp.push_back(v[0] + v[1]);
    tmp.push_back(v[0] - v[1]);
    tmp.push_back(v[0] * v[1]);
    if(v[0] % v[1] == 0) tmp.push_back(v[0] / v[1]);

    for (int i = 0; i < tmp.size(); i++) {
        tmp2.push_back(tmp[i] + v[2]);
        tmp2.push_back(tmp[i] - v[2]);
        tmp2.push_back(tmp[i] * v[2]);
        if(tmp[i] % v[2] == 0) tmp2.push_back(tmp[i] / v[2]);
    }

    sort(tmp2.begin(), tmp2.end());

    for (auto it : tmp2) {
        if (it >= 0) {
            cout << it;
            break;
        }
    }


    return 0;
}
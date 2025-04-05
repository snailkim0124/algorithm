#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

string a, b;
int alcnt[30] = {3, 2, 1, 2, 3, 3, 2, 3, 3, 2, 2, 1, 2, 2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1};
vector<int> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> a >> b;

    for(int i = 0; i < a.size(); i++) {
        int cnt_a = alcnt[a[i] - 'A'];
        int cnt_b = alcnt[b[i] - 'A'];

        v.push_back(cnt_a);
        v.push_back(cnt_b);
    }

    while (v.size() > 2) {
        vector<int> tmp;
        for (int i = 0; i < v.size() - 1; i++) {
            int cnt_tmp = v[i] + v[i + 1];
            if (cnt_tmp >= 10) cnt_tmp -= 10;
            tmp.push_back(cnt_tmp);
        }

        v = tmp;
    }

    for (auto it : v) {
        cout << it;
    }
    

    return 0;
}
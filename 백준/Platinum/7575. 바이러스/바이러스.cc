#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

vector<int> v[105];
int n, k;
bool ans;

vector<int> failure(vector<int>& p) {
    vector<int> f(p.size());
    int j = 0;

    for (int i = 1; i < p.size(); i++) {
        while (j > 0 && p[i] != p[j]) j = f[j - 1];
        if (p[i] == p[j]) f[i] = ++j;
    }

    return f;
}

bool kmp(vector<int>& t, vector<int>& p) {
    vector<int> f = failure(p);
    int j = 0;

    for (int i = 0; i < t.size(); i++) {
        while (j > 0 && t[i] != p[j]) j = f[j - 1];
        if (t[i] == p[j]) {
            if (j == p.size() - 1) {
                return true;
            }
            else j++;
        }
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        int sz;
        cin >> sz;
        for (int j = 0; j < sz; j++) {
            int num;
            cin >> num;
            v[i].push_back(num);
        }
    }

    for (int i = 0; i < v[0].size() - k + 1; i++) {
        vector<int> subv(v[0].begin() + i, v[0].begin() + i + k);
        bool check = true;

        for (int j = 1; j < n; j++) {
            vector<int> rev_subv = subv;
            reverse(all(rev_subv));

            if (!kmp(v[j], subv) && !kmp(v[j], rev_subv)) {
                check = false;
                break;
            }
        }

        if (check) {
            cout << "YES\n";
            exit(0);
        }
    }
    
    cout << "NO\n";

    return 0;
}
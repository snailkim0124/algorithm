#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n;
vector<pair<string, int>> v, tmp;
stack<pair<string, int>> st;
queue<pair<string, int>> q;

int main() {
    ios::sync_with_stdio(false);
    cout.tie(NULL); cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 5; j++) {
            string s;
            cin >> s;
            string c = s.substr(0, 1);
            int num = stoi(s.substr(2));
            q.push({ c, num });
            v.push_back({ c, num });
        }
    }

    tmp = v;

    sort(tmp.begin(), tmp.end());
    int idx = 0;

    while (!q.empty()) {
        bool check = false;
        if (q.front() == tmp[idx]) {
            q.pop();
            idx++;
            check = true;
        }
        while (!st.empty()) {
            if (st.top() == tmp[idx]) {
                st.pop();
                idx++;
                check = true;
            }
            else break;
        }

        if (!check) {
            st.push(q.front());
            q.pop();
        }
    }


    //for (auto it : tmp) {
    //    cout << it.first << " : " << it.second << "\n";
    //}

    //cout << "q_remain : \n";
    //while (!q.empty()) {
    //    cout << q.front().first << " : " << q.front().second << "\n";
    //    q.pop();
    //}

    //cout << "st_remain : \n";
    //while (!st.empty()) {
    //    cout << st.top().first << " : " << st.top().second << "\n";
    //    st.pop();
    //}

    cout << (st.empty() ? "GOOD" : "BAD");

    return 0;
}
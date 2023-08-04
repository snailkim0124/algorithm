#include <iostream>
#include <algorithm>
#include <stack>
#include <deque>

using namespace std;

deque<int> st;
int n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        if (num == 1) {
            int x;
            cin >> x;
            st.push_front(x);
        }
        else if (num == 2) {
            int x;
            cin >> x;
            st.push_back(x);
        }
        else if (num == 3) {
            if (!st.empty()) {
                cout << st.front()<<"\n";
                st.pop_front();
            }
            else cout << -1 << "\n";
        }
        else if (num == 4) {
            if (!st.empty()) {
                cout << st.back() << "\n";
                st.pop_back();
            }
            else cout << -1 << "\n";
        }
        else if (num == 5) {
            cout << st.size() <<"\n";
        }
        else if (num == 6) {
            cout << st.empty() <<"\n";
        }
        else if (num == 7) {
            if (!st.empty()) {
                cout << st.front() << "\n";
            }
            else cout << -1 << "\n";
        }
        else if (num == 8) {
            if (!st.empty()) {
                cout << st.back() << "\n";
            }
            else cout << -1 << "\n";
        }
    }
    return 0;
}
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

stack<int> st;
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
            st.push(x);
        }
        else if (num == 2) {
            if (!st.empty()) {
                cout << st.top()<<"\n";
                st.pop();
            }
            else cout << -1<<"\n";
        }
        else if (num == 3) {
            cout << st.size() <<"\n";
        }
        else if (num == 4) {
            cout << st.empty() <<"\n";
        }
        else if (num == 5) {
            if (!st.empty()) {
                cout << st.top() << "\n";
            }
            else cout << -1 << "\n";
        }
    }
    return 0;
}
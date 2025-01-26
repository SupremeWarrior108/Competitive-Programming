#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

void proc() {
    int n;
    cin >> n;

    auto calc = [](int n) {
        int res = 0; 
        vector<int> pow2;
        vector<int> others;

        for (int i = 3; i <= n; ++i) {
            if (((i + 1) & i) == 0 || (i & (i - 1)) == 0) {
                pow2.push_back(i);
            } else {
                others.push_back(i);
            }
        }

        vector<int> lst = {2, 1}; 
        lst.insert(lst.end(), others.begin(), others.end());
        lst.insert(lst.end(), pow2.begin(), pow2.end());

        for (int j = 0; j < n; ++j) {
            if (j % 2 == 0) {
                res = res & lst[j];
            } else {
                res = res | lst[j];
            }
        }
        return make_pair(res, lst);
    };

    if (n % 2 == 1) {
        auto [res, lst] = calc(n - 1);
        lst.push_back(n); 
        cout << n << endl;

        for (int v : lst) {
            cout << v << " ";
        }
        cout << endl;
        return;
    }

    auto [res, lst] = calc(n);
    cout << res << endl;

    for (int v : lst) {
        cout << v << " ";
    }
    cout << endl;
}

int main() {
    int t;  // Number of test cases
    cin >> t;
    while (t--) {
        proc();
    }
    return 0;
}

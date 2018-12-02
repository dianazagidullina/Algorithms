#include <iostream>
#include <vector>
#include <deque>
#include <map>
#include <algorithm>
#include <string>
using namespace std;

int main() {
#pragma warning(disable :4996)
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1, 0);
    vector<int> c(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }
    vector<int> d1(m + 1, 0);
    vector<vector<int>> d(n + 1, d1);
    for (int k = 1; k <= n; k++) {
        for (int s = 1; s <= m; s++) {
            d[k][s] = d[k - 1][s];
            if (s - a[k] >= 0) {
                if (d[k][s] < d[k - 1][s - a[k]] + c[k]) {
                    d[k][s] = d[k - 1][s - a[k]] + c[k];
                }
            }
        }
    }
    vector<int> ans;
    int s = m;
    for (int k = n; k >= 1; k--) {
        if (d[k][s] != d[k - 1][s]) {
            ans.push_back(k);
            s -= a[k];
        }
    }
    for (int i = ans.size() - 1; i >= 0; i--) {
        cout << ans[i] << endl;
    }
    return 0;
}
#include <iostream>
#include <vector>
#include <deque>
#include <map>
#include <algorithm>
#include <string>
using namespace std;

long long m, n;
int main() {
#pragma warning(disable :4996)
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> v(n);
    for (int i = 0; i < m; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        v[x - 1].push_back(make_pair(y - 1, w));
        v[y - 1].push_back(make_pair(x - 1, w));
    }
    map<int, bool> used;
    used[0] = 1;
    int ans = 0;
    for (int k = 0; k < n - 1; k++) {
        int weight = 1e9;
        int ver;
        int i = 0;
        for (int i = 0; i < n; i++) {
            if (used[i]) {
                for (int j = 0; j < v[i].size(); j++) {
                    if (!used[v[i][j].first]) {
                        if (v[i][j].second < weight) {
                            weight = v[i][j].second;
                            ver = v[i][j].first;
                        }
                    }
                }
            }
        }
        ans += weight;
        used[ver] = 1;
    }
    cout << ans;
    return 0;
}
#include <iostream>
#include <vector>
#include <cstdio>
#include <ctime>
#include <algorithm>
#include <map>
using namespace std;
int t = 0;
map<int, int> res;
void dfs(vector<vector<pair<int, int>>>& v, vector<bool>& used, int u, vector<int>& t_in,
         vector<int>& f, int pred, int root) {
    t_in[u] = t;
    f[u] = t;
    t++;
    used[u] = 1;
    int amount = 0;
    for (int i = 0; i < v[u].size(); i++) {
        if (v[u][i].second == pred) continue;
        if (!used[v[u][i].first]) {
            amount++;
            dfs(v, used, v[u][i].first, t_in, f, v[u][i].second, root);
            f[u] = min(f[u], f[v[u][i].first]);
            if (u != root && f[v[u][i].first] >= t_in[u]) {
                res[u] = 1;
            }
        } else {
            f[u] = min(f[u], t_in[v[u][i].first]);
        }
    }
    if (u == root && amount > 1) {
        res[u] = 1;
    }
    return;
}
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
        int v1, v2;
        cin >> v1 >> v2;
        v1--;
        v2--;
        v[v1].push_back(make_pair(v2, i));
        v[v2].push_back(make_pair(v1, i));
    }
    vector<bool> used(n, 0);
    vector<int> t_in(n, 1e6);
    vector<int> f(n, 1e6);
    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            dfs(v, used, i, t_in, f, -1, i);
        }
    }
    cout << res.size() << endl;
    for (auto it = res.begin(); it != res.end(); it++) {
        cout << it->first + 1<< endl;
    }
    return 0;
}
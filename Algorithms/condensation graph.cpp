#include <iostream>
#include <vector>
#include <cstdio>
#include <ctime>
#include <algorithm>

using namespace std;
void dfs_for_time(vector<vector<int>> &v, vector<bool> &used, vector<int>& t_out, int u) {
    used[u] = 1;
    for (int i = 0; i < v[u].size(); i++) {
        if (!used[v[u][i]]) {
            dfs_for_time(v, used, t_out, v[u][i]);
        }
    }
    t_out.push_back(u);
    return;
}
void dfs(vector<vector<int>> &v, vector<bool> &used, vector<pair<int, int>>& comp, int num, int u) {
    used[u] = 1;
    comp.push_back(make_pair(u, num));
    for (int i = 0; i < v[u].size(); i++) {
        if (!used[v[u][i]]) {
            dfs(v, used, comp, num, v[u][i]);
        }
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
    vector<vector<int>> v(n), vT(n);
    for (int i = 0; i < m; i++) {
        int v1, v2;
        cin >> v1 >> v2;
        v1--;
        v2--;
        v[v1].push_back(v2);
        vT[v2].push_back(v1);
    }
    vector<bool> used(n, 0);
    vector<int> t_out;
    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            dfs_for_time(v, used, t_out, i);
        }
    }
    for (int i = 0; i < n; i++) {
        used[i] = 0;
    }
    int amount = 0;
    vector<pair<int, int>> comp;
    int k = t_out.size() - 1;
    while (comp.size() != n) {
        while (used[t_out[k]]) {
            k--;
        }
        amount++;
        dfs(vT, used, comp, amount, t_out[k]);
    }
    cout << amount << endl;
    sort(comp.begin(), comp.end());
    for (int i = 0; i < n; i++) {
        cout << comp[i].second << " ";
    }
    return 0;
}
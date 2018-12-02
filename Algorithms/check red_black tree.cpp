#include<algorithm>
#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<string>
using namespace std;
struct Tree {
    int key;
    int left;
    int right;
    string colour;
};
int find_max(vector<Tree> &v, int x) {
    while (v[x].right != -1) {
        x = v[x].right;
    }
    return v[x].key;
}
int find_min(vector<Tree> &v, int x) {
    while (v[x].left != -1) {
        x = v[x].left;
    }
    return v[x].key;
}

bool if_binary_tree(vector<Tree> &v, int x) {
    if (v.size() == 0) {
        return 1;
    }
    if (v[x].left != -1) {
        if (find_max(v, v[x].left) >= v[x].key) return 0;
        if (!if_binary_tree(v, v[x].left)) return 0;
    }
    if (v[x].right != -1) {
        if (find_min(v, v[x].right) <= v[x].key) return 0;
        if (!if_binary_tree(v, v[x].right)) return 0;
    }
    return 1;
}
bool if_red_child_have_black_parent(vector<Tree> &v, int x) {
    if (v.size() == 0) {
        return 1;
    }
    if (v[x].left != -1) {
        if (v[x].colour == "R") {
            if (v[v[x].left].colour == "R") return 0;
        }
        if (!if_red_child_have_black_parent(v, v[x].left)) {
            return 0;
        }
    }
    if (v[x].right != -1) {
        if (v[x].colour == "R") {
            if (v[v[x].right].colour == "R") return 0;
        }
        if (!if_red_child_have_black_parent(v, v[x].right)) {
            return 0;
        }
    }
    return 1;
}
int dfs(vector<Tree>& v, int x) {
    if (v.size() == 0) {
        return 0;
    }
    int l = 0, r = 0;
    if (v[x].left != -1) {
        l = dfs(v, v[x].left);
        if (l == -1) return l;
    }
    if (v[x].right != -1) {
        r = dfs(v, v[x].right);
        if (r == -1) return r;
    }
    if (v[x].left == -1 && v[x].right == -1) {
        if (v[x].colour == "B") {
            return 1;
        } else {
            return 0;
        }
    }
    if (l != r) return -1;
    if (v[x].colour == "B") return l + 1;
    return l;
}
int main() {
#pragma warning(disable :4996)
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, root;
    cin >> n;
    if (n == 0) {
        cout << "YES";
        return 0;
    }
    cin >> root;
    root--;
    vector<Tree> v(n);
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        num--;
        cin >> v[num].key;

        string left;
        cin >> left;
        if (left == "null") {
            v[num].left = -1;
        } else {
            v[num].left = stoi(left) - 1;
        }

        string right;
        cin >> right;
        if (right == "null") {
            v[num].right = -1;
        } else {
            v[num].right = stoi(right) - 1;
        }

        cin >> v[num].colour;
    }
    bool if_red_black_tree = 1;
    if (v[root].colour == "R") if_red_black_tree = 0;
    if (!if_binary_tree(v, root)) if_red_black_tree = 0;
    if (!if_red_child_have_black_parent) if_red_black_tree = 0;
    if (dfs(v, 0) == -1) if_red_black_tree = 0;
    if (if_red_black_tree) {
        cout << "YES";
    } else {
        cout << "NO";
    }
}
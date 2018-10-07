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
    int parent;
};
void add_elem(vector<Tree>& v, int num) {
    if (num != 0) {
        int cur = 0;
        bool if_insert = 0;
        while (!if_insert) {
            if (v[num].key > v[cur].key) {
                if (v[cur].right == -1) {
                    v[cur].right = num;
                    v[num].parent = cur;
                    break;
                } else {
                    cur = v[cur].right;
                }
            } else {
                if (v[num].key < v[cur].key) {
                    if (v[cur].left == -1) {
                        v[cur].left = num;
                        v[num].parent = cur;
                        break;
                    } else {
                        cur = v[cur].left;
                    }
                } else {
                    return;
                }
            }
        }
    }
}
int height(vector<Tree> &v, int x) {
    if (x == 0 || x == -1) {
        return 0;
    }
    int cur_h = 1;
    if (v[x].left != -1) {
        cur_h = max(cur_h, height(v, v[x].left) + 1);
    }
    if (v[x].right != -1) {
        cur_h = max(cur_h, height(v, v[x].right) + 1);
    }
    return cur_h;
}

int find_second_max(vector<Tree> v, int x) {
    while (v[x].right != -1) {
        x = v[x].right;
    }
    if (v[x].left == -1) {
        return v[v[x].parent].key;
    }
    x = v[x].left;
    while (v[x].right != -1) {
        x = v[x].right;
    }
    return v[x].key;
}
void dfs(vector<Tree>& v, int x) {
    if (v.size() == 0) {
        return;
    }
    if (v[x].left != -1) {
        dfs(v, v[x].left);
    }
    if ((v[x].left != -1 && v[x].right == -1)
        || (v[x].left == -1 && v[x].right != -1)) {
        cout << v[x].key << endl;
    }
    if (v[x].right != -1) {
        dfs(v, v[x].right);
    }
}

int if_balanced(vector<Tree> &v, int x) {
    if (v.size() == 0) {
        return 1;
    }
    if (v[x].left != -1) {
        if (!if_balanced(v, v[x].left)) return 0;
    }
    if (v[x].right != -1) {
        if (!if_balanced(v, v[x].right)) return 0;
    }
    if (abs(height(v, v[x].right) - height(v, v[x].left)) > 1) {
        return 0;
    } else {
        return 1;
    }
}
int main() {
#pragma warning(disable :4996)
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int x;
    cin >> x;
    vector<Tree> v;
    while (x != 0) {
        Tree elem;
        elem.left = -1;
        elem.right = -1;
        elem.parent = -1;
        elem.key = x;
        v.push_back(elem);
        add_elem(v, v.size() - 1);
        cin >> x;
    }
    int if_balanc = if_balanced(v, 0);
    if (if_balanc) {
        cout << "YES";
    } else {
        cout << "NO";
    }
}
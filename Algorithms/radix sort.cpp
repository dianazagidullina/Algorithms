#include<algorithm>
#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<string>

using namespace std;

int main() {
#pragma warning(disable :4996)
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<string> v(n);
    string s;
    getline(cin, s);
    for (int i = 0; i < n; i++) {
        getline(cin, v[i]);
    }
    cout << "Initial array:" << endl;
    for (int i = 0; i < n; i++) {
        cout << v[i];
        if (i != n - 1) {
            cout << ", ";
        } else {
            cout << endl;
        }
    }
    cout << "**********" << endl;
    int m = v[0].size();
    for (int i = 0; i < m; i++) {
        cout << "Phase " << i + 1 << endl;
        vector<vector<string>> basket(10);
        for (int j = 0; j < n; j++) {
            int el = v[j][m - 1 - i] - '0';
            basket[el].push_back(v[j]);
        }
        int numb = 0;
        for (int j = 0; j < 10; j++) {
            cout << "Bucket " << j << ": ";
            if (basket[j].size() == 0) {
                cout << "empty" << endl;
            } else {
                for (int k = 0; k < basket[j].size(); k++) {
                    cout << basket[j][k];
                    v[numb] = basket[j][k];
                    numb++;
                    if (k != basket[j].size() - 1) {
                        cout << ", ";
                    } else {
                        cout << endl;
                    }
                }
            }
        }
        cout << "**********" << endl;
    }
    cout << "Sorted array:" << endl;
    for (int i = 0; i < n; i++) {
        cout << v[i];
        if (i != n - 1) {
            cout << ", ";
        } else {
            cout << endl;
        }
    }
}
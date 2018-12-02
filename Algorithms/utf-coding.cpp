#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<stdio.h>
using namespace std;
int binary(int x) {
    int ans = 0;
    while (x > 0) {
        ans++;
        x = x >> 1;
    }
    return ans;
}
int main() {
#pragma warning(disable: 4996)
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int x;
    vector<int> v;
    while (cin >> x) {
        v.push_back(x);
    }
    string ans;
    for (size_t i = 0; i < v.size(); ++i) {
        x = v[i];
        int deg = binary(x);
        if (x <= 127) {
            ans += x;
        } else {
            int num = 1;
            vector<int> vv;
            while (deg + num + 1 > 8) {
                vv.push_back((((1 << 6) - 1) & x)|(1 << 7));
                deg -= 6;
                num++;
                x = x >> 6;
            }
            vv.push_back((((1 << num) - 1) << (8 - num)) | x);
            for (int i = vv.size() - 1; i >= 0; --i) {
                ans += vv[i];
            }
        }
    }
    cout << ans;
    return 0;
}

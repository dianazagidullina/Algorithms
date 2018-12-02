#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <deque>
#include <cstdlib>
#include <ctime>

using  namespace std;

void quick_sort(vector<int>& v, int begin, int end) {
    int pred = (v[begin] + v[end]) / 2;
    int l = begin;
    int r = end;
    while (l <= r) {
        while (v[l] < pred) {
            l++;
        }
        while (v[r] > pred) {
            r--;
        }
        if (l <= r) {
            swap(v[l], v[r]);
            l++;
            r--;
        }
    }
    if (begin < r) {
        quick_sort(v, begin, r);
    }
    if (end > l) {
        quick_sort(v, l, end);
    }
}
int main() {
#pragma warning(disable :4996)
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    if (v.size() > 1) {
        quick_sort(v, 0, v.size() - 1);
    }
    for (int i = 0; i < n; i++) {
        cout << v[i] << " ";
    }
}
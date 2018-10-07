#include <iostream>
#include <memory>
#include <string>
#include <vector>

using  namespace std;
template <typename Iter>
void merge(Iter begin1, Iter end1, Iter begin2, Iter end2, Iter it3) {
    while (begin1 != end1 && begin2 != end2) {
        if (*(begin1) < *(begin2)) {
            *(it3++) = *(begin1++);
        } else {
            *(it3++) = *(begin2++);
        }
    }
    while (begin1 != end1) {
        *(it3++) = *(begin1++);
    }
    while (begin2 != end2) {
        *(it3++) = *(begin2++);
    }
}


template <typename Iter>
void sort_merge(Iter begin, Iter end, Iter it3) {
    if (begin != end) {
        int n = end - begin;
        vector<int> v(n);
        if (n != 1) {
            sort_merge(begin, begin + n/2, v.begin());
            sort_merge(begin + n/2, end, v.begin() + n/2);
            merge(v.begin(), v.begin() + n/2, v.begin() + n/2, v.end(), it3);
        } else {
            (*it3) = (*begin);
        }
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
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort_merge(v.begin(), v.end(), ans.begin());
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
}
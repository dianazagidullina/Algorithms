#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <cmath>

using  namespace std;
long long int distance(vector<long long int>& v1, vector<long long int>& v2) {
    return (v1[0]-v2[0]) * (v1[0]-v2[0])
        + (v1[1]-v2[1]) * (v1[1]-v2[1]);
}
long long int min_dist(vector<vector<long long int>>& v, int begin, int end) {
    if (end - begin == 1) {
        auto it = v.begin();
        sort(it + begin, it + end, [](vector<long long int> v1, vector<long long int> v2) {
            return v1[1] < v2[1];
        });
        return distance(v[begin], v[end]);
    }
    if (end - begin == 2) {
        auto it = v.begin();
        sort(it + begin, it + end, [](vector<long long int> v1, vector<long long int> v2) {
            return v1[1] < v2[1];
        });
        long long int dist;
        dist = distance(v[begin], v[end]);
        dist = min(dist, distance(v[begin], v[end - 1]));
        dist = min(dist, distance(v[end], v[end - 1]));
        return dist;
    }
    int m = (begin + end) / 2;
    long long int h1 = min_dist(v, begin, m);
    long long int h2 = min_dist(v, m + 1, end);
    long long int h = min(h1, h2);
    vector<vector<long long int>> v1(end - begin + 1);
    merge(v.begin() + begin, v.begin() + m + 1, v.begin() + m + 1,
        v.begin() + end + 1, v1.begin(), [](vector<long long int> v1, vector<long long int> v2) {
            return v1[1] < v2[1];
        });
    copy(v1.begin(), v1.begin() + (end - begin) + 1, v.begin() + begin);
    /*vector<vector<long long int>> v_new;
    for (int i = begin; i <= end; i++) {
        if (abs(v[m][0] - v[i][0]) < static_cast<long long>(sqrt(h)) + 1) {
            v_new.push_back(v[i]);
        }
    }

    long long int ans = h;
    for (int i = 0; i < v_new.size(); i++) {
        int j = i + 1;
        while (j < v_new.size() && v_new[j][1] - v_new[i][1] <
               static_cast<long long>(sqrt(h)) + 1) {
            ans = min(ans, distance(v_new[j], v_new[i]));
            j++;
        }
    }*/
    int v1_size = 0;
    for (int i = begin; i <= end; ++i) {
        if (abs(v[m][0] - v[i][0]) < h + 1) {
            for (int j = v1_size - 1;
                 j >= 0 && v[i][1] - v1[j][1] < h; --j) {
                h = min(h, distance(v1[j], v[i]));
            }
            v1[v1_size++] = v[i];
        }
    }
    return h;
}

int main() {
#pragma warning(disable :4996)
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<long long int> w(2);
    vector<vector<long long int>> v(n, w);
    for (int i = 0; i < n; i++) {
        cin >> v[i][0] >> v[i][1];
    }
    sort(v.begin(), v.end());
    long long int ans = min_dist(v, 0, n - 1);
    cout.precision(11);
    cout << sqrt(ans);
}
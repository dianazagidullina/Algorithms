#include<algorithm>
#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<string>


using namespace std;
void Insert(vector<int>& h, int& Heap_size, int x) {
    h.push_back(x);
    Heap_size++;
    int i = Heap_size;
    int parent = i / 2;
    while (parent > 0 && h[parent] < h[i]) {
        swap(h[i], h[parent]);
        i = parent;
        parent = i / 2;
    }
}

void Heapify_down(vector<int>& h, int& Heap_size, int i) {
    int l = 2 * i;
    int r = 2 * i + 1;
    if (l <= Heap_size) {
        if (r > Heap_size) {
            if (h[l] > h[i]) {
                swap(h[l], h[i]);
                Heapify_down(h, Heap_size, l);
            }
        } else {
            int m = max(h[i], max(h[l], h[r]));
            if (m > h[i]) {
                if (h[l] > h[r]) {
                    swap(h[l], h[i]);
                    Heapify_down(h, Heap_size, l);
                } else {
                    swap(h[r], h[i]);
                    Heapify_down(h, Heap_size, r);
                }
            }
        }
    }
}
int Extract(vector<int>& h, int& Heap_size) {
    int m = h[1];
    Heap_size--;
    if (Heap_size > 0) {
        h[1] = h[Heap_size + 1];
        h.pop_back();
        Heapify_down(h, Heap_size, 1);
    } else {
        h.pop_back();
    }

    return m;
}
int main() {
#pragma warning(disable :4996)
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<int> h;
    h.push_back(0);
    int Heap_size = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        Insert(h, Heap_size, x);
    }
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        ans.push_back(Extract(h, Heap_size));
    }
    for (int i = ans.size() - 1; i >= 0; i--) {
        cout << ans[i] << " ";
    }
}
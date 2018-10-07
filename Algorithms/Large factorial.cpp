#include <iostream>
#include <math.h>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <stdio.h>
using namespace std;
void writelong(vector<int> & a) {
    int i = a[0];
    cout << a[i];
    i--;
    while (i >= 1){
        printf("%.4d", a[i]);
        i--;
    }
    return ;
}
void proizv(vector<int> & a, int n) {
    int ost = 0;
    for (int i = 1; i <= a[0]; i++){
        int m = a[i] * n + ost;
        a[i] = m % 10000;
        ost = m / 10000;
    }

    while (ost > 0){
        a[0]++;
        a.push_back(0);
        a[a[0]] = ost % 10000;
        ost = ost / 10000;     
    }
    return;
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector <int> a(2);
    a[0] = 1;
    a[1] = 1;
    int n;
    cin >> n;
    if (n == 0) {
        cout << 1;
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        proizv(a, i);
    }
    writelong(a);
    return 0;
}
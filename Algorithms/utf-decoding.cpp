#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
#include <bitset>
using namespace std;
string need_symbols(bitset<8> &bits, int amount) {
    string ans;
    for (int i = amount; i >= 0; --i) {
        ans += to_string(bits[i]);
    }
    return ans;
}
string sum_numbers(vector <bitset<8>> numbers) {
    string ans;
    if (numbers.size() == 1)
        ans += need_symbols(numbers[0], 6);
    if (numbers.size() == 2)
        ans += need_symbols(numbers[0], 4);
    if (numbers.size() == 3)
        ans += need_symbols(numbers[0], 3);
    if (numbers.size() == 4)
        ans += need_symbols(numbers[0], 2);
    for (size_t i = 1; i < numbers.size(); ++i) {
        ans += need_symbols(numbers[i], 5);
    }
    return ans;
}
int main() {
    string s;
    getline(cin, s);
    auto i = 0;
    while (i < s.size()) {
        int amount_of_bytes;
        bitset<8> sym(s[i]);
        if (sym[7] == 0)
            amount_of_bytes = 1;
        if (sym[7] == 1 && sym[6] == 1 && sym[5] == 0)
            amount_of_bytes = 2;
        if (sym[7] == 1 && sym[6] == 1 && sym[5] == 1 && sym[4] == 0)
            amount_of_bytes = 3;
        if (sym[7] == 1 && sym[6] == 1 && sym[5] == 1 && sym[4] == 1 && sym[3] == 0)
            amount_of_bytes = 4;
        vector <bitset<8>> numbers;
        for (size_t j = 0; j < amount_of_bytes; ++j) {
            bitset<8> num(s[i + j]);
            numbers.push_back(num);
        }
        string binary_number = sum_numbers(numbers);
        bitset<32> ans;
        for (int j = 0; j <= binary_number.size() - 1; j++) {
            string bin;
            bin += binary_number[j];
            ans[binary_number.size() - 1 - j] = std::stoi(bin);
        }
        cout << ans.to_ullong() << " ";
        i += amount_of_bytes;
    }
    return 0;
}
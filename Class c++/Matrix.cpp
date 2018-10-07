#include<algorithm>
#include<iostream>
#include<cstdio>
#include<math.h>
#include<vector>
#include<string>
#include<stdio.h>
using namespace std;

template<typename T>
class Matrix {
private:
    vector<T> matrix;
    int lines;
    int columns;

public:
    Matrix<T>(const vector<vector<T>>& V) {
        lines = V.size();
        columns = V[0].size();
        for (int i = 0 ; i < lines; ++i) {
            for (int j = 0 ; j < columns; ++j) {
                matrix.push_back(V[i][j]);
            }
        }
    }

    friend ostream& operator<<(ostream& out, const Matrix<T>& m) {
        for (int i = 0 ; i < m.lines; ++i) {
            for (int j = 0 ; j < m.columns; ++j) {
                if (j + 1 != m.columns) {
                    out << m.matrix[i * m.columns + j] << '\t';
                } else {
                    out << m.matrix[i * m.columns + j];
                }
            }
            if (i + 1 != m.lines) {
                out << '\n';
            }
        }
        return out;
    }
    pair<size_t, size_t> size() const {
        return make_pair(lines, columns);
    }
};

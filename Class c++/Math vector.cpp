#include <iostream>
#include <vector>
using namespace std;
template <typename T>
class MathVector {
 private:
    std::vector<T> data;

 public:
    // Zero vector of size n
    MathVector(size_t n) {
        data.resize(n);
    }

    template <typename Iter>
    MathVector(Iter first, Iter last) {
        while (first != last) {
            data.push_back(*first);
            first++;
        }
    }

    size_t Dimension() const {
         return data.size();
    }

    T& operator[] (size_t i) {
        return data[i];
    }

    const T& operator[] (size_t i) const {
        return data[i];
    }

    MathVector<T>& operator += (const MathVector<T> &v) {
        for (int i = 0; i < data.size(); ++i) {
            data[i] += v.data[i];
        }
        return *this;
    }


    MathVector<T>& operator *= (const T& scalar) {
        for (size_t i = 0; i != data.size(); ++i)
            data[i] *= scalar;
        return *this;
    }
};
template <typename T>
MathVector<T> operator + (MathVector<T> v1, const MathVector<T> &v) {
    return v1 += v;
}

// Output format: (1, 2, 3, 4, 5)
template <typename T>
std::ostream& operator << (std::ostream& out, const MathVector<T>& v) {
    out << '(';
    for (size_t i = 0; i != v.Dimension(); ++i) {
        if (i > 0)
            out << ", ";
        out << v[i];
    }
    out << ')';
    return out;
}

template <typename T>
MathVector<T> operator * (MathVector<T> v, const T& scalar) {
    return v *= scalar;
}

template <typename T>
MathVector<T> operator * (const T& scalar, MathVector<T> v) {
    return v *= scalar;
}
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

template<typename T>
class Polynomial {
private:
    vector<T> polynom;
    void normalize() {
        while (polynom.size() > 0 && polynom.back() == T(0)) {
            polynom.pop_back();
        }
    }
public:
    Polynomial(const vector<T>& v) : polynom(v) {
        normalize();
    }

    Polynomial(const T& coef = T()) {
        polynom.clear();
        polynom.push_back(coef);
        normalize();
    }

    template <typename Iter>
    Polynomial<T>(Iter begin, Iter end) {
        polynom.clear();
        while (begin != end) {
            polynom.push_back(*begin);
            begin++;
        }
        normalize();
    }

    T operator [] (size_t i) const {
        if (i >= polynom.size()) {
            return T(0);
        }
        return polynom[i];
    }

    T operator () (const T& x) const {
        T ans = T(0);
        T x_pow_i = static_cast<T>(1);
        for (size_t i = 0; i < polynom.size(); ++i) {
            ans += polynom[i] * x_pow_i;
            x_pow_i *= x;
        }
        return ans;
    }

    int Degree() const {
        if (polynom.empty()) {
            return -1;
        }
        return polynom.size() - 1;
    }

    typename vector<T>::const_iterator begin() const {
        return polynom.begin();
    }

    typename vector<T>::const_iterator end() const {
        return polynom.end();
    }

    size_t size() const {
        return polynom.size();
    }

    bool operator == (const Polynomial<T>& other) const {
        return polynom == other.polynom;
    }

    bool operator != (const Polynomial<T>& other) const {
        return polynom != other.polynom;
    }

    Polynomial& operator += (const Polynomial& other) {
        size_t deg = max(polynom.size(), other.polynom.size());
        polynom.resize(deg);
        for (size_t i = 0; i < other.size(); ++i) {
            polynom[i] += other.polynom[i];
        }
        normalize();
        return *this;
    }

    Polynomial& operator += (const T& other) {
        polynom[0] += other;
        normalize();
        return *this;
    }

    Polynomial& operator -= (const Polynomial& other) {
        size_t deg = max(polynom.size(), other.polynom.size());
        polynom.resize(deg);
        for (size_t i = 0; i < other.size(); ++i) {
            polynom[i] -= other.polynom[i];
        }
        normalize();
        return *this;
    }

    Polynomial& operator -= (const T& other) {
        polynom[0] -= other;
        normalize();
        return *this;
    }

    Polynomial& operator *= (const Polynomial& other) {
        if (polynom.size() == 0 || other.polynom.size() == 0) {
            Polynomial<T> k(T(0));
            polynom = k.polynom;
            return *this;
        }
        size_t deg = polynom.size() + other.polynom.size() - 2;
        size_t size_polynom = polynom.size();
        vector <T> polynom_new(deg + 1);
        for (size_t i = 0; i < polynom.size(); ++i) {
            polynom_new[i] = T(0);
        }
        for (size_t i = 0; i < other.size(); ++i) {
            for (size_t j = 0; j < size_polynom; ++j) {
                polynom_new[i + j] += polynom[j] * other.polynom[i];
            }
        }
        polynom = polynom_new;
        normalize();
        return *this;
    }

    Polynomial& operator *= (const T& other) {
        for (size_t i = 0; i < polynom.size(); ++i) {
            polynom[i] *= other;
        }
        normalize();
        return *this;
    }
    
    Polynomial operator /= (const Polynomial& other) {
        Polynomial<T> result(T(0));
        while (polynom.size() >= other.size()) {
            T coef = polynom.back() / other.polynom.back();
            size_t deg = polynom.size() - other.polynom.size();
            vector<T> monomial(deg + 1);
            monomial.back() = coef;
            Polynomial<T> monom(monomial);
            *this -= other * monom;
            result += monom;
        }
        polynom = result.polynom;
        return *this;
    }

    Polynomial operator %= (const Polynomial& other) {
        Polynomial<T> quotient = *this / other;
        Polynomial<T> ans = *this - other * quotient;
        polynom = ans.polynom;
        return *this;
    }

    friend ostream& operator << (ostream& out, const Polynomial<T>& pol) {
        bool f = true;

        for (int i = int(pol.size() - 1); i >= 0; i--) {
            if (pol[i] != T(0)) {
                f = false;
                if (pol[i] > T(0) && i != int(pol.size() - 1)) {
                    out << '+';
                }
                if (pol[i] == T(-1) && i != 0) {
                    out << '-';
                }
                if (pol[i] != T(-1) && pol[i] != T(1) && i != 0) {
                    out << pol[i] << "*";
                }
                if (i > 1) {
                    out << "x^" << i;
                }
                if (i == 1) {
                    out << 'x';
                }
                if (i == 0) {
                    out << pol[i];                
                }
            }
        }
        if (f) {
            out << T(0);
        }
        return out;
    }

    Polynomial operator & (const Polynomial& other) const {
        Polynomial<T> res(T(0));
        Polynomial<T> other_pow(T(1));
        for (size_t i = 0; i < polynom.size(); ++i) {
            res += (polynom[i] * other_pow);
            other_pow *= other;
        }
        return res;
    }

};

template<typename T>
Polynomial<T> operator + (const Polynomial<T>& first, const Polynomial<T>& second) {
    auto res =  first;
    res += second;
    return res;
}

template<typename T>
Polynomial<T> operator + (const Polynomial<T>& first, const T& second) {
    return first + Polynomial<T>(second);
}

template<typename T>
Polynomial<T> operator + (const T& second, const Polynomial<T>& first) {
    return first + Polynomial<T>(second);
}

template<typename T>
Polynomial<T> operator - (const Polynomial<T>& first, const Polynomial<T>& second) {
    auto res =  first;
    res -= second;
    return res;
}

template<typename T>
Polynomial<T> operator - (const Polynomial<T>& first, const T& second) {
    return first - Polynomial<T>(second);
}

template<typename T>
Polynomial<T> operator - (const T& first, const Polynomial<T>& second) {
    return Polynomial<T>(first) - second;
}

template<typename T>
Polynomial<T> operator * (const Polynomial<T>& first, const Polynomial<T>& second) {
    auto res =  first;
    res *= second;
    return res;
}

template<typename T>
Polynomial<T> operator * (const Polynomial<T>& first, const T& second) {
    return first * Polynomial<T>(second);
}

template<typename T>
Polynomial<T> operator * (const T& second, const Polynomial<T>& first) {
    return first * Polynomial<T>(second);
}

template<typename T>
Polynomial<T> operator / (const Polynomial<T>& first, const Polynomial<T>& second) {
    auto res =  first;
    res /= second;
    return res;
}

template<typename T>
Polynomial<T> operator % (const Polynomial<T>& first, const Polynomial<T>& second) {
    auto res =  first;
    res %= second;
    return res;
}

template<typename T>
bool operator == (const Polynomial<T>& first, const T& second) {
    return (first == Polynomial<T>(second));
}

template<typename T>
bool operator == (const T& first, const Polynomial<T>& second) {
    return (second == Polynomial<T>(first));
}

template<typename T>
bool operator != (const Polynomial<T>& first, const T& second) {
    return (first != Polynomial<T>(second));
}

template<typename T>
bool operator != (const T& first, const Polynomial<T>& second) {
    return (second != Polynomial<T>(first));
}


template <typename T>
Polynomial<T> operator, (const Polynomial<T>& first, const Polynomial<T>& second) {
    Polynomial<T> fir = first, sec = second;
    while (sec.Degree() != -1) {
        fir %= sec;
        swap(fir, sec);
    }
    if (fir.Degree() != -1) {
        Polynomial<T> coef(fir[fir.Degree()]);
        fir /= coef;
    }
    return fir;
}
#include<algorithm>
#include<iostream>
#include<cstdio>
#include<math.h>
#include<vector>
#include<string>
#include<stdio.h>
using namespace std;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

class Rational {
private:
    int m;
    int n;

public:
    Rational& irred() {
        int sgn = 1;
        if (m < 0) {
            sgn *= -1;
        }
        if (n < 0) {
            sgn *= -1;
        }
        m = abs(m);
        n = abs(n);
        int gcd1 = gcd(m, n);
        m /= (gcd1 * sgn);
        n /= gcd1;
        return *this;
    }

    explicit Rational(int m = 0, int n = 1)
        : m(m)
        , n(n)
    {irred();}

    int M() const {
        return m;
    }

    int N() const {
        return n;
    }

    Rational operator + () const {
        auto z = *this;
        return z;
    }

    Rational operator - () const {
        auto z = Rational();
        z -= *this;
        return z;
    }

    int numerator() const {
        return m;
    }

    int denominator() const {
        return n;
    }

    bool operator == (const Rational& other) {
        return (m == other.m && n == other.n);
    }

    bool operator != (const Rational& other) {
        return !(*this == other);
    }

    Rational& operator += (const Rational& other) {
        auto c = *this;
        m = c.m * other.n + other.m * c.n;
        n = c.n * other.n;
        return irred();
    }

    Rational& operator -= (const Rational& other) {
        auto c = *this;
        m = c.m * other.n - other.m * c.n;
        n = c.n * other.n;
        return irred();
    }

    Rational& operator *= (const Rational& other) {
        auto c = *this;
        m = c.m * other.m;
        n = c.n * other.n;
        return irred();
    }

    Rational& operator /= (const Rational& other) {
        auto c = *this;
        c.m = m * other.n;
        c.n = n * other.m;
        m = c.m;
        n = c.n;
        return irred();
    }

    Rational& operator ++() {
        m += n;
        return irred();
    }

    Rational operator ++(int) {
        auto c = *this;
        m += n;
        return c;
    }

    Rational& operator --() {
        m -= n;
        return irred();
    }

    Rational operator --(int) {
        auto c = *this;
        m -= n;
        return c;
    }
};

Rational operator + (const Rational& one, const Rational& other) {
    auto z = one;
    z += other;
    return z;
}

Rational operator + (Rational a, int b) {
    return a += Rational(b * a.N(), a.N());
}
Rational operator + (int b, Rational a) {
    return a += Rational(b * a.N(), a.N());
}

Rational operator - (const Rational& one, const Rational& other) {
    auto z = one;
    z -= other;
    return z;
}

Rational operator - (Rational a, int b) {
    return a -= Rational(b * a.N(), a.N());
}
Rational operator - (int b, Rational a) {
    return a -= Rational(b * a.N(), a.N());
}

Rational operator * (const Rational& one, const Rational& other) {
    auto z = one;
    z *= other;
    return z;
}

Rational operator * (Rational a, int b) {
    return a *= Rational(b, 1);
}
Rational operator * (int b, Rational a) {
    return a *= Rational(b, 1);
}

Rational operator / (const Rational& one, const Rational& other) {
    auto z = one;
    z /= other;
    return z;
}

Rational operator / (Rational a, int b) {
    return a /= Rational(b, 1);
}
Rational operator / (int b, Rational a) {
    return a /= Rational(b, 1);
}
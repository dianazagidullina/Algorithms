#include<iostream>
#include<cstdio>
#include<math.h>
#include<vector>
#include<string>
#include<stdio.h>
using namespace std;

class Complex {
    private:
        double re;
        double im;

    public:
        explicit Complex(double Re = 0, double Im = 0)
            : re(Re)
            , im(Im)
        {}

        double Re() const {
            return re;
        }

        double Im() const {
            return im;
        }

        Complex operator + () const {
            auto z = *this;
            return z;
        }

        Complex operator - () const {
            auto z = Complex();
            return z -= *this;
        }


        bool operator == (const Complex& other) {
            return (re == other.re && im == other.im);
        }

        bool operator != (const Complex& other) {
            return !(*this == other);
        }

        Complex& operator += (const Complex& other) {
            re += other.re;
            im += other.im;
            return *this;
        }

        Complex& operator -= (const Complex& other) {
            re -= other.re;
            im -= other.im;
            return *this;
        }

        Complex& operator *= (const Complex& other) {
            Complex z;
            z.re = re * other.re - im * other.im;
            z.im = im * other.re + re * other.im;
            re = z.re;
            im = z.im;
            return *this;
        }

        Complex& operator /= (const Complex& other) {
            Complex z;
            auto sqr = other.re * other.re + other.im * other.im;
            z.re = (re * other.re + im * other.im) / sqr;
            z.im = (im * other.re - re * other.im) / sqr;
            re = z.re;
            im = z.im;
            return *this;
        }

        Complex operator + (const Complex& other) const {
            auto z = *this;
            z += other;
            return z;
        }

        Complex operator - (const Complex& other) const {
            auto z = *this;
            z -= other;
            return z;
        }

        Complex operator * (const Complex& other) const {
            auto z = *this;
            z *= other;
            return z;
        }

        Complex operator / (const Complex& other) const {
            auto z = *this;
            z /= other;
            return z;
        }
};

double abs(const Complex& z) {
    return sqrt(z.Re() * z.Re() + z.Im() * z.Im());
}

template <typename T>
Complex operator + (const T& a, const Complex& other) {
    return Complex(other.Re() + a, other.Im());
}

template <typename T>
Complex operator + (const Complex& other, const T& a) {
    return Complex(other.Re() + a, other.Im());
}


template <typename T>
Complex operator - (const T& a, const Complex& other) {
    return Complex(other.Re() - a, other.Im());
}

template <typename T>
Complex operator - (const Complex& other, const T& a) {
    return Complex(other.Re() - a, other.Im());
}


template <typename T>
Complex operator * (const T& a, const Complex& other) {
    return Complex(other.Re() * a, other.Im() * a);
}

template <typename T>
Complex operator * (const Complex& other, const T& a) {
    return Complex(other.Re() * a, other.Im() * a);
}


template <typename T>
Complex operator / (const T& a, const Complex& other) {
    return Complex(other.Re() / a, other.Im() / a);
}

template <typename T>
Complex operator / (const Complex& other, const T& a) {
    return Complex(other.Re() / a, other.Im() / a);
}

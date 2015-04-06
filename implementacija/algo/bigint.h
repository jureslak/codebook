#ifndef IMPLEMENTACIJA_ALGO_BIGINT_H_
#define IMPLEMENTACIJA_ALGO_BIGINT_H_

#include "bigint_util.h"

template<typename T>
struct Number {
    bool sign = true;  // true = 1 = +, false = 0 = -
    deque<T> data;
    static const int base = 10;  // bi se lahko spremenilo samo I/O nebi delal, matematika bi
    static const int KARATSUBA_LIMIT = 2;  // kdaj preklopi na bruteforce množenje

    Number() {}  // default constructor, positive zero
    Number(const deque<T>& a, bool s = 1) : sign(s), data(a) { clear_zeros(); }
    Number(deque<T>&& a, bool s = 1) : sign(s), data(a) { clear_zeros(); }
    Number(const string& s) { from_string(s); }
    void from_string(const string& s) {
        if (s.size() == 0) data = {0};
        int i = 0;
        if (s[0] == '+') sign = 1, i = 1;
        if (s[0] == '-') sign = 0, i = 1;
        int l = s.size(); data.resize(l-i);
        for (; i < l; ++i) {
            if (!('0' <= s[i] && s[i] <= '9')) return;  // silent quit po prvi ne stevilki
            data[l-i-1] = s[i] - '0';
        }
        clear_zeros();
    }
    string to_string() const {
        if (data.empty()) return "0";
        string s = (sign) ? "" : "-";
        for (int i = data.size() - 1; i >= 0; --i)
            s.push_back('0' + data[i]);
        return s;
    }
    Number operator+(const Number& o) const {  // remove signs if using for positive only
        if (sign == 0) return -((-*this) + (-o));
        if (sign == 1 && o.sign == 0) return (*this < -o) ? -((-o) - *this) : *this - (-o);
        bool carry = false;
        int i = 0, j = 0, n = data.size(), m = o.data.size();
        deque<T> r;
        while (i < n || j < m) {
            T c = ((i < n) ? data[i++] : 0) + ((j < m) ? o.data[j++] : 0) + carry;
            carry = (c >= base);
            r.push_back(c % base);
        }
        if (carry) r.push_back(1);
        return Number(move(r));
    }
    Number operator-() const { return Number(data, !sign); }
    bool operator==(const Number& o) const { return sign == o.sign && data == o.data; }
    bool operator<(const Number& o) const {
        if (sign == o.sign) {
            if (sign == 0) return -o < -*this;
            if (data.size() == o.data.size()) {
                for (int i = data.size() - 1; i >= 0; --i)
                    if (data[i] == o.data[i]) continue;
                    else return data[i] < o.data[i];
            }
            return data.size() < o.data.size();
        }
        return sign < o.sign;
    }
    Number& operator+=(const Number& o) {  // lahko tudi s +. Samo za pozitivne.
        bool carry = false;
        int i = 0, j = 0, n = data.size(), m = o.data.size();
        while (i < n || j < m) {
            if (i < n && j < m) data[i] += o.data[j++] + carry;
            else if (i < n)     data[i] += carry;
            else                data.push_back(o.data[j++] + carry);
            carry = data[i] / base;
            data[i++] %= base;
        }
        if (carry) data.push_back(1);
        clear_zeros();
        return *this;
    }
    Number operator*(const T& o) const {  // z eno števko
        deque<T> r;
        int carry = 0, n = data.size();
        for (int i = 0; i < n; ++i) {
            T c = data[i]*o + carry;
            carry = c / base;
            c %= base;
            r.push_back(c);
        }
        if (carry) r.push_back(carry);
        return Number(move(r), sign);
    }
    Number operator<<(int n) const {  // na zacetek dodamo n ničel
        deque<T> r(n, 0);
        r.insert(r.end(), data.begin(), data.end());
        return Number(move(r));
    }
    Number operator*(const Number<T>& o) const {
        if (sign == 0 && o.sign == 0) return ((-*this) * (-o));
        if (sign == 0 && o.sign == 1) return -((-*this) * o);
        if (sign == 1 && o.sign == 0) return -(*this * (-o));
        Number r;
        int m = o.data.size();
        for (int i = 0; i < m; ++i)
            r += (*this*o.data[i] << i);
        return r;
    }
    Number operator-(const Number& o) const {
        deque<T> r;
        bool carry = false;
        int i = 0, j = 0, n = data.size(), m = o.data.size();
        while (i < n || j < m) {
            T c = data[i++] + base - ((j < m) ? o.data[j++] : 0) - carry;
            carry = 1 - c / base;
            c %= base;
            r.push_back(c);
        }
        return Number(move(r));
    }

  private:
    void clear_zeros() {
        while (data.size() > 0 && data.back() == 0) data.pop_back();
        if (data.empty()) sign = 1;
    }
};

template<typename T>  // karatsuba algorithm
Number<T> karatsuba(const Number<T>& a, const Number<T>& b) {
    if (a.data.size() <= Number<T>::KARATSUBA_LIMIT || b.data.size() <= Number<T>::KARATSUBA_LIMIT)
        return a*b;

    if (a.sign == 0 && b.sign == 0) return ((-a) * (-b));
    if (a.sign == 0 && b.sign == 1) return -((-a) * b);
    if (a.sign == 1 && b.sign == 0) return -(a * (-b));

    Number<T> a0, a1, b0, b1, c0, c1, c2;
    int m = min(a.data.size(), b.data.size())/2;  // choose m carefully

    a0.data.assign(a.data.begin(), a.data.begin()+m);
    a1.data.assign(a.data.begin()+m, a.data.end());
    b0.data.assign(b.data.begin(), b.data.begin()+m);
    b1.data.assign(b.data.begin()+m, b.data.end());

    c2 = karatsuba(a1, b1);
    c0 = karatsuba(a0, b0);
    c1 = karatsuba(a0+a1, b0+b1) - c0 - c2;

    return (c2 << 2*m) + (c1 << m) + c0;
}
#endif  // IMPLEMENTACIJA_ALGO_BIGINT_H_

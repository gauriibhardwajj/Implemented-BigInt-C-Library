#include <bits/stdc++.h>

#ifndef BIGINT_H
#define BIGINT_H

using namespace std;

class BigInt
{
protected:
    string digits;

public:
    // Constructors
    BigInt(unsigned long long n = 0);
    BigInt(const char *);
    BigInt(string &);
    BigInt(BigInt &);

    // Helper Functions
    friend void divide_by_2(BigInt &a);
    friend bool isNull(const BigInt &);
    friend int length(const BigInt &);
    int operator[](const int) const;

    /* <----------------------------- Operator Overloading ---------------------------------->*/

    // Direct assignment
    BigInt &operator=(const BigInt &);

    // Post/Pre - Incrementation
    BigInt &operator++();
    BigInt operator++(int temp); // post increment
    BigInt &operator--();
    BigInt operator--(int temp); // post decrement

    // Comparison operators
    friend bool operator==(const BigInt &, const BigInt &);
    friend bool operator!=(const BigInt &, const BigInt &);

    friend bool operator>(const BigInt &, const BigInt &);
    friend bool operator>=(const BigInt &, const BigInt &);
    friend bool operator<(const BigInt &, const BigInt &);
    friend bool operator<=(const BigInt &, const BigInt &);

    // Addition and Subtraction
    friend BigInt &operator+=(BigInt &, const BigInt &);
    friend BigInt operator+(const BigInt &, const BigInt &);
    friend BigInt operator-(const BigInt &, const BigInt &);
    friend BigInt &operator-=(BigInt &, const BigInt &);

    // Multiplication and Division
    friend BigInt &operator*=(BigInt &, const BigInt &);
    friend BigInt operator*(const BigInt &, const BigInt &);
    friend BigInt &operator/=(BigInt &, const BigInt &);
    friend BigInt operator/(const BigInt &, const BigInt &);

    // Modulo
    friend BigInt operator%(const BigInt &, const BigInt &);
    friend BigInt &operator%=(BigInt &, const BigInt &);

    // Power Function
    friend BigInt &operator^=(BigInt &, const BigInt &);
    friend BigInt operator^(BigInt &, const BigInt &);

    // Square Root Function
    friend BigInt sqrt(BigInt &a);

    // Read and Write
    friend ostream &operator<<(ostream &, const BigInt &);
    friend istream &operator>>(istream &, BigInt &);

    // Others
    friend BigInt NthCatalan(int n);
    friend BigInt NthFibonacci(int n);
    friend BigInt Factorial(int n);
};

/* <----------------------------- Constructors ---------------------------------->*/

BigInt::BigInt(unsigned long long n)
{
    do
    {
        digits.push_back(n % 10);
        n /= 10;
    } while (n > 0);
}

BigInt::BigInt(const char *s)
{
    digits = "";
    for (int i = strlen(s) - 1; i >= 0; i--)
    {
        if (!isdigit(s[i]))
            throw "ERROR";
        digits.push_back(s[i] - '0');
    }
}

BigInt::BigInt(string &s)
{
    digits = "";
    for (int i = s.size() - 1; i >= 0; i--)
    {
        if (!isdigit(s[i]))
            throw "ERROR";
        digits.push_back(s[i] - '0');
    }
}

BigInt::BigInt(BigInt &b)
{
    digits = b.digits;
}

bool isNull(const BigInt &a)
{
    if (a.digits.size() == 1 && a.digits[0] == 0)
        return true;
    return false;
}

int length(const BigInt &a)
{
    return a.digits.size();
}

int BigInt::operator[](const int index) const
{
    if (digits.size() <= index || index < 0)
        throw("ERROR");
    return digits[index];
}

/* <----------------------------- Direct Assignment ---------------------------------->*/

BigInt &BigInt::operator=(const BigInt &a)
{
    digits = a.digits;
    return *this;
}

// --------------------------------------> Increment- Decrement -------------------------->

BigInt &BigInt::operator++()
{
    // Pre-Increment
    int i, n = digits.size();
    for (i = 0; i < n && digits[i] == 9; i++)
    {
        digits[i] = 0;
    }
    if (i == n)
        digits.push_back(1);
    else
        digits[i]++;

    return *this;
}

BigInt BigInt::operator++(int temp)
{
    // Post-Increment
    BigInt aux = *this;
    ++(*this);
    return aux;
}

BigInt &BigInt::operator--()
{
    // Pre-Decrement
    int i, n = digits.size();
    if (n == 1 && digits[0] == 0)
        throw("ERROR!!");

    for (i = 0; i < n && digits[i] == 0; i++)
    {
        digits[i] = 9;
    }
    digits[i]--;

    if (n > 1 && digits[n - 1] == 0)
    {
        digits.pop_back();
    }

    return *this;
}

BigInt BigInt::operator--(int temp)
{
    // Post-Decrement
    BigInt aux = *this;
    --(*this);
    return aux;
}

// ----------------------------------> Comparison Operators ------------------------------>

bool operator==(const BigInt &a, const BigInt &b)
{
    return (a.digits == b.digits);
}

bool operator!=(const BigInt &a, const BigInt &b)
{
    return !(a == b);
}

bool operator<(const BigInt &a, const BigInt &b)
{
    int m = length(a);
    int n = length(b);

    if (m != n)
        return m < n;

    while (m--)
    {
        if (a.digits[m] != b.digits[m])
            return a.digits[m] < b.digits[m];
    }

    return false;
}

bool operator>(const BigInt &a, const BigInt &b)
{
    return b < a;
}

bool operator<=(const BigInt &a, const BigInt &b)
{
    return !(a > b);
}

bool operator>=(const BigInt &a, const BigInt &b)
{
    return !(a < b);
}

// -----------------------------------> Addition & Subtraction ------------------------------->

BigInt &operator+=(BigInt &a, const BigInt &b)
{
    int carry = 0, sum, i;
    int m = length(a);
    int n = length(b);

    if (m < n)
    {
        a.digits.append(n - m, 0);
    }

    for (i = 0; i < m; i++)
    {
        if (i < n)
            sum = a.digits[i] + b.digits[i] + carry;
        else
            sum = a.digits[i] + carry;

        carry = sum / 10;
        a.digits[i] = sum % 10;
    }

    if (carry)
        a.digits.push_back(carry);
    return a;
}

BigInt operator+(const BigInt &a, const BigInt &b)
{
    BigInt temp;
    temp = a;
    temp += b;
    return temp;
}

BigInt &operator-=(BigInt &a, const BigInt &b)
{
    if (a < b)
        throw("UNDERFLOW");

    int m = length(a), n = length(b);
    int i, carry = 0, diff;
    for (i = 0; i < m; i++)
    {
        if (i < n)
            diff = a.digits[i] - b.digits[i] + carry;
        else
            diff = a.digits[i] + carry;
        if (diff < 0)
            diff += 10,
                carry = -1;
        else
            carry = 0;
        a.digits[i] = diff;
    }

    while (m > 1 && a.digits[m - 1] == 0)
    {
        a.digits.pop_back();
        m--;
    }

    return a;
}

BigInt operator-(const BigInt &a, const BigInt &b)
{
    BigInt temp;
    temp = a;
    temp -= b;
    return temp;
}

// -----------------------------------> Multiplication & Division ---------------------------->

BigInt &operator*=(BigInt &a, const BigInt &b)
{
    if (isNull(a) || isNull(b))
    {
        a = BigInt();
        return a;
    }
    int m = length(a), n = length(b);
    vector<int> temp(m + n, 0);
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
        {
            temp[i + j] += (a.digits[i]) * (b.digits[j]);
        }
    m += n;
    a.digits.resize(temp.size());
    int sum = 0, carry = 0;
    for (int i = 0; i < m; i++)
    {
        sum = carry + temp[i];
        temp[i] = sum % 10;
        carry = sum / 10;
        a.digits[i] = temp[i];
    }
    for (int i = m - 1; i >= 1 && !temp[i]; i--)
        a.digits.pop_back();

    return a;
}

BigInt operator*(const BigInt &a, const BigInt &b)
{
    BigInt temp;
    temp = a;
    temp *= b;
    return temp;
}

BigInt &operator/=(BigInt &a, const BigInt &b)
{
    if (isNull(b))
        throw("ERROR: Division by Zero");

    if (a < b)
    {
        a = BigInt();
        return a;
    }

    if (a == b)
    {
        a = BigInt(1);
        return a;
    }

    // Initialising variables
    int i, lgcat = 0, cc;
    int m = length(a), n = length(b);
    vector<int> cat(m, 0);
    BigInt temp;
}

BigInt operator/(const BigInt &a, const BigInt &b)
{
    BigInt temp;
    temp = a;
    temp /= b;
    return temp;
}

/* <----------------------------- Modulus and Power---------------------------------->*/

BigInt &operator%=(BigInt &a, const BigInt &b)
{
    if (isNull(b))
        throw("Arithmetic Error: Division By 0");
    if (a < b)
    {
        return a;
    }
    if (a == b)
    {
        a = BigInt();
        return a;
    }
    int i, lgcat = 0, cc;
    int n = length(a), m = length(b);
    vector<int> cat(n, 0);
    BigInt t;
    for (i = n - 1; t * 10 + a.digits[i] < b; i--)
    {
        t *= 10;
        t += a.digits[i];
    }
    for (; i >= 0; i--)
    {
        t = t * 10 + a.digits[i];
        for (cc = 9; cc * b > t; cc--)
            ;
        t -= cc * b;
        cat[lgcat++] = cc;
    }
    a = t;
    return a;
}
BigInt operator%(const BigInt &a, const BigInt &b)
{
    BigInt temp;
    temp = a;
    temp %= b;
    return temp;
}

BigInt &operator^=(BigInt &a, const BigInt &b)
{
    BigInt Exponent, Base(a);
    Exponent = b;
    a = 1;
    while (!isNull(Exponent))
    {
        if (Exponent[0] & 1)
            a *= Base;
        Base *= Base;
        divide_by_2(Exponent);
    }
    return a;
}
BigInt operator^(BigInt &a, BigInt &b)
{
    BigInt temp(a);
    temp ^= b;
    return temp;
}

void divide_by_2(BigInt &a)
{
    int add = 0;
    for (int i = a.digits.size() - 1; i >= 0; i--)
    {
        int digit = (a.digits[i] >> 1) + add;
        add = ((a.digits[i] & 1) * 5);
        a.digits[i] = digit;
    }
    while (a.digits.size() > 1 && !a.digits.back())
        a.digits.pop_back();
}

/* <----------------------------- Implementing square root function ---------------------------------->*/

BigInt sqrt(BigInt &a)
{
    BigInt left(1), right(a), v(1), mid, prod;
    divide_by_2(right);
    while (left <= right)
    {
        mid += left;
        mid += right;
        divide_by_2(mid);
        prod = (mid * mid);
        if (prod <= a)
        {
            v = mid;
            ++mid;
            left = mid;
        }
        else
        {
            --mid;
            right = mid;
        }
        mid = BigInt();
    }
    return v;
}

/* <----------------------------- Computing Catalan Series ---------------------------------->*/
BigInt NthCatalan(int n)
{
    BigInt a(1), b;
    for (int i = 2; i <= n; i++)
        a *= i;
    b = a;
    for (int i = n + 1; i <= 2 * n; i++)
        b *= i;
    a *= a;
    a *= (n + 1);
    b /= a;
    return b;
}

/* <----------------------------- Computing Fibonacci Series ---------------------------------->*/
BigInt NthFibonacci(int n)
{
    BigInt a(1), b(1), c;
    if (!n)
        return c;
    n--;
    while (n--)
    {
        c = a + b;
        b = a;
        a = c;
    }
    return b;
}

/* <----------------------------- Computing Factorial ---------------------------------->*/
BigInt Factorial(int n)
{
    BigInt f(1);
    for (int i = 2; i <= n; i++)
        f *= i;
    return f;
}

/* <----------------------------- Defining Input and output streams ---------------------------------->*/
istream &operator>>(istream &in, BigInt &a)
{
    string s;
    in >> s;
    int n = s.size();
    for (int i = n - 1; i >= 0; i--)
    {
        if (!isdigit(s[i]))
            throw("INVALID NUMBER");
        a.digits[n - i - 1] = s[i];
    }
    return in;
}

ostream &operator<<(ostream &out, const BigInt &a)
{
    for (int i = a.digits.size() - 1; i >= 0; i--)
        cout << (short)a.digits[i];
    return cout;
}

#endif

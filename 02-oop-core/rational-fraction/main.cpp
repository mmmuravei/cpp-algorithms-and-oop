#include <iostream>
#include <cstdlib>
#include <numeric>

/**
 * @file Fraction.hpp / main.cpp
 * @brief Rational Number Arithmetic Class with Invariant Maintenance and Euclidean Algorithm
 */

class Fraction {
private:
    int numerator;
    int denominator;

    // Euclidean Algorithm for Greatest Common Divisor
    static int gcd(int a, int b) {
        a = std::abs(a);
        b = std::abs(b);
        while (b != 0) {
            int t = b;
            b = a % b;
            a = t;
        }
        return (a == 0) ? 1 : a;
    }

    void simplify() {
        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }
        int common = gcd(numerator, denominator);
        numerator /= common;
        denominator /= common;
    }

public:
    Fraction() : numerator(0), denominator(1) {}

    Fraction(int num, int den) : numerator(num), denominator(den) {
        if (denominator == 0) {
            std::cerr << "[Error] Denominator cannot be zero. Resetting to 1.\n";
            denominator = 1;
        }
        simplify();
    }

    Fraction operator+(const Fraction& other) const {
        return Fraction(numerator * other.denominator + other.numerator * denominator,
                        denominator * other.denominator);
    }

    Fraction operator*(const Fraction& other) const {
        return Fraction(numerator * other.numerator, denominator * other.denominator);
    }

    void print() const {
        std::cout << numerator;
        if (denominator != 1 && numerator != 0) {
            std::cout << "/" << denominator;
        }
        std::cout << "\n";
    }
};

int main() {
    std::cout << "=== Rational Number (Fraction) Arithmetic ===\n\n";

    Fraction f1(2, 4);
    std::cout << "Fraction 1 (2/4 reduced): ";
    f1.print();

    Fraction f2(3, 5);
    std::cout << "Fraction 2 (3/5): ";
    f2.print();

    Fraction sum = f1 + f2;
    std::cout << "f1 + f2 = ";
    sum.print();

    Fraction product = f1 * f2;
    std::cout << "f1 * f2 = ";
    product.print();

    return 0;
}

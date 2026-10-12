#include <iostream>
#include <cmath>
#include <stdexcept>

/**
 * @file Triangle.hpp / main.cpp
 * @brief Demonstration of Class Lifecycle, Encapsulation and Geometric Verification
 */

class Triangle {
private:
    double side_a;
    double side_b;
    double side_c;
    static constexpr double EPSILON = 1e-9;

public:
    // Default Constructor
    Triangle() : side_a(1.0), side_b(1.0), side_c(1.0) {
        std::cout << "[Triangle] Default constructor invoked.\n";
    }

    // Parameterized Constructor
    Triangle(double a, double b, double c) : side_a(a), side_b(b), side_c(c) {
        std::cout << "[Triangle] Parameterized constructor invoked (" << a << ", " << b << ", " << c << ")\n";
        if (!isValid()) {
            std::cerr << "[Warning] Warning: Provided sides violate triangle inequality theorem.\n";
        }
    }

    // Copy Constructor
    Triangle(const Triangle& other)
        : side_a(other.side_a), side_b(other.side_b), side_c(other.side_c) {
        std::cout << "[Triangle] Copy constructor invoked.\n";
    }

    // Destructor
    ~Triangle() {
        std::cout << "[Triangle] Destructor invoked for sides (" << side_a << ", " << side_b << ", " << side_c << ")\n";
    }

    // Validation using floating-point epsilon comparison
    bool isValid() const {
        return (side_a > EPSILON) && (side_b > EPSILON) && (side_c > EPSILON) &&
               (side_a + side_b - side_c > EPSILON) &&
               (side_a + side_c - side_b > EPSILON) &&
               (side_b + side_c - side_a > EPSILON);
    }

    double getPerimeter() const {
        return side_a + side_b + side_c;
    }

    double getArea() const {
        if (!isValid()) return 0.0;
        double s = getPerimeter() / 2.0;
        return std::sqrt(s * (s - side_a) * (s - side_b) * (s - side_c));
    }
};

int main() {
    std::cout << "=== OOP Triangle Lifecycle & Geometry Test ===\n\n";

    {
        Triangle default_t;
        std::cout << "Default Perimeter: " << default_t.getPerimeter() << ", Area: " << default_t.getArea() << "\n\n";

        Triangle custom_t(3.0, 4.0, 5.0);
        std::cout << "Custom Perimeter: " << custom_t.getPerimeter() << ", Area: " << custom_t.getArea() << "\n\n";

        Triangle copied_t = custom_t;
        std::cout << "Copied Triangle Area: " << copied_t.getArea() << "\n\n";
    }

    std::cout << "Scope exited successfully.\n";
    return 0;
}

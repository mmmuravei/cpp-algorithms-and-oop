#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

/**
 * @file main.cpp
 * @brief Trapping Rain Water Algorithm (Dynamic Programming / Prefix Maximums)
 * 
 * Computes the total volume of trapped water between vertical walls of varying heights.
 * Time Complexity: O(N)
 * Auxiliary Space: O(N)
 */

long long calculateTrappedWater(const std::vector<int>& height) {
    int n = static_cast<int>(height.size());
    if (n <= 2) return 0;

    std::vector<int> left_max(n);
    std::vector<int> right_max(n);

    // Compute maximum wall height to the left of each index
    left_max[0] = height[0];
    for (int i = 1; i < n; ++i) {
        left_max[i] = std::max(left_max[i - 1], height[i]);
    }

    // Compute maximum wall height to the right of each index
    right_max[n - 1] = height[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        right_max[i] = std::max(right_max[i + 1], height[i]);
    }

    // Sum trapped water above each position
    long long total_water = 0;
    for (int i = 0; i < n; ++i) {
        int bounded_height = std::min(left_max[i], right_max[i]);
        if (bounded_height > height[i]) {
            total_water += (bounded_height - height[i]);
        }
    }

    return total_water;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cout << "=== Trapping Rain Water Solver ===\n";
    std::cout << "Enter number of wall segments: ";
    int count = 0;
    if (!(std::cin >> count) || count <= 0) {
        std::cerr << "Invalid input. Positive integer expected.\n";
        return 1;
    }

    std::mt19937 rng(static_cast<unsigned int>(std::chrono::system_clock::now().time_since_epoch().count()));
    std::uniform_int_distribution<int> dist(1, 15);

    std::vector<int> walls(count);
    std::cout << "Wall profile heights:\n";
    for (int i = 0; i < count; ++i) {
        walls[i] = dist(rng);
        std::cout << walls[i] << " ";
    }
    std::cout << "\n\n";

    long long trapped = calculateTrappedWater(walls);
    std::cout << "Total trapped water volume: " << trapped << " units.\n";

    return 0;
}

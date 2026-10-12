#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <climits>

/**
 * @file main.cpp
 * @brief Partition Optimization: Exhaustive Search (Backtracking) vs Greedy Approach
 * 
 * Explores strategies to partition N weighted elements across M subsets such that
 * the weight variance (max_subset - min_subset) is minimized.
 */

class PartitionOptimizer {
private:
    int num_elements;
    int num_subsets;
    std::vector<int> weights;
    std::vector<int> current_assignment;
    std::vector<int> best_assignment;
    int best_imbalance;

    void backtrack(int index) {
        if (index == num_elements) {
            std::vector<int> subset_sums(num_subsets, 0);
            for (int i = 0; i < num_elements; ++i) {
                subset_sums[current_assignment[i]] += weights[i];
            }
            int min_w = *std::min_element(subset_sums.begin(), subset_sums.end());
            int max_w = *std::max_element(subset_sums.begin(), subset_sums.end());
            int diff = max_w - min_w;

            if (diff < best_imbalance) {
                best_imbalance = diff;
                best_assignment = current_assignment;
            }
            return;
        }

        for (int s = 0; s < num_subsets; ++s) {
            current_assignment[index] = s;
            backtrack(index + 1);
        }
    }

public:
    PartitionOptimizer(int n, int m, std::vector<int> w)
        : num_elements(n), num_subsets(m), weights(std::move(w)),
          current_assignment(n, 0), best_assignment(n, 0), best_imbalance(INT_MAX) {}

    void solveExhaustive() {
        backtrack(0);
        std::cout << "Exhaustive Search Minimum Imbalance: " << best_imbalance << "\n";
    }

    void solveGreedy() {
        // Sort descending and greedily assign to currently lightest subset
        std::vector<std::pair<int, int>> sorted_items(num_elements);
        for (int i = 0; i < num_elements; ++i) sorted_items[i] = {weights[i], i};
        std::sort(sorted_items.rbegin(), sorted_items.rend());

        std::vector<int> subset_sums(num_subsets, 0);
        for (const auto& item : sorted_items) {
            auto min_it = std::min_element(subset_sums.begin(), subset_sums.end());
            *min_it += item.first;
        }

        int min_w = *std::min_element(subset_sums.begin(), subset_sums.end());
        int max_w = *std::max_element(subset_sums.begin(), subset_sums.end());
        std::cout << "Greedy Heuristic Imbalance: " << (max_w - min_w) << "\n";
    }
};

int main() {
    std::cout << "=== Partition Optimization Benchmark ===\n";
    std::vector<int> sample_weights = {12, 5, 8, 17, 3, 9, 14, 6};
    int subsets = 3;

    std::cout << "Input weights: ";
    for (int w : sample_weights) std::cout << w << " ";
    std::cout << "\nSubsets count: " << subsets << "\n\n";

    PartitionOptimizer solver(static_cast<int>(sample_weights.size()), subsets, sample_weights);
    solver.solveExhaustive();
    solver.solveGreedy();

    return 0;
}

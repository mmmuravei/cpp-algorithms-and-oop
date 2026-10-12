#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
#include <iomanip>

/**
 * @file main.cpp
 * @brief Discrete-Event Simulation of a Worker Queue / Job Pipeline
 * 
 * Simulates incoming batches of processing units, schedules their arrival and
 * measures pipeline processing capacity and timeline.
 * Core concepts: Struct-based data records, chronologic event sorting, timeline simulation.
 */

struct ProcessTask {
    int id;
    int arrival_time;
    int processing_duration;
    int start_time;
    int finish_time;
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cout << "=== Discrete-Event Job Queue Simulation ===\n";
    int time_window = 30;
    std::cout << "Enter simulation time horizon T0 (e.g. 30): ";
    if (!(std::cin >> time_window) || time_window <= 0) {
        time_window = 30;
    }

    std::mt19937 rng(static_cast<unsigned int>(std::chrono::system_clock::now().time_since_epoch().count()));
    std::uniform_int_distribution<int> count_dist(5, 12);
    std::uniform_int_distribution<int> duration_dist(2, 6);
    std::uniform_int_distribution<int> arrival_dist(1, time_window);

    int total_tasks = count_dist(rng);
    std::vector<ProcessTask> tasks;
    tasks.reserve(total_tasks);

    for (int i = 0; i < total_tasks; ++i) {
        tasks.push_back({
            i + 1,
            arrival_dist(rng),
            duration_dist(rng),
            -1,
            -1
        });
    }

    // Sort tasks chronologically by arrival time
    std::sort(tasks.begin(), tasks.end(), [](const ProcessTask& a, const ProcessTask& b) {
        return a.arrival_time < b.arrival_time;
    });

    // Simulate single-worker queue processing
    int current_clock = 0;
    for (auto& task : tasks) {
        if (current_clock < task.arrival_time) {
            current_clock = task.arrival_time;
        }
        task.start_time = current_clock;
        task.finish_time = current_clock + task.processing_duration;
        current_clock = task.finish_time;
    }

    // Output formatted simulation table
    std::cout << "\nTask Schedule & Execution Metrics:\n";
    std::cout << std::string(60, '-') << "\n";
    std::cout << std::left 
              << std::setw(10) << "Task ID"
              << std::setw(15) << "Arrival Time"
              << std::setw(12) << "Duration"
              << std::setw(12) << "Start Time"
              << std::setw(12) << "End Time" << "\n";
    std::cout << std::string(60, '-') << "\n";

    for (const auto& task : tasks) {
        std::cout << std::left
                  << std::setw(10) << task.id
                  << std::setw(15) << task.arrival_time
                  << std::setw(12) << task.processing_duration
                  << std::setw(12) << task.start_time
                  << std::setw(12) << task.finish_time << "\n";
    }
    std::cout << std::string(60, '-') << "\n";
    std::cout << "All tasks finished at timestamp: " << current_clock << "\n";

    return 0;
}

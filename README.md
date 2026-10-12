# C++ Algorithms and Object-Oriented Programming (OOP) Showcase

A curated collection of fundamental algorithms, discrete event modeling, and object-oriented programming designs implemented in modern C++ (C++17/20).

Designed as an engineering portfolio highlight demonstrating algorithmic efficiency, memory management, and clean OOP architecture.

---

## 📂 Repository Structure

```
cpp-algorithms-and-oop/
├── 01-algorithms/
│   ├── trapping-rain-water/       # Dynamic programming: Prefix maximums O(N) water trapping
│   ├── event-queue-simulation/    # Discrete-event job pipeline simulation & chronological scheduling
│   └── partition-optimization/    # Combinatorial search: Backtracking vs Greedy partitioning
└── 02-oop-core/
    ├── geometry-triangle/         # OOP lifecycle: Constructors, destructor, floating-point validation
    └── rational-fraction/         # Mathematical invariant maintenance, Euclidean GCD, operator overloading
```

---

## ⚡ Highlights & Key Topics

### 1. Dynamic Programming & Two-Pointers (`01-algorithms/trapping-rain-water`)
- **Problem Formulation:** Trapping Rain Water over non-uniform elevation profiles.
- **Approach:** Computes prefix/suffix maximums in $O(N)$ time with $O(N)$ space.
- **Concepts:** Vector manipulation, algorithm optimization, edge-case handling.

### 2. Discrete Event Pipeline Simulation (`01-algorithms/event-queue-simulation`)
- **Problem Formulation:** Queue processing of asynchronous tasks with arbitrary arrival times and workloads.
- **Approach:** Chronological event dispatching, timeline progression, throughput analysis.
- **Concepts:** Custom `struct` data representations, `std::sort` comparator lambdas, simulation metrics.

### 3. NP-Hard Heuristics & Backtracking (`01-algorithms/partition-optimization`)
- **Problem Formulation:** Multi-way number partitioning to minimize subset variance.
- **Approach:** Compares global optimum search (recursive state-space exploration) against descending Greedy heuristic.

### 4. Object Lifecycle & Robust Validation (`02-oop-core/geometry-triangle`)
- **Features:** Default, parameterized, and copy constructors; RAII and destructor telemetry.
- **Robustness:** Numerical tolerance checking (`epsilon = 1e-9`) against floating-point inaccuracy.

### 5. Invariant Maintenance & Operator Overloading (`02-oop-core/rational-fraction`)
- **Features:** Invariant preservation (automatic canonical sign and irreducible form reduction).
- **Core Math:** Euclidean Greatest Common Divisor (GCD) algorithm; overloaded `+` and `*` operators.

---

## 🛠️ How to Build and Run

All modules are self-contained and standard-compliant. You can compile any module using `g++`, `clang++`, or MSVC:

```bash
# Example: Compile Trapping Rain Water
g++ -std=c++17 01-algorithms/trapping-rain-water/main.cpp -o trapping_water
./trapping_water

# Example: Compile OOP Triangle Engine
g++ -std=c++17 02-oop-core/geometry-triangle/main.cpp -o triangle_app
./triangle_app
```

---

## 👤 Author
- **GitHub:** [@mmmuravei](https://github.com/mmmuravei)
- **Specialization:** Applied Informatics in Design / Software Engineering & Systems

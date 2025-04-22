# Leetcode-2976.-Minimum-Cost-to-Convert-String-I
# 🔤 Minimum Character Transformation Cost

This repository contains an elegant C++ solution to transform a `source` string into a `target` string using a series of allowed character transformations with associated costs. The goal is to determine the **minimum total cost** to perform this transformation.

---

## 🚀 Problem Overview

You are given:
- Two strings: `source` and `target` (must be of the same length)
- A list of transformations:
  - `original[i]` → `changed[i]` with `cost[i]`

You can **chain transformations** (e.g., `a → b → c`) if intermediate transformations exist.

### ✅ Objective:
Compute the **minimum total cost** to convert each character of `source` into the corresponding character in `target`.

---

## 🧠 Approach: Floyd-Warshall Algorithm

The solution uses the **Floyd-Warshall algorithm** to compute the minimum cost to convert any character to any other character via direct or indirect transformations.

### Steps:
1. **Build a 26x26 graph** (for lowercase English letters) with transformation costs.
2. Apply **Floyd-Warshall** to compute all-pairs shortest transformation costs.
3. Iterate through `source` and `target` to calculate total cost.

If any character can't be transformed, return `-1`.

---

✨ Features
✅ Handles character chains and indirect transformations.

🔁 Uses Floyd-Warshall for global optimality.

📉 Returns -1 if transformation is not possible.

💡 Efficient and clean code with clear logic.

🔍 Related Concepts
Graph Algorithms

All-Pairs Shortest Path

Floyd-Warshall Algorithm

Dynamic Programming on Characters


---
## 📦 Input Format

```cpp
string source = "abc";
string target = "bcd";

vector<char> original = {'a', 'b', 'c'};
vector<char> changed = {'b', 'c', 'd'};
vector<int> cost = {1, 2, 3};
output- 6
Explanation:

a → b costs 1

b → c costs 2

c → d costs 3

Total cost = 1 + 2 + 3 = 6

#include <iostream>
#include <vector>
#include <algorithm>

const std::vector<int> SEQUENCE = {4, 1, 13, 7, 0, 2, 8, 11, 3};

void backtrack(const std::vector<int>& nums, std::vector<int>& path, std::vector<std::vector<int>>& results, int* maxLength, int start) {
    if (path.size() > 1 && is_sorted(path.begin(), path.end())) {
        if (path.size() == *maxLength) {
            results.push_back(path);
        } else if (path.size() > *maxLength) {
            *maxLength = path.size();
            results.clear();
            results.push_back(path);
        }
    }

    for (int i = start; i < nums.size(); ++i) {
        if (path.empty() || nums[i] >= path.back()) {
            path.push_back(nums[i]);
            backtrack(nums, path, results, maxLength, i + 1);
            path.pop_back();
        }
    }
}

std::vector<std::vector<int>> findIncreasingSubsequences(const std::vector<int>& nums) {
    std::vector<std::vector<int>> results;
    std::vector<int> path;
    int maxLengthValue = 0;
    int* maxLength = &maxLengthValue;
    backtrack(nums, path, results, maxLength, 0);

    return results;
}

int main() {
    std::vector<std::vector<int>> subsequences = findIncreasingSubsequences(SEQUENCE);

    std::cout << "Largest monotonically increasing subsequences:\n";
    for (const auto& subsequence : subsequences) {
        for (int num : subsequence) {
            std::cout << num << " ";
        }
        std::cout << "\n";
    }

    return 0;
}

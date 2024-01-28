#include <iostream>
#include <vector>
#include <unordered_set>
#include <memory>

int main() {
    auto removeDuplicates = [](const std::vector<int>& inputVector) -> std::unique_ptr<std::vector<int>> {
        std::unordered_set<int> uniqueSet;
        auto result = std::make_unique<std::vector<int>>();

        for (const auto& num : inputVector) {
            if (uniqueSet.find(num) == uniqueSet.end()) {
                result->push_back(num);
                uniqueSet.insert(num);
            }
        }

        return result;
    };

    std::vector<int> input = {1, 2, 3, 1, 2, 4, 5, 6, 3, 7, 8, 9, 1, 2, 3};

    auto uniqueNumbers = removeDuplicates(input);

    std::cout << "Unique Numbers: ";
    for (const auto& num : *uniqueNumbers) {
        std::cout << num << " ";
    }
}

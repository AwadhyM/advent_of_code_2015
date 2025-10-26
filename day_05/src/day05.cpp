#include "day05.hpp"
#include <string_view>
#include <unordered_map>

using namespace puzzle;

uint64_t part1::solve_part_1(const std::vector<std::string> &input) {
    uint32_t count = 0;
    for (const auto& line : input) {
        if (containsAtleastThreeVowels(line) && containsConsequtiveLetter(line) && doesNotContain(line)) {
            count++;
        }
    }
    return count;
};

bool part1::doesNotContain(const std::string_view line) {
    for (std::size_t i = 1; i < line.size(); ++i) {
        char a = line[i - 1], b = line[i];
        if ((a == 'a' && b == 'b') ||
            (a == 'c' && b == 'd') ||
            (a == 'p' && b == 'q') ||
            (a == 'x' && b == 'y')) {
            return false;
        }
    }
    return true;
}

bool part1::containsConsequtiveLetter(const std::string_view line) {
    std::unordered_map<char, int> mp;
    for (int i = 0; i < line.size(); i++) {
        if (mp.find(line[i]) != mp.end()) {
            if (mp[line[i]] == i - 1) {
                return true;
            }
        }
        mp[line[i]] = i;
    }
    return false;
}

bool part1::containsAtleastThreeVowels(const std::string_view line) {
    static constexpr std::string_view vowels  = "aeoui";

    auto count {0};

    for (const auto& letter : line ) {
        
        if (vowels.find(letter) != std::string_view::npos){
            count++;
        }

        if (count == 3) {
            return true;
        }
    }

    return false;
}


uint64_t part2::solve(const std::vector<std::string> &input) {
    uint32_t count = 0;
    for (const auto& line : input) {
        if (part2::repeatingPair(line) && part2::repeatingLetterWithInBetween(line)) {
            count++;
        }
    }
    return count;
    return 0;
};

bool part2::repeatingPair(const std::string_view line) {
    std::unordered_map<std::string_view, int> mp;
    for (int i = 0; i + 1 < line.size() ; i++) {
        std::string_view pair = line.substr(i, 2);
        if (mp.find(pair) != mp.end()) {
            return (i > mp[pair] + 1);
        } else {
            mp[pair] = i;
        }
    }
    return false;
}

bool part2::repeatingLetterWithInBetween(const std::string_view line) {
    for (int i = 0; i < line.size() - 2; i++) {
        if (line[i] == line[i+2]) {
            return true;
        }
    }
    return false;
}
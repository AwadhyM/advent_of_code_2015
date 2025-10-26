#include <iostream>
#include <stdint.h>
#include <string>
#include <string_view>
#include <vector>

namespace puzzle {
namespace part1 {
bool containsAtleastThreeVowels(const std::string_view);
bool containsConsequtiveLetter(const std::string_view);
bool doesNotContain(const std::string_view);
uint64_t solve_part_1(const std::vector<std::string> &input);
} // namespace part1

namespace part2 {
uint64_t solve(const std::vector<std::string> &input);
bool repeatingPair(const std::string_view line);
bool repeatingLetterWithInBetween(const std::string_view line);
}

} // namespace puzzle
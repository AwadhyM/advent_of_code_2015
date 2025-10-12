#include <iostream>
#include <string>
#include <string_view>
#include <vector>

constexpr int count_step(const char paren);
int count_steps(std::string_view line);
int solve_part_1(std::vector<std::string> input);
int solve_part_2(const std::vector<std::string> input);

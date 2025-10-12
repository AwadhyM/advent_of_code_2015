#include "day01.hpp"
#include <filesystem>
#include <fstream>
#include <numeric>
#include <stdexcept>
#include <string_view>

std::vector<std::string> read_input(const std::string &path) {
  if (!std::filesystem::exists(path))
    throw std::runtime_error("File not found: " + path);

  std::ifstream file(path);
  if (!file.is_open())
    throw std::runtime_error("Failed to open file: " + path);
  std::vector<std::string> lines;
  std::string line;
  while (std::getline(file, line)) {
    lines.push_back(line);
  }
  return lines;
}

constexpr int count_step(const char paren) {
  if (paren == '(') {
    return 1;
  } else if (paren == ')') {
    return -1;
  } else {
    throw std::runtime_error("Unexpected char within input file");
  }
}

int count_steps(std::string_view line) {
  return std::accumulate(
      line.begin(), line.end(), 0,
      [](int floor, char paren) { return floor + count_step(paren); });
}

int solve_part_1(std::vector<std::string> input) {
  int floor = 0;
  for (const auto &line : input) {
    floor += count_steps(line);
  }
  return floor;
}

int solve_part_2(const std::vector<std::string> input) {
  int floor = 0;

  for (const auto &line : input) {
    for (int steps = 0; char paren : line) {
      floor += count_step(paren);
      steps++;
      if (floor == -1) {
        return steps;
      }
    }
  }

  return 0;
}

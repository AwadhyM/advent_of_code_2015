#include "day02.hpp"
#include <algorithm>
#include <array>
#include <iostream>
#include <string>
#include <vector>

using namespace puzzle;

uint64_t part1::solve_part_1(const std::vector<std::string> &input) {
  uint64_t total = 0;
  for (const auto &line : input) {
    const auto dims = get_dimensions(line);
    auto present = box(dims);
    total += present.get_surface_area() + present.get_smallest_side();
  }
  return total;
};

uint64_t part2::solve_part_2(const std::vector<std::string> &input) {
  uint64_t total = 0;
  for (const auto &line : input) {
    const auto dims = get_dimensions(line);
    auto present = box(dims);
    total += present.get_ribbon_length();
  }
  return total;
};

Dimensions puzzle::get_dimensions(const std::string &expr) {
  std::vector<int> dims;
  size_t begin = 0;
  size_t end = expr.find('x');

  while (end != std::string::npos) {
    dims.push_back(std::stoi(expr.substr(begin, end - begin)));
    begin = end + 1;
    end = expr.find('x', begin);
  }
  dims.push_back(std::stoi(expr.substr(begin)));
  Dimensions dimensions(dims[0], dims[1], dims[2]);
  return dimensions;
}

void box::calculate_surface_area() {
  m_surface_area = (2 * m_dimensions.length * m_dimensions.width) +
                   (2 * m_dimensions.width * m_dimensions.height) +
                   (2 * m_dimensions.height * m_dimensions.length);
}
void box::calculate_area_smallest_side() {
  int smallest = std::min(m_dimensions.length * m_dimensions.height,
                          m_dimensions.width * m_dimensions.height);
  smallest = std::min(smallest, m_dimensions.width * m_dimensions.length);
  smallest_side = smallest;
}
void box::calculate_ribbon_length() {
  std::array dims = {m_dimensions.length, m_dimensions.width,
                     m_dimensions.height};
  std::sort(dims.begin(), dims.end());
  m_ribbon_length = (2 * (dims[0] + dims[1])) + get_area();
}
void box::calculate_area() {
  m_area = m_dimensions.length * m_dimensions.height * m_dimensions.width;
}

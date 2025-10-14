#include "day02.hpp"
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace puzzle;

uint64_t part1::solve_part_1(std::vector<std::string> input) {
  uint64_t total = 0;
  for (int i = 0; i < input.size(); i++) {
    const auto dims = get_dimensions(input[i]);
    auto present = box(dims[0], dims[1], dims[2]);
    total += present.get_m_surface_area() + present.get_smallest_side();
  }
  return total;
};
std::vector<int> part1::get_dimensions(const std::string &expr) {
  std::vector<int> dims;
  size_t begin = 0;
  size_t end = expr.find('x');

  while (end != std::string::npos) {
    dims.push_back(std::stoi(expr.substr(begin, end - begin)));
    begin = end + 1;
    end = expr.find('x', begin);
  }

  dims.push_back(std::stoi(expr.substr(begin)));
  return dims;
}

void box::calculate_surface_area() {
  // Error checking needed. I.e check that values are noi 0. Or do this in the
  // constructor...
  m_surface_area = (2 * m_length * m_width) + (2 * m_width * m_height) +
                   (2 * m_height * m_length);
}
void box::calculate_area_smallest_side() {
  int smallest = std::min(m_length * m_height, m_width * m_height);
  smallest = std::min(smallest, m_width * m_length);
  smallest_side = smallest;
}

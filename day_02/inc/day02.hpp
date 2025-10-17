#include <stdint.h>
#include <string>
#include <vector>

namespace puzzle {

struct Dimensions {
  Dimensions(int length, int width, int height)
      : length(length), width(width), height(height) {}

  int length{0};
  int width{0};
  int height{0};
};

class box {
public:
  box(Dimensions dimensions) : m_dimensions(dimensions) {
    calculate_surface_area();
    calculate_area_smallest_side();
    calculate_area();
    calculate_ribbon_length();
  }

  int get_surface_area() const { return m_surface_area; }
  int get_area() const { return m_area; }
  int get_smallest_side() const { return smallest_side; }
  int get_ribbon_length() const { return m_ribbon_length; }

private:
  Dimensions m_dimensions;
  int m_area{0};
  int m_surface_area{0};
  int smallest_side{0};
  int m_ribbon_length{0};

  void calculate_surface_area();
  void calculate_area_smallest_side();
  void calculate_ribbon_length();
  void calculate_area();
};

Dimensions get_dimensions(const std::string &expr);
namespace part1 {
uint64_t solve_part_1(const std::vector<std::string> &input);
} // namespace part1

namespace part2 {
uint64_t solve_part_2(const std::vector<std::string> &input);
}

} // namespace puzzle

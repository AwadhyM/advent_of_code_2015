#include <stdint.h>
#include <string>
#include <vector>

namespace puzzle {

class box {
public:
  box(int length, int width, int height)
      : m_length(length), m_width(width), m_height(height) {
    calculate_surface_area();
    calculate_area_smallest_side();
  }

  int get_m_surface_area() const { return m_surface_area; }
  int get_smallest_side() const { return smallest_side; }

private:
  int m_length{0};
  int m_width{0};
  int m_height{0};
  int m_surface_area{0};
  int smallest_side{0};

  void calculate_surface_area();
  void calculate_area_smallest_side();
};

namespace part1 {
uint64_t solve_part_1(std::vector<std::string> input);
std::vector<int> get_dimensions(const std::string &expr);
} // namespace part1

} // namespace puzzle

/*
 * How to solve this puzzle!
 * Lets have a struct called box. Box has: length, height, width.
 * Box also have a function to calculate the surface area.
 * Also a function to calculate the area of the smallest side
 * */

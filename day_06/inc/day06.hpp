#include <stdint.h>
#include <string>
#include <string_view>
#include <vector>

namespace puzzle {
enum class action { TURN_ON, TURN_OFF, TOGGLE, ERROR };
action parseAction(std::string_view instruction);

struct coordinates {
  uint32_t rowStart;
  uint32_t rowEnd;
  uint32_t colStart;
  uint32_t colEnd;
};

coordinates parseCoordinates(std::string instruction);

namespace part1 {
using lights = std::array<std::array<bool, 1000>, 1000>;
uint64_t solve_part_1(const std::vector<std::string> &input);
int64_t modifyLights(action command, coordinates coord, lights &grid);
} // namespace part1

namespace part2 {
using lights = std::array<std::array<uint64_t, 1000>, 1000>;
uint64_t solve(const std::vector<std::string> &input);
int64_t modifyBrightness(action command, coordinates coord, lights &grid);
} // namespace part2

} // namespace puzzle

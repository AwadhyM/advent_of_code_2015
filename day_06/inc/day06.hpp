#include <stdint.h>
#include <string>
#include <string_view>
#include <vector>


namespace puzzle {
enum class action {TURN_ON, TURN_OFF, TOGGLE, ERROR};
action parseAction(std::string_view instruction);
void removeActionFromString(action command, std::string &instruction);
std::pair<uint16_t, uint16_t> getCoordinates(std::string instruction);

namespace part1 {
using lights = std::array<std::array<bool, 1000>, 1000>;
uint64_t solve_part_1(const std::vector<std::string> &input);
int64_t modifyLights(action command, std::pair<uint16_t, uint16_t> start, std::pair<uint16_t, uint16_t> end, lights &grid);
} // namespace part1

namespace part2 {
using lights = std::array<std::array<uint64_t, 1000>, 1000>;
uint64_t solve(const std::vector<std::string> &input);
int64_t modifyBrightness(action command, std::pair<uint16_t, uint16_t> start, std::pair<uint16_t, uint16_t> end, lights &grid);
}

} // namespace puzzle

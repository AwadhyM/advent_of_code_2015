#include "day06.hpp"
#include <array>
#include <iostream>
#include <sstream>
#include <string>
#include <string_view>

using namespace puzzle;

coordinates puzzle::parseCoordinates(std::string instruction) {
  instruction = instruction.substr(instruction.find_first_of("0123456789"));
  std::stringstream s(instruction);
  uint32_t rowStart, rowEnd, colStart, colEnd;
  char comma;
  std::string through;
  s >> colStart >> comma >> rowStart >> through >> colEnd >> comma >> rowEnd;
  return {rowStart, rowEnd, colStart, colEnd};
}

uint64_t part1::solve_part_1(const std::vector<std::string> &input) {
  // Iterate through each element of the vector (element is a line)
  part1::lights grid{};
  uint64_t count = 0;
  for (auto line : input) {
    const auto command = parseAction(line);
    const auto coordinates = parseCoordinates(line);
    count += modifyLights(command, coordinates, grid);
  }
  return count;
}

uint64_t part2::solve(const std::vector<std::string> &input) {
  lights grid{0};
  uint64_t brightness = 0;
  for (auto line : input) {
    const auto command = parseAction(line);
    const auto coordinates = parseCoordinates(line);
    brightness += modifyBrightness(command, coordinates, grid);
  }
  return brightness;
};

int64_t part2::modifyBrightness(action command, coordinates coord,
                                lights &grid) {
  int64_t change = 0;
  for (uint32_t row = coord.rowStart; row <= coord.rowEnd; row++) {
    for (uint32_t col = coord.colStart; col <= coord.colEnd; col++) {
      if (command == action::TOGGLE) {
        grid[row][col] += 2;
        change += 2;
      } else if (command == action::TURN_OFF) {
        if (grid[row][col] > 0) {
          grid[row][col] -= 1;
          change -= 1;
        }
      } else {
        grid[row][col] += 1;
        change += 1;
      }
    }
  }
  return change;
}

int64_t part1::modifyLights(action command, coordinates coord, lights &grid) {
  int64_t change = 0;
  for (uint32_t row = coord.rowStart; row <= coord.rowEnd; row++) {
    for (uint32_t col = coord.colStart; col <= coord.colEnd; col++) {
      const bool originalState = grid[row][col];
      if (command == action::TOGGLE) {
        grid[row][col] = !grid[row][col];
      } else if (command == action::TURN_OFF) {
        grid[row][col] = false;
      } else {
        grid[row][col] = true;
      }

      if (originalState == false && grid[row][col] == true) {
        change += 1;
      }

      if (originalState == true && grid[row][col] == false) {
        change -= 1;
      }
    }
  }
  return change;
}

action puzzle::parseAction(std::string_view instruction) {
  if (instruction.find("toggle") != std::string::npos) {
    return action::TOGGLE;
  }

  if (instruction.find("turn on") != std::string::npos) {
    return action::TURN_ON;
  }

  if (instruction.find("turn off") != std::string::npos) {
    return action::TURN_OFF;
  }

  return action::ERROR;
}

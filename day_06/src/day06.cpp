#include "day06.hpp"
#include <array>
#include <string>
#include <string_view>


using namespace puzzle;
void puzzle::removeActionFromString(action command, std::string &instruction) {
        if (command == action::TURN_OFF || command == action::TURN_ON)  {
            const auto whitespace = instruction.find(" ");
            instruction = instruction.substr(whitespace + 1);
        }
        instruction = instruction.substr(instruction.find(" ") + 1);
}

uint64_t part1::solve_part_1(const std::vector<std::string> &input) {
    // Iterate through each element of the vector (element is a line)
    part1::lights grid{};
    uint64_t count = 0;
    for (auto& line : input) {
        //Have a function that takes in the line and returns the command
        const auto command = parseAction(line);

        // Have a function that takes in the line and returns a pair of coordinates
        std::string instruction = line;
        removeActionFromString(command, instruction);
        const auto whitespace = instruction.find(" ");
        std::pair<uint16_t, uint16_t> start = getCoordinates(instruction.substr(0, whitespace));
        // Remove the first pair of coordinates from the string
        instruction = instruction.substr(instruction.find(" ")+1);
        // Get to the second pair of coordinates from the string
        instruction = instruction.substr(instruction.find(" "));
        // Get the coordinates
        std::pair<uint16_t, uint16_t> end = getCoordinates(instruction);
        count += modifyLights(command, start, end, grid);
   }
   return count;
}

uint64_t part2::solve(const std::vector<std::string> &input) {
    lights grid{0};
    uint64_t brightness = 0;
    for (auto& line : input) {
        //Have a function that takes in the line and returns the command
        const auto command = parseAction(line);

        // Have a function that takes in the line and returns a pair of coordinates
        std::string instruction = line;
        removeActionFromString(command, instruction);
        const auto whitespace = instruction.find(" ");
        std::pair<uint16_t, uint16_t> start = getCoordinates(instruction.substr(0, whitespace));
        // Remove the first pair of coordinates from the string
        instruction = instruction.substr(instruction.find(" ")+1);
        // Get to the second pair of coordinates from the string
        instruction = instruction.substr(instruction.find(" "));
        // Get the coordinates
        std::pair<uint16_t, uint16_t> end = getCoordinates(instruction);
       brightness += modifyBrightness(command, start, end, grid);
    }
    return brightness;
};

int64_t part2::modifyBrightness(action command, std::pair<uint16_t, uint16_t> start, std::pair<uint16_t, uint16_t> end, lights &grid) {
    int64_t change = 0;
    for (uint16_t row = start.first; row <= end.first; row++) {
        for (uint16_t col = start.second; col <= end.second; col++) {
            if (command == action::TOGGLE) {
                grid[row][col]+= 2;
                change += 2;
            } else if (command == action::TURN_OFF) {
                if(grid[row][col] > 0) {
                    grid[row][col]-= 1;
                    change -= 1;
                }
            } else {
                grid[row][col]+= 1;
                change += 1;
            }
        }
    }
    return change;
}

int64_t part1::modifyLights(action command, std::pair<uint16_t, uint16_t> start, std::pair<uint16_t, uint16_t> end, lights &grid) {
    int64_t change = 0;
    for (uint16_t row = start.first; row <= end.first; row++) {
        for (uint16_t col = start.second; col <= end.second; col++) {
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

std::pair<uint16_t, uint16_t> puzzle::getCoordinates(std::string instruction) {
    const auto delimiterIndex = instruction.find(",");
    const auto xCoordinate = instruction.substr(0, delimiterIndex );
    const auto yCoordinate = instruction.substr(delimiterIndex + 1);
    return {std::stoi(xCoordinate), std::stoi(yCoordinate)};
}

action puzzle::parseAction(std::string_view instruction) {
    if (instruction.find("toggle")!= std::string::npos) {
        return action::TOGGLE;
    }

    if (instruction.find("turn on") != std::string::npos) {
        return action::TURN_ON;
    }

    if (instruction.find("turn off")!= std::string::npos) {
        return action::TURN_OFF;
    }

    return action::ERROR;
}

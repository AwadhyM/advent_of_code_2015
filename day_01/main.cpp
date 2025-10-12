#include "day01.hpp"
#include <exception>
#include <stdexcept>

int main(int argc, char *argv[]) {

  if (argc < 2) {
    throw std::runtime_error("Programme requires passing of an argument");
  }

  const auto input = read_input(argv[1]);
  if (input.empty()) {
    throw std::runtime_error("Input file is empty");
  }

  std::vector<std::string> file_contents = input;

  std::cout << "Solution to part 1 is: " << solve_part_1(file_contents)
            << std::endl;
  std::cout << "Solution to part 2 is: " << solve_part_2(file_contents)
            << std::endl;
  return 0;
}

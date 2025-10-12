#include "utils.hpp"
#include <filesystem>
#include <fstream>
#include <stdexcept>

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

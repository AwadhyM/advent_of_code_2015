#include <string>
#include <vector>

/**
 * @brief Reads the contents of a file into a vector of strings.
 *
 * Each element of the returned vector corresponds to one line of the file.
 *
 * @param path The path to the input file.
 * @return std::vector<std::string> A vector containing the lines of the file.
 *
 * @throws std::runtime_error if the file does not exist or cannot be opened.
 */
std::vector<std::string> read_input(const std::string &path);

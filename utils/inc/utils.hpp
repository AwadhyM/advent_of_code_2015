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

/**
 * @brief Converts a digit character to its integer value.
 *
 * This function takes a single character representing a decimal digit ('0' to
 * '9') and returns its corresponding integer value. If the input character is
 * not a decimal digit, the function throws a std::invalid_argument exception.
 *
 * @param num The character to convert. Must be '0'..'9'.
 * @return int The integer value of the digit (0..9).
 * @throws std::invalid_argument if the character is not a digit.
 */
int to_num(char num);
